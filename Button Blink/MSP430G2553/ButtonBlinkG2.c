/*  Author: Jacob Okun
    Created: September 17, 2018
    Last Updated: September 21, 2018*/

#include <msp430.h>
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD; //stop watchdog timer

    P1DIR = BIT0; //Sets Port 1 to output pin
    P1REN = BIT3; //Enables pull-up resistor for Port 1
    P1OUT = BIT3; //Sets Port 1 output to normally high by connecting to pull up resistor

    while(1)
    {
        if((P1IN & BIT3)!=BIT3)
        {
            _delay_cycles(250000); //sets delay so LED can be seen with button press
            P1OUT ^= BIT0; //XOR to turn LED on and off
        }
    }
}
