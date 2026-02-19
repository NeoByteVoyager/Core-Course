// PSW：1 位状态寄存器（这里只保存标志位 G）
module psw(
    input  clk,     // 时钟信号
    input  g_en,    // 使能信号
    input  g,       // 1 位输入
    output reg gf   /* synthesis preserve */
);

    // 初始值 0
    initial gf = 1'b0;

    // 在 clk 下降沿，g_en = 1 时，把 g 装入 gf
    always @(negedge clk) begin
        if (g_en)
            gf <= g;
    end

endmodule