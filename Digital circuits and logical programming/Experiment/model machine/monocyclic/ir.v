// IR：8 位指令寄存器
module ir(
    input        clk,    // 时钟信号
    input        ld_ir,  // 装载使能信号
    input  [7:0] a,      // 8 位输入
    output reg [7:0] x   // 8 位输出
);

    // 初始值 00000000
    initial x = 8'b00000000;

    // 在 clk 下降沿，ld_ir = 1 时，把总线 a 装入寄存器
    always @(negedge clk) begin
        if (ld_ir)
            x <= a;
    end

endmodule