MSP430-LCD-Driver
=================

8-bit Parallel interface LCD Driver for the MSP430G2553 MCU

This allows interfacing of a standard LCD with an 8-bit parallel interface to the MSP430G2553 microcontroller from Texas Instruments.  

The MSP430_lcd.h header file contains detailed descriptions of each function created for communication between the MCU and the LCD.  Definitions for the instructions for the LCD controller are also in the header file, as well as the following pin out digram:

  		                 |	   LCD	         |
   LCD Pin #             |       Function		 |	 MSP Pin #
                     ------------------------------------------
  	PIN 14	        |          DB7		 |	  P1.7
  	PIN 13	        |          DB6		 |	  P1.6
  	PIN 12	        |          DB5		 |	  P1.5
  	PIN 11	        |          DB4		 |	  P1.4
  	PIN 10	        |          DB3		 |	  P1.3
  	PIN 9		|	   DB2		 |	  P1.2
  	PIN 8		|	   DB1		 |	  P1.1
  	PIN 7		|	   DB0		 |	  P1.0
  	PIN 6		|	   E		         |	  P2.0
  	PIN 5		|	   R/W		 |	  P2.1
  	PIN 4		|	   RS		         |	  P2.2
  	PIN 3		|	   CONTRAST	 |	  GND
  	PIN 2		|	   VCC		 |	  5V
  	PIN 1		|	   VSS		 |	  GND

note: the MSP430 uses 3.3V logic, and some LCDs use 5V logic, but can be powered with 3.3V logic level data.  Do not attempt to read from the LCD unless you have taken proper precautions for protecting the MSP's input ports--utilizing a logic translator IC for example.
