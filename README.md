MSP430 LCD Driver
=================

This allows interfacing of a standard LCD with an 8-bit parallel interface to the MSP430G2553 microcontroller from             Texas Instruments.  This version of the driver requires that the MCU is operating at a 1MHz clock when communicating with the LCD. 

The ````MSP430_lcd.h```` header file contains detailed descriptions of each function created for communication between the MCU and the LCD.  Definitions for the instructions for the LCD controller are also in the header file, as well as a table describing the pins used.

Using my driver in your project
-------------------------
To use this driver, clone the repository and include the ````MSP430_lcd.h```` and ````MSP430_lcd.c```` header and source files in your project.  Pay attention to the pins used for the driver, and avoid collisions in your design.  Initialize the LCD by calling the initialization function in your program main.
    
     lcd_init();

You can write a string to the LCD with the print string function.  The following example writes the string "Hello World!" with a small delay between each character to the top line of the LCD.
    
     lcd_printString("Hello world!", DELAY, TOP_LINE);



Logic Level Issues
-------------------------
The MSP430 uses 3.3V logic, and some LCDs use 5V logic, but can be powered with 3.3V logic level data.  Do not                 attempt to read from the LCD unless you have taken proper precautions for protecting the MSP's input ports; utilizing a logic translator IC for example.
