#include <msp430.h>
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD; //Stop Watchdog timer

    P1SEL &= ~BIT0;
    P1DIR |= BIT0;

    while(1)
    {
        P1OUT ^= BIT0;
        _delay_cycles(100000);
    }
    return 0;
}
