/*  Author: Jacob Okun
    Created: September 12, 2018
    Last Updated: September 21, 2018*/


#include <msp430.h>
int main()
{
    WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

    P1SEL &= ~BIT0;     //Sets select bit to 0 for BIT 0 to be configured as I/O
    P1SEL2 &= ~BIT0;    //Sets select bit 2 to 0 for BIT 0 to be configured as I/O
    P1DIR |= BIT0; //Sets Port 1 direction to pin 0 to control LED

    P1SEL &= ~BIT6; //Sets select bit to 0 for BIT 6 to be configured as I/O
    P1SEL2 &= ~BIT6; //Sets select bit 2 to 0 for BIT 6 to be configured as I/O
    P1DIR |= BIT6; //Sets Port 1 direction to pin 6 to control LED

    volatile unsigned int n, i;

    i = 10000; //Sets delay for LED blinking in P1.0
    n = 50000; //Sets delay for LED blinking in P1.6


    for (;;)
        {
            n--;
            i--;

            if (n==0) //if statement that checks if the first variable is a high enough value to turn on the LED
            {
                P1OUT ^= BIT0; //XOR to turn on and off first LED
                n = 50000;
            }

            if (i==0) //if statement that checks if the first variable is a high enough value to turn on the LED
            {
                P1OUT ^= BIT6; //XOR to turn on and off second LED
                i = 10000;
            }
        }
    return(0);
}
