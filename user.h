/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

#define ENABLE_TMR0  T0CONbits.TMR0ON = 1
#define DISABLE_TMR0 T0CONbits.TMR0ON = 0

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

/* TODO User level functions prototypes (i.e. InitApp) go here */

void InitApp(void);         /* I/O and Peripheral Initialization */
