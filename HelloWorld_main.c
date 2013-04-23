#include <msp430g2553.h>
#include <intrinsics.h>
#include "MSP430_lcd.h"

/**
  * Hello World main program as specified in the
  * assignment guidelines.
  *
  * Author: Donald Percivalle
  *         Alex Lin
  **/
int i = 0;

int main(void) {
   //
   //Disable watchdog timer and calibrate DCO to 1Mhz
   //
   WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
   DCOCTL = 0;
   BCSCTL1 = CALBC1_1MHZ;
   DCOCTL = CALDCO_16MHZ;
   //
   // Initialize LCD in the right-moving, invisible
   // cursor, static display mode.
   //
   lcd_init(MODE_RT_NOSHIFT);

   //
   // Create and save custom characters
   //
   //
   // Left border at CGRAM location 0
   //
   lcd_writeData(0x40, FALSE);
   unsigned char left_Border[8] = {0x1F, 0x1C, 0x18, 0x10,
                                   0x10, 0x00, 0x00, 0x00};
   lcd_customCharacterInit(left_Border);

   //
   // Right border cat CGRAM location 1
   //
   unsigned char right_Border[8] = {0x1F, 0x07, 0x03, 0x01,
                                    0x01, 0x00, 0x00, 0x00};
   lcd_customCharacterInit(right_Border);

   //
   // Horse tail at CGRAM location 2
   //
   unsigned char horse_Tail[8] = {0x00, 0x00, 0x00, 0x01,
                                  0x07, 0x0B, 0x02, 0x04};
   lcd_customCharacterInit(horse_Tail);

   //
   // Horse body at CGRAM location 3
   //
   unsigned char horse_Body[8] = {0x00, 0x01, 0x00, 0x1F,
                                  0x1F, 0x1E, 0x02, 0x04};
   lcd_customCharacterInit(horse_Body);

   //
   // Horse head at CGRAM location 4
   //
   unsigned char horse_Head[8] = {0x00, 0x00, 0x10, 0x18,
                                  0x1C, 0x00, 0x00, 0x00};
   lcd_customCharacterInit(horse_Head);

   //
   // Print "Hello world!" on the LCD
   //
   lcd_goHome();
   lcd_printString("Hello world!", DELAY, TOP_LINE);

   //
   // Enable interrupts on P2.3 after the LCD
   // initialization, and enter low power mode 4.
   //
   P2IE |= BIT3;
   P2IES |= BIT3;
   P2IFG &= ~BIT3;


   __enable_interrupt();
   _low_power_mode_3();
   return 0;
}

/**
  * Port 2 interrupt vector to change
  * message displayed on LCD.
  **/
#pragma vector = PORT2_VECTOR
__interrupt void P2ISR(){
   //
   // Disable nested and additional interrupts
   //
   __disable_interrupt();

   //
   // Additional string (left-button) pressed
   //
   lcd_goHome();
   lcd_printString("   ", NO_DELAY, TOP_LINE);
   lcd_writeData(0x00, TRUE);
   lcd_printString("Cal Poly", NO_DELAY, CURRENT_LOCATION);
   lcd_writeData(0x01, TRUE);
   lcd_writeData(BOTTOM_LINE, FALSE);
   lcd_writeData(0x02, TRUE);
   lcd_writeData(0x03, TRUE);
   lcd_writeData(0x04, TRUE);
   __delay_cycles(500000);
   lcd_printString("GO MUSTANGS!", DELAY, CURRENT_LOCATION);
   __delay_cycles(500000);
}


