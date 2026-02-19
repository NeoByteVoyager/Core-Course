module reg_group (
    input wire clk,
    input wire we,
    input wire [1:0] sr,
    input wire [1:0] dr,
    input wire [7:0] i,
    output wire [7:0] s,
    output wire [7:0] d
);

    // 4个8位寄存器
    reg [7:0] R0, R1, R2, R3;
    initial begin
        R0 = 8'h01;
        R1 = 8'b0000_0000;
        R2 = 8'b0000_0000;
        R3 = 8'h07;
    end
    
    // 写操作：时钟下降沿触发
    always @(negedge clk) begin
        if (we) begin
            case (dr)
                2'b00: R0 <= i;
                2'b01: R1 <= i;
                2'b10: R2 <= i;
                2'b11: R3 <= i;
            endcase
        end
    end
    
    // 读操作：组合逻辑
    assign s = (sr == 2'b00) ? R0 :
               (sr == 2'b01) ? R1 :
               (sr == 2'b10) ? R2 :
               (sr == 2'b11) ? R3 : 8'b0;
    
    assign d = (dr == 2'b00) ? R0 :
               (dr == 2'b01) ? R1 :
               (dr == 2'b10) ? R2 :
               (dr == 2'b11) ? R3 : 8'b0;

endmodule