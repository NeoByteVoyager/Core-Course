module ins_decode(
    input en,
    input [3:0] ir,
    output reg mova,
    output reg movb,
    output reg movc,
    output reg movd,
    output reg add,
    output reg sub,
    output reg jmp,
    output reg jg,
    output reg in1,
    output reg out1,
    output reg movi,
    output reg halt
);

always @(*) begin
    // 默认所有输出为0
    mova = 0; movb = 0; movc = 0; movd = 0;
    add = 0; sub = 0; jmp = 0; jg = 0;
    in1 = 0; out1 = 0; movi = 0; halt = 0;
    
    if(en) begin
        case(ir)
            4'b0100: mova = 1;  // MOVA
            4'b0101: movb = 1;  // MOVB
            4'b0110: movc = 1;  // MOVC
            4'b0111: movd = 1;  // MOVD
            4'b1000: add = 1;   // ADD
            4'b1001: sub = 1;   // SUB
            4'b1010: jmp = 1;   // JMP
            4'b1011: jg = 1;    // JG
            4'b1100: in1 = 1;   // IN
            4'b1101: out1 = 1;  // OUT
            4'b1110: movi = 1;  // MOVI
            4'b1111: halt = 1;  // HALT
            default: ;  // 其他组合保持全0
        endcase
    end
end

endmodule