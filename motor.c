#include "motor.h"

/* Private variables */
static uint8_t stepState;

static void initStep(void)
{
    stepState = 0;
}

uint8_t currentStep(void)
{
    return stepState;
}

void nextStep(Direction state)
{
    if (state == FORWARD)
    {
        if (stepState == 3)
        {
            stepState = 0;
        }
        else
        {
            stepState++;
        }
    }
    else
    {
        if (stepState == 0)
        {
            stepState = 3;
        }
        else
        {
            stepState--;
        }
    }
}

void initMotor(void)
{
    //Sent all motor ports to OUTPUT mode
    MOTOR_TRIS_0 = 0;
    MOTOR_TRIS_1 = 0;
    MOTOR_TRIS_2 = 0;
    MOTOR_TRIS_3 = 0;

    initStep();
}

void holdMotor(void)
{
    //Send a HIGH to all four pins of the stepper motor
    MOTOR_0 = 1;
    MOTOR_1 = 1;
    MOTOR_2 = 1;
    MOTOR_3 = 1;
}

void releaseMotor(void)
{
    //Send a LOW to all four pins of the stepper motor
    MOTOR_0 = 0;
    MOTOR_1 = 0;
    MOTOR_2 = 0;
    MOTOR_3 = 0;
}

void updateMotor(uint8_t step)
{
    switch(step)
    {
        case 0:
            releaseMotor();
            MOTOR_0 = 1;
            break;
        case 1:
            releaseMotor();
            MOTOR_1 = 1;
            break;
        case 2:
            releaseMotor();
            MOTOR_2 = 1;
            break;
        case 3:
            releaseMotor();
            MOTOR_3 = 1;
            break;
    }
}