module mux2_1 (
    input  [7:0] a,
    input  [7:0] b,
    input        s,
    output reg [7:0] y
);

    always @(*) begin
        case (s)
            1'b0: y = a;
            1'b1: y = b;
            default: y = a; // ·ÀÖ¹×ÛºÏ²úÉúËø´æ
        endcase
    end

endmodule
