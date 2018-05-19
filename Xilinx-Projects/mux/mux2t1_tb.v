// Verilog test fixture created from schematic D:\Documents\GitHub\First\Xilinx-Projects\mux\mux2t1.sch - Fri May 18 16:34:05 2018

`timescale 1ns / 1ps

module mux2t1_mux2t1_sch_tb();

// Inputs
   reg a;
   reg sel;
   reg b;

// Output
   wire o;

// Bidirs

// Instantiate the UUT
   mux2t1 UUT (
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
a = 1; 
b = 0; 
sel = 0; 
#100; 
a = 0; 
b = 1; 
sel = 1; 
end
endmodule
