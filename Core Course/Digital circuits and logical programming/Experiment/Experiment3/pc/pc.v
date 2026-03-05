module pc(
    input        clk,    // 时钟
    input        ld_pc,  // 装载控制
    input        in_pc,  // 自增控制
    input  [7:0] a,      // 8 位输入（跳转地址）
    output reg [7:0] c   // 8 位输出（当前 PC）
);

    initial c = 8'b00000000;   // 初始取值为 0（第一条指令地址）

    always @(negedge clk) begin
        if (ld_pc)
            c <= a;              // 装载跳转地址
        else if (in_pc)
            c <= c + 8'b00000001; // 顺序执行，自加 1
        // 否则保持不变
    end

endmodule