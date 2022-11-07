#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDT_ADLY_250;                      // WDT 1000ms, SMCLK, interval timer. watchdog sends the interrupt every 250ms.
    P6OUT &= ~BIT6; //sets the last digit of P1OUT to 0.
    P6DIR |= BIT6; //Sets the last bit of P1DIR to 1. This denotes it as an output.  IN = 0, OUT = 1
    PM5CTL0 &= ~LOCKLPM5; //power mode 5 of control register 0. The last bit of it is set to 0. Power managment mode
    SFRIE1 |= WDTIE; //enables interrupts by oring with watchdog timer(1).
    _enable_interrupts(); //preset macro on our boards.
    while (1);

}
    #pragma vector=WDT_VECTOR
    __interrupt void wdtled(void)
    {
            P6OUT^=BIT6;  //makes sure that this interrupt is called before every time void runs? P1out gets toggled on and off here.
    }

