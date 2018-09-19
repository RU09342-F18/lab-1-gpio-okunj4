#include <msp430.h>
int main()
{
    WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

    P1SEL &= ~BIT0;     //Sets select bit to 0 to be configured as I/O
    P1SEL2 &= ~BIT0;    //Sets select bit 2 to 0 to be configured as I/O
    P1DIR |= BIT0;

    P1SEL &= ~BIT6;
    P1SEL2 &= ~BIT6;
    P1DIR |= BIT6;

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
                P1OUT ^= BIT6;
                i = 10000;
            }
        }
    return(0);
}
