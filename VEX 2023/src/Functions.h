/*Functions: 1. Intake(Forward)
            2. Intake(Backward)
            3.Flywheel
            4.Pneumatics
            5.DrivingFoward
            6.DriveBack
            7.DriveLeft
            8.DriveRight
            testing

            tesitng2
            
            */


#include "vex.h"
#include <math.h>
#include <cmath>
#include "Autonomous.h"

using namespace vex; 
extern motor LeftDriveSmart;
extern motor RightDriveSmart;


extern int desired;



extern int turndesired;
extern bool reset;


extern bool enableDrivePID;
extern double motorpower;
extern double turnmotorpower;

void stop(){
  FrontRight.stop();
  FrontLeft.stop();
  BackRight.stop();
  BackLeft.stop();
  FlyWheel.stop();
FlyWheel1.stop();
Intake.stop();
Intake2.stop();

}
void eject(){
  DigitalOutA.set(true);
   wait(1,seconds);
  DigitalOutA.set(false);
 wait(1,seconds);
   DigitalOutA.set(true);
    wait(1,seconds);
  DigitalOutA.set(false);
  wait(1,seconds);
   DigitalOutA.set(true);
    wait(1,seconds);
  DigitalOutA.set(false);
}
void intakeUp(){
Intake.spin(vex::forward,100,pct);
    Intake2.spin(vex::reverse,100,pct);
    wait(3,seconds);
  
}

void roller(double time){
   Intake.spin(vex::reverse,100,pct);
    Intake2.spin(vex::forward,100,pct);
    wait(time, seconds);

  
}

void shoot(int FlyWheelspeed,double time){

  FlyWheel.spin(vex::forward,FlyWheelspeed,volt);
    FlyWheel1.spin(vex::reverse,FlyWheelspeed,volt);
  wait(3, seconds);
  eject();
 
  stop();
}


void DriveForward(int speed, double time){
  FrontRight.spin(vex::forward,speed, pct);
  FrontLeft.spin(vex::forward, speed , pct);
  BackRight.spin(vex::forward, speed, pct);
  BackLeft.spin(vex::forward, speed, pct);
  wait(time,seconds);
  stop();

}
void DriveBack(int speed, double time){
  FrontRight.spin(vex::reverse,speed, pct);
  FrontLeft.spin(vex::reverse, speed , pct);
  BackRight.spin(vex::reverse, speed, pct);
  BackLeft.spin(vex::reverse, speed, pct);
  
}
void DriveRight(int speed, double time){
  FrontRight.spin(reverse,speed, pct);
  FrontLeft.spin(forward, speed , pct);
  BackRight.spin(forward, speed, pct);
  BackLeft.spin(reverse, speed, pct);
  wait(time,seconds);
  stop();
}
void DriveLeft(int speed, double time){
  FrontRight.spin(forward,speed, pct);
  FrontLeft.spin(reverse, speed , pct);
  BackRight.spin(reverse, speed, pct);
  BackLeft.spin(forward, speed, pct);
  wait(time,seconds);
  stop();
}

void TurnRight(int speed, double time){
  FrontRight.spin(vex::reverse,speed, pct);
  FrontLeft.spin(vex::forward, speed , pct);
  BackRight.spin(vex::reverse, speed, pct);
  BackLeft.spin(vex::forward, speed, pct);
  wait(time,seconds);
  stop();
}
void TurnLeft(int speed, double time){
  FrontRight.spin(vex::forward,speed, pct);
  FrontLeft.spin(vex::reverse, speed , pct);
  BackRight.spin(vex::forward, speed, pct);
  BackLeft.spin(vex::reverse, speed, pct);
  wait(time,seconds);
  stop();
}
void SkillsAuton(){

 
  DriveBack(100,1);
  roller(1);
  stop();
  DriveRight(100,1.65);
  DriveForward(60,1.1);
  TurnLeft(10,1.1);
  DriveForward(55,0.22);
  shoot(11,3);
  
  
}