// Verilog test fixture created from schematic D:\Documents\GitHub\First\Xilinx-Projects\mux\mux8t1.sch - Fri May 18 17:13:14 2018

`timescale 1ns / 1ps

module mux8t1_mux8t1_sch_tb();

// Inputs
   reg [3:0] x1;
   reg [3:0] x0;
   reg [3:0] x3;
   reg [3:0] x2;
   reg [3:0] x5;
   reg [3:0] x4;
   reg [3:0] x7;
   reg [3:0] x6;
   reg [2:0] sel;

// Output
   wire [3:0] o;

// Bidirs

// Instantiate the UUT
   mux8t1 UUT (
		.x1(x1), 
		.x0(x0), 
		.x3(x3), 
		.x2(x2), 
		.x5(x5), 
		.x4(x4), 
		.x7(x7), 
		.o(o), 
		.x6(x6), 
		.sel(sel)
   );
// Initialize Inputs

initial begin 
x0 = 4'h0; 
x1 = 4'h1; 
x2 = 4'h2; 
x3 = 4'h3; 
x4 = 4'h4; 
x5 = 4'h5; 
x6 = 4'h6; 
x7 = 4'h7; 
sel = 0; 
#100; 
sel = 1; 
#100; 
sel = 2; 
#100; 
sel = 3; 
       #100;
sel = 4; 
#100; 
sel = 5; 
#100; 
sel = 6; 
#100; 
sel = 7; 
end
endmodule
