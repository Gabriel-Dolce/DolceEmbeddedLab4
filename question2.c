#include <msp430.h>
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;                 // Stop WDT
    P1DIR |= BIT6 | BIT7;                     // P1.6 and P1.7 output
    P1SEL1 |= BIT6 | BIT7;                    // P1.6 and P1.7 options select
    PM5CTL0 &= ~LOCKLPM5;
    TB0CCR0 = 62500;                         // PWM Period. Frequency of TBO clock
    TB0CCTL1 = OUTMOD_7;                      // CCR1 reset/set
    TB0CCR1 = 6250;                            // CCR1 PWM duty cycle
    //TB0CCTL2 = OUTMOD_7;                      // CCR2 reset/set
    //TB0CCR2 = 250;                            // CCR2 PWM duty cycle
    TB0CTL = TBSSEL__SMCLK | MC__UP | TBCLR| ID_3;  // SMCLK, up mode, clear TBR
    while(1)
    {
        P1OUT ^=BIT6;// For debugger
    }
}
