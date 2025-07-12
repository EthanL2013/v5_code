#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Right = motor(PORT2, ratio6_1, false);
motor Left = motor(PORT1, ratio6_1, false);
controller Controller1 = controller(primary);
motor Intake = motor(PORT5, ratio18_1, false);
motor Scoring = motor(PORT3, ratio18_1, false);
motor Left_Back = motor(PORT8, ratio6_1, false);
motor Right_Back = motor(PORT9, ratio6_1, false);

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