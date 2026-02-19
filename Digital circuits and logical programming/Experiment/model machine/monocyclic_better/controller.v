module controller(
input sm,               // 状态信号
    input [7:0] ir,         // 【关键修改】直接输入 8位 IR，无需外部拆分
    input gf,              // 标志位 G
    
  output ld_pc,           
    output in_pc,           
    output [1:0] s,         // RAM地址选择
    output ram_we,          
    output ram_re,          
    output ld_ir,           
    output reg_we,          
    output au_en,           
    output [3:0] ac,        
    output g_en,            
    output in_en,           
    output out_en,          
    output s0,              // 寄存器写来源选择
    output sm_en,           
    output [1:0] SR,        
    output [1:0] DR   
);

  
    // 1. 拆分指令 (零延迟)
    wire [3:0] opcode = ir[7:4];
    wire [1:0] Rd_raw = ir[3:2];
    wire [1:0] Rs_raw = ir[1:0];

    // 2. 指令译码 (并行比较器)
    localparam MOVA = 4'b0100;
    localparam MOVB = 4'b0101;
    localparam MOVC = 4'b0110;
    localparam MOVD = 4'b0111;
    localparam ADD  = 4'b1000;
    localparam SUB  = 4'b1001;
    localparam JMP  = 4'b1010;
    localparam JG   = 4'b1011;
    localparam IN1  = 4'b1100;
    localparam OUT1 = 4'b1101;
    localparam MOVI = 4'b1110;
    localparam HALT = 4'b1111;

    wire is_mova = (opcode == MOVA);
    wire is_movb = (opcode == MOVB);
    wire is_movc = (opcode == MOVC);
    wire is_movd = (opcode == MOVD);
    wire is_add  = (opcode == ADD);
    wire is_sub  = (opcode == SUB);
    wire is_jmp  = (opcode == JMP);
    wire is_jg   = (opcode == JG);
    wire is_in   = (opcode == IN1);
    wire is_out  = (opcode == OUT1);
    wire is_movi = (opcode == MOVI);
    wire is_halt = (opcode == HALT);

    // 3. 极速控制逻辑生成

    // --- PC 控制 ---
    assign ld_pc = sm & (is_jmp | (is_jg & gf));
    assign in_pc = (~sm) | (sm & is_movi);

    // --- RAM 地址选择 (并行化优化) ---
    // 00: Fetch/MOVI, 01: MOVC, 10: MOVB
    assign s[0] = sm & is_movc;
    assign s[1] = sm & is_movb;

    // --- RAM 读写 ---
    assign ram_re = (~sm) | (sm & (is_movc | is_movi));
    assign ram_we = sm & is_movb;

    // --- 寄存器控制 ---
    assign s0 = ~(sm & is_movd); // 只有 MOVD 时为 0，其他为 1

    assign reg_we = sm & (is_mova | is_movc | is_movd | is_add | is_sub | is_in | is_movi);

    // 寻址逻辑优化
    assign SR = (is_jmp | is_jg | is_movd) ? 2'b11 : Rs_raw;
    
    // 这里的嵌套 MUX 综合器通常处理得很好
    assign DR = is_movi ? 2'b00 : (is_movd ? 2'b11 : Rd_raw);

    // --- AU 控制 ---
    assign au_en = sm & (is_mova | is_add | is_sub | is_out | is_movb);
    
    // ac 保持逻辑直观即可
    assign ac = (is_add) ? 4'b1000 : 
                (is_sub) ? 4'b1001 : 
                (is_mova | is_out | is_movb) ? 4'b0100 : 4'b0000;

    // --- 其他 ---
    assign sm_en  = ~(sm & is_halt);
    assign ld_ir  = ~sm;
    assign g_en   = sm & is_sub;
    assign in_en  = sm & is_in;
    assign out_en = sm & is_out;

endmodule