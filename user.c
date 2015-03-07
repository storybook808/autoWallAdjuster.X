/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>    /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#endif

#include "user.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/


void InitApp(void)
{
    /* TODO Initialize User Ports/Peripherals/Project here */

    /* Setup analog functionality and port direction */

    /* Initialize peripherals */
    /* T0CON register */
    T0CONbits.TMR0ON = 0;
    T0CONbits.T08BIT = 1;
    T0CONbits.C0CS   = 0;
    T0CONbits.T0SE   = 0;
    T0CONbits.PSA    = 1;
    T0CONbits.T0PS2  = 0;
    T0CONbits.T0PS1  = 0;
    T0CONbits.T0PS0  = 0;

    /* INTCON1 register */
    INTCON1bits.GIE    = 1;
    INTCON1bits.PEIE   = 1;
    INTCON1bits.TMR0IE = 1;
    INTCON1bits.INT0IE = 0;
    INTCON1bits.RBIE   = 0;
    INTCON1bits.TMR0IF = 0;
    INTCON1bits.INT0IF = 0;
    INTCON1bits.RBIF   = 0;

    /* INTCON2 register */
    INTCON2bits.RBPU    = 0;
    INTCON2bits.INTEDG0 = 1;
    INTCON2bits.INTEDG1 = 1;
    INTCON2bits.INTEDG2 = 1;
    INTCON2bits.TMR0IP  = 1;
    INTCON2bits.RBIP    = 0;

    /* INTCON3 register */
    INTCON3bits.INT2IP = 0;
    INTCON3bits.INT1IP = 0;
    INTCON3bits.INT2IE = 0;
    INTCON3bits.INT1IE = 0;
    INTCON3bits.INT2IF = 0;
    INTCON3bits.INT1IF = 0;

    /* PIR1 register */
    PIR1bits.PSPIF  = 0;
    PIR1bits.ADIF   = 0;
    PIR1bits.RCIF   = 0;
    PIR1bits.TXIF   = 0;
    PIR1bits.SSPIF  = 0;
    PIR1bits.CCP1IF = 0;
    PIR1bits.TMR2IF = 0;
    PIR1bits.TMR1IF = 0;

    /* PIR2 register */
    PIR2bits.OSCFIF = 0;
    PIR2bits.CMIF   = 0;
    PIR2bits.EEIF   = 0;
    PIR2bits.BCLIF  = 0;
    PIR2bits.HLVDIF = 0;
    PIR2bits.TMR3IF = 0;
    PIR2bits.CCP2IF = 0;

    /* PIE1 register */
    PIE1bits.PSPIE  = 0;
    PIE1bits.ADIE   = 0;
    PIE1bits.RCIE   = 0;
    PIE1bits.TXIE   = 0;
    PIE1bits.SSPIE  = 0;
    PIE1bits.CCP1IE = 0;
    PIE1bits.TMR2IE = 0;
    PIE1bits.TMR1IE = 0;

    /* PIE2 register */
    PIE2bits.OSCFIE = 0;
    PIE2bits.CMIE   = 0;
    PIE2bits.EEIE   = 0;
    PIE2bits.BCLIE  = 0;
    PIE2bits.HLVDIE = 0;
    PIE2bits.TMR3IE = 0;
    PIE2bits.CCP2IE = 0;


    /* IPR1 register */
    IPR1bits.PSPIP  = 0;
    IPR1bits.ADIP   = 0;
    IPR1bits.RCIP   = 0;
    IPR1bits.TXIP   = 0;
    IPR1bits.SSPIP  = 0;
    IPR1bits.CCP1IP = 0;
    IPR1bits.TMR2IP = 0;
    IPR1bits.TMR1IP = 0;

    /* IPR2 register */
    IPR2bits.OSCFIP = 0;
    IPR2bits.CMIP   = 0;
    IPR2bits.EEIP   = 0;
    IPR2bits.BCLIP  = 0;
    IPR2bits.HLVDIP = 0;
    IPR2bits.TMR3IP = 0;
    IPR2bits.CCP2IP = 0;

    /* RCON register */
    RCONbits.IPEN = 0;
}

