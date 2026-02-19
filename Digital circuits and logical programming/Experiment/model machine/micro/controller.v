module controller(
    input clk,
    input [7:0] ir,
    input gf,
    input sm,

	output ld_pc,           
    output in_pc,           
    output [1:0] s,         
    output ram_we,          
    output ram_re,          
    output ld_ir,           
    output reg_we,          
    output au_en,           
    output [3:0] ac,        
    output g_en,            
    output in_en,           
    output out_en,          
    output s0,              
    output sm_en,           
    output [1:0] SR,        
    output [1:0] DR 
    
 
);



    wire [4:0] uaddr;

    assign uaddr = {sm, ir[7:4]};

    wire [19:0] u;

    lpm_rom urom (
        .address (uaddr),
        .q       (u),
        .memenab (1'b1)
    );

    defparam urom.lpm_width = 20;
    defparam urom.lpm_widthad = 5; 
    defparam urom.lpm_file = "microcode.mif";
    defparam urom.lpm_address_control = "UNREGISTERED";
    defparam urom.lpm_outdata = "UNREGISTERED";

    wire [1:0] jump;

     
    assign sm_en  = u[19];
    assign in_pc  = u[17];
    assign ld_ir  = u[16];
    assign ram_we = u[15];
    assign ram_re = u[14];
    assign reg_we = u[13];
    assign s0     = u[12];
    assign au_en  = u[11];
    assign g_en   = u[10];
    assign in_en  = u[9];
    assign out_en = u[8];
    assign s      = u[7:6];
    assign ac     = u[5:2];
    

    assign jump = u[1:0];

    //
    assign ld_pc = (jump == 2'b01) | ((jump == 2'b10) & gf);

    assign SR = ir[1:0];
    assign DR = ir[3:2];

endmodule