#include <msp430.h>
int main()
{
    WDTCTL = WDTPW + WDTHOLD; //Stop Watchdog timer

    P1SEL &= ~BIT0;  //sets P1.0 to be configured as I/0
    P1SEL2 &= ~BIT0;
    P1DIR |= BIT0;+




    for (;;)
      {
        volatile unsigned int i;

        P1OUT ^= BIT0;                          // Toggle P1.0 using exclusive-OR

        i = 50000;                              // Delay
        do (i--);
        while (i != 0);
      }


    return(0);
}
