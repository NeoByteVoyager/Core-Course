module sm (
    input wire clk,
    input wire sm_en,
    output reg sm
);
    initial sm = 1'b0;
    
    always @(negedge clk) begin
        if (sm_en)
            sm <= ~sm;
    end
endmodule