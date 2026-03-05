module buffer_reg(
    input clk,
    input load,        
    input [7:0] d,     
    output reg [7:0] q 
);
    initial q = 8'h00;

    always @(posedge clk) begin
        if (load) q <= d;
    end
endmodule