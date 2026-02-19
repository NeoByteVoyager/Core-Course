module controller(
    input sm,               // 状态信号：0为取指，1为执行
    input mova, movb, movc, movd, add, sub, jmp, jg, in1, out1, movi, halt, // 译码器输出
    input gf,               // 状态寄存器标志位 G
    output ld_pc,           // 加载PC
    output in_pc,           // PC自增
    output s1, s2,          // RAM地址选择
    output ram_we,          // RAM写使能 (WR)
    output ram_re,          // RAM读使能 (RE)
    output ld_ir,           // 指令寄存器装载
    output reg_we,          // 通用寄存器组写使能
    output au_en,           // 运算单元输出使能
    output [3:0] ac,        // 运算单元功能控制
    output g_en,            // 状态寄存器写使能
    output in_en,           // 输入设备使能
    output out_en,          // 输出设备使能
    output s0,              // 寄存器组输入数据源选择 (0:PC, 1:总线)
    output sm_en            // 状态机翻转使能
);

    // 1. PC 控制逻辑
    // 跳转逻辑：执行阶段(sm=1) 且 (无条件跳转 或 有条件跳转且G=1)
    assign ld_pc = sm & (jmp | (jg & gf));
    // 自增逻辑：取指阶段(sm=0)
    assign in_pc = ~sm;

    // 2. RAM 地址选择逻辑 (s2, s1)
    // 00: PC(取指), 01: S口(movc), 10: D口(movb)
    assign s1 = sm & movc;
    assign s2 = sm & movb;

    // 3. RAM 读写逻辑
    assign ram_we = sm & movb;         // 执行movb时写入RAM
    assign ram_re = (~sm) | (sm & movc); // 取指期 或 执行movc时读取

    // 4. IR 装载逻辑
    assign ld_ir = ~sm;                // 仅在取指期装载

    // 5. 通用寄存器组写回逻辑 (reg_we)
    // 凡是修改目的寄存器的指令都需要写使能
    assign reg_we = sm & (mova | movc | movd | add | sub | in1 | movi);

    // 6. 运算单元控制 (AU)
    // AU需要输出到总线的指令
    assign au_en = sm & (mova | add | sub | out1);
    // AU功能码映射
    assign ac = add ? 4'b1000 : 
               (sub ? 4'b1001 : 
               (mova ? 4'b0100 : 4'b0000));

    // 7. 状态位更新 (G_EN)
    assign g_en = sm & sub;            // 仅减法指令更新G标志

    // 8. 输入/输出设备使能
    assign in_en = sm & in1;
    assign out_en = sm & out1;

    // 9. 寄存器组数据来源选择 (s0)
    // 0: 来自PC (movd), 1: 来自总线 (其他指令)
    assign s0 = ~(sm & movd);

    // 10. 停机控制
    assign sm_en = ~halt;              // halt有效时禁止SM翻转，系统停止

endmodule