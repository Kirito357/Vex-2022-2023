#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
digital_out DigitalOutA = digital_out(Brain.ThreeWirePort.A);
controller Controller1 = controller(primary);
motor BackLeft = motor(PORT10, ratio6_1, true);
motor FrontRight = motor(PORT8, ratio6_1, false);
motor BackRight = motor(PORT9, ratio6_1, false);
motor FrontLeft = motor(PORT7, ratio6_1, true);
motor Intake = motor(PORT5, ratio18_1, false);
motor FlyWheel1 = motor(PORT6, ratio18_1, true);
motor FlyWheel = motor(PORT4, ratio18_1, true);
motor Intake2 = motor(PORT12, ratio18_1, false);
encoder Xoptical = encoder(Brain.ThreeWirePort.C);
encoder Yoptical = encoder(Brain.ThreeWirePort.G);
encoder Xoptical2 = encoder(Brain.ThreeWirePort.E);
inertial Inertial1 = inertial(PORT1);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}