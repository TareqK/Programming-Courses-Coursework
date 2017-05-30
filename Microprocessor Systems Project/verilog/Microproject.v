//Tareq Kirresh
//1142828
//This is the logic for the address decoder module part of our design


module AddressDecoder(clock,address,MIO,cs,ALE);
output reg [4:0] cs;
input [15:0] address;
input clock;
input MIO;
input ALE;

always @(posedge clock)//when the clock arrives
case(MIO)//check if we are doing IO or memory
	1'b0 ://If I/0
		casez(address)//casez so that bits makred z do not effect logic , they are equivalent to DC
		16'bzzzzzzzzzzzz0zz0:cs=5'b11110;//CS of PPI1
		16'bzzzzzzzzzzzz0zz1:cs=5'b11101;//CS of PPI2
		16'bzzzzzzzzzzzz1zz0:cs=5'b11011;//CS of PIT
		default:cs=5'b11111;//If it is none of these , then no chips are selected. Perhaps an
		//interrupt should be sent?
		endcase
		
	1'b1:	casez(address)//casez so that bits makred z do not effect logic , they are equivalent to DC
		16'bzzzz01zzzzzzzzzz:cs=5'b10111;//CS of EEPROM
		16'bzzzz10zzzzzzzzzz:cs=5'b01111;//CS of SRAM
		default:cs=5'b11111;
		endcase
	endcase
	endmodule
	