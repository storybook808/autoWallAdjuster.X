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
void resetStep(void);
uint8_t currentMasterCount (void);

void initMotor(void);
void setMotorDirection(Direction state);
Direction currentMotorDirection(void);
void startMotor(void);
void stopMotor(void);
void stepMotor(void);
void holdMotor(void);
void releaseMotor(void);
void updateMotor(uint8_t step);

/* Private Prototypes */
static void stepInit(void);
static void incrementMasterCount(void);
static void decrementMasteCount(void);
static void resetMasterCount(void);