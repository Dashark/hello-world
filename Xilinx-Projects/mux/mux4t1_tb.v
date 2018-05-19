// Verilog test fixture created from schematic D:\Documents\GitHub\First\Xilinx-Projects\mux\mux4t1.sch - Fri May 18 16:56:50 2018

`timescale 1ns / 1ps

module mux4t1_mux4t1_sch_tb();

// Inputs
   reg [3:0] a;
   reg sel;
   reg [3:0] b;

// Output
   wire [3:0] o;

// Bidirs

// Instantiate the UUT
   mux4t1 UUT (
		.a(a), 
		.sel(sel), 
		.b(b), 
		.o(o)
   );
// Initialize Inputs

initial begin 
a = 0; 
b = 0; 
sel = 0; 
#100; 
a = 4'b1010; 
b = 4'b0001; 
sel = 0; 
#100; 
sel = 1; 
end

endmodule
