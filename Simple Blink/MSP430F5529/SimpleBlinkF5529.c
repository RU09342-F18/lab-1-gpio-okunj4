/*  Author: Jacob Okun
    Created: September 19, 2018
    Last Updated: September 21, 2018*/


#include <msp430.h>
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD; //Stop Watchdog timer

    P1SEL &= ~BIT0;  //Changes port 1 select bit to zero allowing P1 output and direction to be selected
    P1DIR |= BIT0;  //Changes Port 1 least significant it to 1 to make direction output

    while(1)
    {
        P1OUT ^= BIT0; //X-OR to change least significant bit to turn LED on and off
        _delay_cycles(100000); //sets delay so LED can be seen
    }
    return 0;
}
