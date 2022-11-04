/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// DigitalOutA          digital_out   A               
// Controller1          controller                    
// BackLeft             motor         10              
// FrontRight           motor         8               
// BackRight            motor         9               
// FrontLeft            motor         7               
// Intake               motor         5               
// FlyWheel1            motor         6               
// FlyWheel             motor         4               
// Intake2              motor         12              
// Xoptical             encoder       C, D            
// Yoptical             encoder       G, H            
// Xoptical2            encoder       E, F            
// Inertial1            inertial      1               
// ---- END VEXCODE CONFIGURED DEVICES ----
//testing
#include "vex.h"
#include <math.h>
#include <cmath>
#include "Autonomous.h"

using namespace vex;

competition Competition;
extern motor LeftDriveSmart;
extern motor RightDriveSmart;


extern double motorpower;
extern double turnmotorpower;



extern int desired;



extern int turndesired;
extern bool reset;


extern bool enableDrivePID;


void pre_auton(void) {
  vexcodeInit();
  
}


 




// define variables used for controlling motors based on controller inputs
bool Controller1RightShoulderControlMotorsStopped = true;

// define a task that will handle monitoring inputs from Controller1

  // process the controller input every 20 milliseconds
  // update the motors based on the input values
 



  
void usercontrol(void){
  enableDrivePID =false;
  FlyWheel1.setStopping(vex::brakeType::coast);
  FlyWheel.setStopping(vex::brakeType::coast);
  double FlyWheelspeed=15;
  double Intakespeed=15;
  Controller1.Screen.setCursor(1, 1);
  while(1){

     
  if(Controller1.ButtonUp.pressing()&&FlyWheelspeed==15){
    FlyWheelspeed=10.5;
        Controller1.Screen.clearLine();
Controller1.Screen.print("F:");
Controller1.Screen.print(FlyWheelspeed);
wait(200,msec);

  } 
  else if(Controller1.ButtonUp.pressing()&&FlyWheelspeed==10.5){
    FlyWheelspeed=15;
    Controller1.Screen.clearLine();
     
     Controller1.Screen.print("F:");
Controller1.Screen.print(FlyWheelspeed);
wait(200,msec);


  } 
  
   if(Controller1.ButtonDown.pressing()&&Intakespeed==15){
    Intakespeed=4;
         Controller1.Screen.clearLine();
     Controller1.Screen.print("I:");
Controller1.Screen.print(Intakespeed);
wait(200,msec);

  } 
  else if(Controller1.ButtonDown.pressing()&&Intakespeed==4){
    Intakespeed=15;
        Controller1.Screen.clearLine();
     Controller1.Screen.print("I:");
Controller1.Screen.print(Intakespeed);
wait(200,msec);

  } 
    
  if(Controller1.ButtonR2.pressing()){
    DigitalOutA.set(true);

    
  }else {
      DigitalOutA.set(false);

  }

  if(Controller1.ButtonL1.pressing()){
    Intake.spin(vex::forward,Intakespeed,volt);
    Intake2.spin(vex::reverse,Intakespeed,volt);


  }else  if(Controller1.ButtonL2.pressing()){
    Intake.spin(vex::reverse,Intakespeed,volt);
    Intake2.spin(vex::forward,Intakespeed,volt);


  }
   else{
    Intake.stop();
    Intake2.stop();


  }
    if(Controller1.ButtonR1.pressing()){

    FlyWheel.spin(vex::forward,FlyWheelspeed,volt);
    FlyWheel1.spin(vex::reverse,FlyWheelspeed,volt);
    
 

  }else{
   
  FlyWheel.stop();
  FlyWheel1.stop();


  }//testing
  /*if(Controller1.ButtonA.pressing()){
FrontRight.spin(vex::forward);
 

  }else if(Controller1.ButtonB.pressing()){
FrontLeft.spin(vex::forward);
 

  }else if(Controller1.ButtonX.pressing()){
BackLeft.spin(vex::forward);
 

  }else if(Controller1.ButtonY.pressing()){
BackRight.spin(vex::forward);
 

  }
  else{
   
FrontRight.stop();

  FrontLeft.stop();
  BackRight.stop();
  BackLeft.stop(); 

  
   }*/
   double forward = 0;
  double sideways = 0;
  double turn=  0;

  if(Controller1.Axis4.position(vex::percent) > 20 ||Controller1.Axis4.position(vex::percent) < -20  ){
   sideways = Controller1.Axis4.position(vex::percent);
  }
  else{
    sideways = 0;
  }
  if(Controller1.Axis1.position(vex::percent) > 20 ||Controller1.Axis1.position(vex::percent) < -20  ){
  turn = Controller1.Axis1.position(vex::percent);
  }
  else{
   turn = 0;
  }  if(Controller1.Axis3.position(vex::percent) > 20 ||Controller1.Axis3.position(vex::percent) < -20  ){
  forward = Controller1.Axis3.position(vex::percent);
  }
  else{
   forward= 0;
  }

/*
FrontRight.spin(vex::forward, turn- sideways - forward, vex::percent);
  FrontLeft.spin(vex::forward,  turn + sideways + forward, vex::percent);
  BackRight.spin(vex::forward,  turn + sideways - forward, vex::percent);
  BackLeft.spin(vex::forward,   turn - sideways + forward, vex::percent);*/

  FrontRight.spin(vex::forward, forward - sideways - turn, vex::percent);
  FrontLeft.spin(vex::forward,  forward + sideways + turn, vex::percent);
  BackRight.spin(vex::forward,  forward + sideways - turn, vex::percent);
  BackLeft.spin(vex::forward,   forward - sideways + turn, vex::percent);
  wait(20, msec); 
//INTAKE PORT 6
//FLYWHEEL PORT 4 5


  }
  
  
  }
  void autonomous(void) {
   
  
   SkillsAuton();
}

int main() {
  Competition.autonomous(autonomous);

  

  Competition.drivercontrol(usercontrol);
  while (true) {
    wait(100, msec);
  }
  
  }