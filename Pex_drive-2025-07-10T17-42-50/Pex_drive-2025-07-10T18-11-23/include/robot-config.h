using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Right;
extern motor Left;
extern controller Controller1;
extern motor Intake;
extern motor Scoring;
extern motor Left_Back;
extern motor Right_Back;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );