/*  Author: Jacob Okun
    Created: September 12, 2018
    Last Updated: September 21, 2018*/


#include <msp430.h>
int main()
{
    WDTCTL = WDTPW + WDTHOLD; //Stop Watchdog timer

    P1SEL &= ~BIT0;  //sets Port 1 Select bit to zero
    P1SEL2 &= ~BIT0; //sets Port 1 Select bit 2 to zero
    P1DIR |= BIT0; //Makes pin 0 high and pin 1 low




    for (;;)
      {
        volatile unsigned int i;

        P1OUT ^= BIT0;                          // Toggle P1.0 using exclusive-OR which turns the LED on and off

        i = 50000;                              // Delay that allows the LED to be seen
        do (i--);
        while (i != 0);
      }


    return(0);
}
