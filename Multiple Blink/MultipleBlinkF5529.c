#include <msp430.h>
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD; // Stop watch dog timer

    P1SEL &= ~BIT0;     //Sets select bit to 0 to be configured as I/O
    P1OUT |= BIT0;    //Sets select bit 2 to 0 to be configured as I/O
    P1DIR |= BIT0;

    P4SEL &= ~BIT7;
    P4OUT &= ~BIT7;
    P4DIR |= BIT7;

    volatile unsigned int n, i;

    i = 10000;
    n = 50000;


    for (;;)
        {
            n--;
            i--;

            if (n==0)
            {
                P1OUT ^= BIT0;
                n = 50000;
            }

            if (i==0)
            {
                P4OUT ^= BIT7;
                i = 10000;
            }
        }
}
