using namespace vex;

extern brain Brain;

// VEXcode devices
extern digital_out DigitalOutA;
extern controller Controller1;
extern motor BackLeft;
extern motor FrontRight;
extern motor BackRight;
extern motor FrontLeft;
extern motor Intake;
extern motor FlyWheel1;
extern motor FlyWheel;
extern motor Intake2;
extern encoder Xoptical;
extern encoder Yoptical;
extern encoder Xoptical2;
extern inertial Inertial1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );