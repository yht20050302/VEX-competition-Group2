#include "vex.h"
#include "robot-config.h"
#include <iostream> 
using namespace vex;
using namespace std;
// A global instance of competition
competition Competition;
float A1,A2,A3,A4;
// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    A1 = Controller.Axis1.position(vex::percentUnits::pct);
    A2 = Controller.Axis2.position(vex::percentUnits::pct);
    A3 = Controller.Axis3.position(vex::percentUnits::pct);
    A4 = Controller.Axis4.position(vex::percentUnits::pct);

    Motor_LF.spin(directionType::fwd, (A1 - A2) - (A3 - A4), percentUnits::pct);
    Motor_RF.spin(directionType::fwd, (A1 - A2) + (A3 - A4), percentUnits::pct);
    Motor_LB.spin(directionType::fwd, (A1 - A2) - (A3 - A4), percentUnits::pct);
    Motor_RB.spin(directionType::fwd, (A1 - A2) + (A3 - A4), percentUnits::pct);
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  Brain.Screen.setCursor(1, 1);           //设置光标
  Brain.Screen.print("Ready"); //打印
  Controller.Screen.setCursor(1, 1);
  Controller.Screen.print("Get Started");
  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
