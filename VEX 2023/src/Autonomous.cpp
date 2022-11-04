
#include "vex.h"
#include <math.h>
#include <cmath>

using namespace vex;




vex::task PID;
vex::task Move;
vex::task PID1;
double todegree=0.08866;//360 degrees=30.3 cm x
double todegrees2=(360/30.3);
double kp=3;
double kI=0.02;
double kD=0.7;
double turnkp=7;
double turnkI=0.0;
double turnkD=0.2;
double sidekp=2.25;
double sidekI=0.02;
double sidekD=0.1;
int desired;
int error; 
int prevError; 
int derivative;
int totalError; 


int turndesired;

int turnerror; 
int turnprevError;

int turnderivative;
int turntotalError; 
int sidedesired;

int sideerror; 
int sideprevError;

int sidederivative;
int sidetotalError; 
double sidemotorpower;
double turnmotorpower;
double motorpower;
bool reset=false; 

bool enableDrivePID =true;
int drivePID(){
 

  

  while(enableDrivePID){
    if(reset){
      reset =false;
      Xoptical.resetRotation();
      Yoptical.resetRotation();
Inertial1.setRotation(0,deg);

    }
   /////////////////////////////////////////////////////////////
    int Xwheelposition = Xoptical.position(deg);
    // int Xwheelposition2 = Yoptical.position(deg);
       //int Ywheelposition = ((Yoptical.position(deg)+Xoptical.position(deg))/2) ;
   

      // int averageposition=(Xwheelposition +Xwheelposition2)/2;
      error=desired - Xwheelposition;
      //error=averageposition-desired;

       derivative =error-prevError;
       totalError += error;
        //motorpower=error* kp +derivative*kD;
        motorpower=error* kp +derivative*kD+totalError*kI;
            Brain.Screen.print("PID");
          
     Brain.Screen.print(motorpower);
    vex::task::sleep(500);
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1); 
    
/////////////////////////////////////////////////////////////////////// 


        //int Xwheelrotation = Xoptical.rotation(deg) ;
    
       //int Ywheelrotation = (Yoptical.rotation(deg)-Xoptical.rotation(deg))/2;
       // int Xwheelposition2= Xoptical2.position(deg)-Xoptical.position(deg) ;
int brotation=Inertial1.angle();

   //int Ywheelrotation = Yoptical.position(deg) ;
     // int Ywheelrotation = (Yoptical.position(deg)+Xoptical.position(deg))/2;
   //int diffrence=(Ywheelrotation-Xwheelrotation)/2;
 // int turnaverageposition=(Xwheelposition2 +Ywheelposition)/2;
      // int turnaveragerotation=(Xwheelrotation+Ywheelrotation)/2;
       turnerror=turndesired-brotation;

      turnderivative = turnerror-turnprevError;
       turntotalError += turnerror;

        turnmotorpower=turnerror* turnkp + turnderivative*turnkD;

   Brain.Screen.print("PID");
          Brain.Screen.print(turnerror);
     Brain.Screen.print(turnmotorpower);
    vex::task::sleep(1000);
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1); 
//////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////

  
        //int Xwheelrotation = Xoptical.rotation(deg) ;
   int Ywheelposition = Yoptical.position(deg) ;
       //int Ywheelrotation = (Yoptical.rotation(deg)-Xoptical.rotation(deg))/2;
        //int Xwheelposition = Xoptical2.position(deg) ;

   //int Ywheelrotation = Yoptical.position(deg) ;
     // int Ywheelrotation = (Yoptical.position(deg)+Xoptical.position(deg))/2;
   //int diffrence=(Ywheelrotation-Xwheelrotation)/2;
  //int turnaverageposition=(Xwheelposition +Ywheelposition)/2;
      // int turnaveragerotation=(Xwheelrotation+Ywheelrotation)/2;
       sideerror=sidedesired-Ywheelposition;
      


      sidederivative = sideerror-sideprevError;
       sidetotalError += sideerror;

        sidemotorpower=sideerror* sidekp + sidederivative*sidekD;

   Brain.Screen.print("PID");
          Brain.Screen.print(turnerror);
     Brain.Screen.print(turnmotorpower);
    vex::task::sleep(1000);
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1); 
//////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////

    
    sideprevError=sideerror;

    prevError=error;
    turnprevError=turnerror;
    vex::task::sleep(20);
    }
  
  


  return  1;
}

int move(){
 while(1){
  FrontRight.spin(vex::forward, motorpower  -sidemotorpower - turnmotorpower, dps);
  FrontLeft.spin(vex::forward,  motorpower  +sidemotorpower+ turnmotorpower, dps);
  BackRight.spin(vex::forward,  motorpower  +sidemotorpower- turnmotorpower, dps);
  BackLeft.spin(vex::forward,   motorpower  -sidemotorpower+ turnmotorpower, dps);

  }
 return 1;
}
int drivePID1(){
    if(reset){
      reset =false;
      Xoptical.resetRotation();
      Yoptical.resetRotation();


    }
  while(1){
  
      //int Xwheelrotation = Xoptical.rotation(deg) ;
    //int Ywheelrotation = Yoptical.rotation(deg) ;
       //int Ywheelrotation = (Yoptical.rotation(deg)-Xoptical.rotation(deg))/2;
        int Xwheelrotation = std::abs(Xoptical.position(deg));
   //int Ywheelrotation = Yoptical.position(deg) ;
     // int Ywheelrotation = (Yoptical.position(deg)+Xoptical.position(deg))/2;
   //int diffrence=(Ywheelrotation-Xwheelrotation)/2;
  // int turnaverageposition=(Xwheelposition -Ywheelposition)/2;
      // int turnaveragerotation=(Xwheelrotation+Ywheelrotation)/2;
       turnerror=turndesired-Xwheelrotation;
      


      turnderivative = turnerror-turnprevError;
       turntotalError += turnerror;

        turnmotorpower=turnerror* turnkp + turnderivative*turnkD;

   Brain.Screen.print("PID");
          Brain.Screen.print(turnerror);
     Brain.Screen.print(turnmotorpower);
    vex::task::sleep(1000);
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    turnprevError=turnerror;
    vex::task::sleep(20); }
    
    return 1;
    
    }

   
 void SkillsAuton(){
  PID= vex::task(drivePID);
  // PID1= vex::task(drivePID1);
  Move= vex::task(move);

   reset=true;
    

   //desired =100/todegree;
   //desired=100*todegree2;
 // desired=360;
 //desired=200*todegrees2;

   //turndesired=500;
  //desired=100*todegrees2;
  desired=200;
  turnmotorpower=0;
  sidemotorpower=0;  

  /* 
while (1) {
      Brain.Screen.print("xp");
   
     Brain.Screen.print(Xoptical.position(deg));
      Brain.Screen.print("yr");
      Brain.Screen.print(Yoptical.rotation(deg));
       Brain.Screen.print("xr");
       Brain.Screen.print(Xoptical.rotation(deg));
        Brain.Screen.print("yp");
        Brain.Screen.print(Yoptical.position(deg));
    vex::task::sleep(500);
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1); 
    
  }
   
*/
}
 
