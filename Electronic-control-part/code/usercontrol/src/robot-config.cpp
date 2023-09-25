#include "vex.h"
#include "robot-config.h"
using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller Controller = controller(primary);
motor Motor_LF = motor(PORT6, ratio18_1, true);
motor Motor_LB = motor(PORT7, ratio18_1, true);
motor Motor_RF = motor(PORT12, ratio18_1, false);
motor Motor_RB = motor(PORT14, ratio18_1, false);
// motor Motor_IntakerF = motor(PORT17, ratio6_1, false);
// motor Motor_IntakerB = motor(PORT18, ratio6_1, true);
// motor Motor_ShooterF = motor(PORT4, ratio6_1, false);
// motor Motor_ShooterB = motor(PORT5, ratio6_1, true);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}