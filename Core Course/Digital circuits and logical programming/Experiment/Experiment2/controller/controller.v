module controller(
    input sm,               
    input mova, movb, movc, movd, add, sub, jmp, jg, in1, out1, movi, halt, 
    input [7:0] ir,     
    input gf,               
    output reg ld_pc,           
    output reg in_pc,           
    output reg [1:0] s,         
    output reg ram_we,          
    output reg ram_re,          
    output reg ld_ir,           
    output reg reg_we,          
    output reg au_en,           
    output reg [3:0] ac,        
    output reg g_en,            
    output reg in_en,           
    output reg out_en,          
    output reg s0,              
    output reg sm_en,           
    output reg [1:0] SR,        
    output reg [1:0] DR         
);
always @(*) begin
    
    
    in_pc = movi | (~sm);    
    ld_pc = jmp | (jg & gf);  
    
    s = movb ? 2'b10 : (movc ? 2'b01 : 2'b00);
    
    ram_re = (~sm) | movc | movi; 
    ram_we = movb; 
    
    ld_ir = ~sm;   
    
    sm_en = ~halt; 
    
    s0 = mova | movi | add | sub | in1 | movc; 
    
    reg_we = movi | mova | movc | movd | sub | add | in1; 
    
    
    
    DR = ir[3:2];               
    SR = ir[1:0];    
                
    au_en = mova | movb | add | out1 | sub; 
                 
                              
    g_en = sub;                 
           
    
    in_en = in1;                
    out_en = out1;               
    ac = ir[7:4];             
   
end

endmodule