/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\liu_b                                            */
/*    Created:      Wed Jul 09 2025                                           */
/*    Description:  2025 basebot drive code                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Right                motor         2               
// Left                 motor         1               
// Controller1          controller                    
// Intake               motor         5               
// Scoring              motor         3               
// Left_Back            motor         9               
// Right_Back           motor         10              
// sensor24mm           distance      6               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
bool activateConveyor = true;
bool activateIntake = true;
bool activateTake = true;
bool activatePlace = true;
bool lastButtonState = false;
bool activateRight = true;
bool activateLeft = true;

void conveyorRun() {
  if (Controller1.ButtonR1.pressing()) {
    if (activateConveyor) {
      Scoring.spin(forward);
      Intake.spin(reverse);
      activateConveyor = false;
    } else {
      Scoring.stop();
      Intake.stop();
      activateConveyor = true;
    }
    wait(200, msec);
  }
  wait(20, msec);
}
void intake() {
  if (Controller1.ButtonLeft.pressing()) {
    if (activateTake) {
      Intake.spin(reverse);
      Scoring.spinFor(forward, 100, degrees);
      activateTake = false;
    } else {
      Scoring.stop();
      Intake.stop();
      activateTake = true;
    }
    wait(200, msec);
  }
  wait(20, msec);
}

void score() {
  if (Controller1.ButtonUp.pressing()) {
    if (activatePlace) {
      Scoring.spin(forward);
      activatePlace = false;
    } else {
      Scoring.stop();
      activatePlace = true;
    }
    wait(200, msec);
  }
  wait(20, msec);
}

void arcadeDrive() {
  double leftJoystick = Controller1.Axis1.position(percent);
  double rightJoystick = Controller1.Axis3.position(percent);

  Left.setVelocity((leftJoystick + rightJoystick), percent);
  Right.setVelocity((leftJoystick - rightJoystick), percent);
  Left_Back.setVelocity((leftJoystick + rightJoystick), percent);
  Right_Back.setVelocity((leftJoystick - rightJoystick), percent);
  Left.spin(forward);
  Right.spin(forward);
  Left_Back.spin(forward);
  Right_Back.spin(forward);
}
void tankDrive() {
  double leftJoystick = Controller1.Axis3.position(percent);
  double rightJoystick = Controller1.Axis2.position(percent);
  Left.setVelocity((leftJoystick), percent);
  Right.setVelocity((rightJoystick),percent);
}

void loading() {
 bool currentButtonState = Controller1.ButtonX.pressing();

  if (currentButtonState && !lastButtonState) {  // Button just pressed (rising edge)
    if (activateIntake) {
      Intake.spin(reverse, 200, rpm);

      for (int i = 0; i < 4; i++) {
      Left.spinFor(forward, 2, turns, false);
      Right.spinFor(forward, 2, turns, false);
      Left_Back.spinFor(forward, 2, turns, false);
      Right_Back.spinFor(forward, 2, turns, true);

      Scoring.spinFor(forward, 65, degrees);

      wait(0.7, sec);

      Right.spinFor(reverse, 2, turns, false);
      Left.spinFor(reverse, 2, turns, false);
      Right_Back.spinFor(reverse, 2, turns, false);
      Left_Back.spinFor(reverse, 2, turns, true);
      }

      Intake.stop();
      Scoring.stop();
      Left.stop();
      Right.stop();
      Right_Back.stop();
      Left_Back.stop();

      activateIntake = false;
    } else {
      // Stop all motors
      Intake.stop();
      Right.stop();
      Left.stop();
      Right_Back.stop();
      Left_Back.stop();
      Scoring.stop();

      activateIntake = true;
    }

    wait(200, msec); // Debounce delay
  }

  lastButtonState = currentButtonState;
}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Left.setVelocity(100, percent);
  Right.setVelocity(100, percent);
  Right_Back.setVelocity(100, percent);
  Left_Back.setVelocity(100, percent);
  Scoring.setVelocity(75, percent);
  Intake.setVelocity(100, percent);
  while (true) {
    arcadeDrive();
    conveyorRun();
    loading();
    score();
    intake();
    //tankDrive();
    wait(10, msec);
  }
 
}
