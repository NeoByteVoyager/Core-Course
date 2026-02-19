module seg_display_signed(
    input        clk,          // 全局时钟
    input  [7:0] IR,           // 指令寄存器
    input        gf,           // PSW 条件标志
    output reg [1:0] state,    // 状态输出

    output ld_pc, in_pc,
    output [1:0] s,
    output ram_re, ram_we,
    output ld_mar, ld_dr, ld_ir,
    output reg_we, s0,
    output [1:0] SR, DR,
    output au_en,
    output [3:0] ac,
    output g_en, in_en, out_en, sm_en
);

    /* 1. FSM 状态定义 */
    localparam FETCH  = 2'b00;
    localparam DECODE = 2'b01;
    localparam EXEC   = 2'b10;

    /* 2. 指令解析 */
    wire [3:0] op   = IR[7:4];
    wire [1:0] Rd_f = IR[3:2];
    wire [1:0] Rs_f = IR[1:0];

    /* 3. 指令分类 */
    wire is_jmp  = (op == 4'b1010);
    wire is_jg   = (op == 4'b1011);
    wire is_jump = is_jmp | is_jg;
    wire is_add  = (op == 4'b1000);
    wire is_sub  = (op == 4'b1001);
    wire is_mov  = (op == 4'b0100);  // MOVA
    wire is_movi = (op == 4'b1110);
    wire is_movd = (op == 4'b0111);
    wire is_ld   = (op == 4'b0110);  // MOVC
    wire is_st   = (op == 4'b0101);  // MOVB
    wire is_in   = (op == 4'b1100);
    wire is_out  = (op == 4'b1101);
    wire is_halt = (op == 4'b1111);

    /* 4. FSM 状态转移 (下降沿) */
    initial state = FETCH;
    always @(negedge clk) begin
        if (is_halt && state == EXEC)
            state <= EXEC;   
        else begin
            case (state)
                FETCH:  state <= is_jump ? DECODE : EXEC;
                DECODE: state <= EXEC;
                EXEC:   state <= FETCH;
                default: state <= FETCH;
            endcase
        end
    end

    wire is_fetch  = (state == FETCH);
    wire is_decode = (state == DECODE);
    wire is_exec   = (state == EXEC);

    /* 5. 核心控制逻辑 */
    assign in_pc = is_fetch || (is_exec && is_movi);
    assign ld_pc = is_exec && ( is_jmp || (is_jg && gf) );

    // MAR/DR 控制 (修正: ld_dr 在执行期也必须有效以捕获操作数)
    assign ld_mar = is_fetch;               
    assign ld_dr  = is_decode || is_exec;  

    // 寄存器寻址
    assign SR = (is_decode || (is_exec && is_jump)) ? 2'b11 : Rs_f;
    assign DR = is_movi ? 2'b00 : (is_movd ? 2'b11 : Rd_f);

    // RAM 控制 (s=00 对应 PC, 01 对应 S口, 10 对应 D口)
    assign s = is_fetch ? 2'b00 : is_ld ? 2'b01 : is_st ? 2'b10 : 2'b00;
    assign ram_re = is_fetch || (is_exec && (is_movi || is_ld));
    assign ram_we = is_exec && is_st;

    // 写回控制
    assign reg_we = is_exec && !(is_jump || is_halt || is_st || is_out);
    assign s0 = (is_exec && is_movd) ? 1'b0 : 1'b1;

    // AU 控制 (修正: 增加 is_out 以便 Rs 能上总线)
    assign au_en = is_exec && (is_add || is_sub || is_mov || is_st || is_out);
    assign ac = is_add ? 4'b1000 : is_sub ? 4'b1001 : 4'b0100;

    /* 6. 其他 */
    assign ld_ir  = is_fetch;
    assign g_en   = is_exec && is_sub;
    assign in_en  = is_exec && is_in;
    assign out_en = is_exec && is_out;
    assign sm_en  = ~is_halt;

endmodule