#include <msp430.h>
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD; //stop watchdog timer

    P1DIR = BIT0; //Sets Port 1 to output pin
    P1REN = BIT1; //Enables pull-up resistor for Port 1, pin 1
    P1OUT = BIT1; //Sets Port 1 output to normally high by connecting to pull up resistor

    while(1)
    {
        if((P1IN & BIT1)!=BIT1)
        {
            _delay_cycles(250000); //sets delay so LED can be seen with button press
            P1OUT ^= BIT0;
        }
    }
}
