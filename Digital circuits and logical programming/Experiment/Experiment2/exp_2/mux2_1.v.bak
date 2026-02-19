module mux2_1 (
    input [7:0] a,
    input [7:0] b,
    input s,
    output [7:0] y
);

    // 使用三目运算符，s为1选b，否则选a
    assign y = (s == 1'b1) ? b : a;

endmodule