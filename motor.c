#include "motor.h"

/* Private variables */
static uint8_t stepState, masterCount;
static Direction directionState;

static void initStep(void) {
    resetStep();
    resetMasterCount;
}

uint8_t currentStep(void) {
    return stepState;
}

void nextStep(Direction state) {
    if (state == FORWARD) {
        if (stepState == 3) {
            stepState = 0;
        }
        else {
            stepState++;
        }
    }
    else {
        if (stepState == 0) {
            stepState = 3;
        }
        else {
            stepState--;
        }
    }
}

void resetStep(void) {
    stepState = 0;
}
int currentMasterCount(void) {
    return masterCount;
}

static void incrementMasterCount(void) {
    masterCount++;
}

static void decrementMasterCount(void) {
    masterCount--;
}

static void resetMasterCount(void) {
    masterCount = 0;
}

void initMotor(void) {
    //Sent all motor ports to OUTPUT mode
    MOTOR_TRIS_0 = 0;
    MOTOR_TRIS_1 = 0;
    MOTOR_TRIS_2 = 0;
    MOTOR_TRIS_3 = 0;

    initStep();

    /* TODO Motor calibration procedure */
    setMotorDirection(BACKWARD);
    //Enable the motor
    //Wait until calibration limit switch has been triggered
    //Disable the motor
    //Reset master step counter
    resetMasterCount();
    setMotorDirection(FORWARD);
}

/* Write function for the directional state */
void setMotorDirection(Direction state) {
    directionState = state;
}

/* Read function for the directional state */
Direction currentMotorDirection(void) {
    return directionState;
}

void startMotor(void) {

}

void stopMotor(void) {

}

/* This function is for the interrupt to use to control the motor */
void stepMoter(void) {
    if (currentMotorDirection == FORWARD) {
        nextStep(FORWARD);
        updateMotor(currentStep());
        incrementMasterCount();
    }
    else {
        nextStep(BACKWARD);
        updateMotor(currentStep());
        decrementMasterCount();
    }
}

void holdMotor(void) {
    //Send a HIGH to all four pins of the stepper motor
    MOTOR_0 = 1;
    MOTOR_1 = 1;
    MOTOR_2 = 1;
    MOTOR_3 = 1;
}

void releaseMotor(void) {
    //Send a LOW to all four pins of the stepper motor
    MOTOR_0 = 0;
    MOTOR_1 = 0;
    MOTOR_2 = 0;
    MOTOR_3 = 0;
}

void updateMotor(uint8_t step) {
    switch(step) {
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