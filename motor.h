typedef enum
{
    FORWARD,
    BACKWARD
}Direction;

/* TODO Update motor ports */

/* Motor Definitions */
#define MOTOR_0
#define MOTOR_1
#define MOTOR_2
#define MOTOR_3
#define MOTOR_TRIS_0
#define MOTOR_TRIS_1
#define MOTOR_TRIS_2
#define MOTOR_TRIS_3

/* Public Prototypes */
uint8_t currentStep(void);
void nextStep(Direction state);

void holdMotor(void);
void releaseMotor(void);
void updateMotor(uint8_t step);

/* Private Prototypes */
static void  stepInit(void);