#include <Servo.h>

// Create servo objects.
Servo servoA;  // Base Servo: Rotate entire arm left and right.
Servo servoB;  // Arm Servo: Moves arm up and down.
Servo servoC;  // Arm Servo: Twist arm left and right.
Servo servoD;  // Claw Servo: Open and closes the claw.

//defining PWM pins
const int servoPinA = 6;  //A
const int servoPinB = 5;  //B
const int servoPinC = 3;  //C
const int servoPinD = 9;  //D



void resetArm() {
  // Arm resting position.
  servoA.write(0);
  servoB.write(0);
  servoC.write(0);
  servoD.write(0);
}

void grabItem() {
  //picking the object
  servoD.write(0);
  delay(1000);
  servoA.write(90);
  delay(1000);
  servoB.write(100);
  delay(1000);
  servoC.write(0);
  delay(1000);
}

void dropItem() {


  //placing the object
  servoB.write(180);
  delay(1000);
  servoD.write(180);
  delay(1000);
}

void fk_test1() {

  int a = map(90, 0, 180, 5, 135);  //maping for A
  int b = map(90, 0, 180, 0, 150);  // maping for B

  servoA.write(a);
  delay(1000);
  servoB.write(b);
  delay(1000);
  servoC.write(90);
  delay(1000);
}

void grab() {
  servoD.write(0);
  delay(1000);
}
void fk_test2() {

  int a = map(180, 0, 180, 5, 135);  //maping for A
  int b = map(45, 0, 180, 0, 150);   // maping for B

  servoA.write(a);
  delay(1000);
  servoB.write(b);
  delay(1000);
}

int pick_position(int angleA1, int angleB1, int angleC1) {
  for (int angle = 0; angle <= angleA1; angle += 1) {
    int a = map(angle, 0, 180, 5, 135);

    servoA.write(a);  // Move to the specified angle
    delay(20);        // Small delay for smoother motion
  }
  delay(100);

  grabbing();

  for (int angle = 0; angle <= angleB1; angle += 1) {
    int b = map(angle, 0, 180, 0, 150);

    servoB.write(b);  // Move to the specified angle
    delay(20);        // Small delay for smoother motion
  }
  delay(100);
  for (int angle = 0; angle <= angleC1; angle += 1) {
    servoC.write(angle);  // Move to the specified angle
    delay(20);            // Small delay for smoother motion
  }
  delay(100);
}

int place_position(int angleA1, int angleB1, int angleC1, int angleA2, int angleB2, int angleC2) {

  
  

  if (angleB1 < 90) {
    for (int angle = angleB1; angle <= 90; angle += 1) {
      int b = map(angle, 0, 180, 0, 150);
      servoB.write(b);  // Move to the specified angle
      delay(20);        // Small delay for smoother motion
    }
  } else {
    for (int angle = angleB1; angle >= 90; angle -= 1) {
      int b = map(angle, 0, 180, 0, 150);
      servoB.write(b);  // Move to the specified angle
      delay(20);        // Small delay for smoother motion
    }
  }

  if (angleC2 > angleC1) {
    for (int angle = angleC1; angle <= angleC2; angle += 1) {
      servoC.write(angle);  // Move to the specified angle
      delay(20);            // Small delay for smoother motion
    }
  } else {
    for (int angle = angleC1; angle >= angleC2; angle -= 1) {
      servoC.write(angle);  // Move to the specified angle
      delay(20);            // Small delay for smoother motion
    }
  }
  


  if (angleA2 > angleA1) {
    for (int angle = angleA1; angle <= angleA2; angle += 1) {
      int a = map(angle, 0, 180, 5, 135);
      servoA.write(a);  // Move to the specified angle
      delay(20);        // Small delay for smoother motion
    }
  } else {
    for (int angle = angleA1; angle >= angleA2; angle -= 1) {
      int a = map(angle, 0, 180, 5, 135);
      servoA.write(a);  // Move to the specified angle
      delay(20);        // Small delay for smoother motion
    }
  }

  if (angleB2 > 90) {
    for (int angle = 90; angle <= angleB2; angle += 1) {
      int b = map(angle, 0, 180, 0, 150);
      servoB.write(b);  // Move to the specified angle
      delay(20);        // Small delay for smoother motion
    }
  } else {
    for (int angle = 90; angle >= angleB2; angle -= 1) {
      int b = map(angle, 0, 180, 0, 150);
      servoB.write(b);  // Move to the specified angle
      delay(20);        // Small delay for smoother motion
    }
  }

  
  delay(1000);
  
  grabbing();
  for (int angle = angleB2; angle >= angleB2 - 40; angle -= 1) {
    int b = map(angle, 0, 180, 0, 150);
    servoB.write(b);  // Move to the specified angle
    delay(20);        // Small delay for smoother motion
  }
}

int back_to_initial(int angleA2, int angleB2, int angleC2) {
  for (int angle = angleA2; angle >= 0; angle -= 1) {
    int a = map(angle, 0, 180, 5, 135);

    servoA.write(a);  // Move to the specified angle
    delay(20);        // Small delay for smoother motion
  }

  delay(100);
  for (int angle = angleB2; angle >= 0; angle -= 1) {
    int b = map(angle, 0, 180, 0, 150);

    servoB.write(b);  // Move to the specified angle
    delay(20);        // Small delay for smoother motion
  }
  delay(100);

  for (int angle = angleC2; angle >= 0; angle -= 1) {
    servoC.write(angle);  // Move to the specified angle
    delay(20);            // Small delay for smoother motion
  }
  delay(100);
}

void grabbing() {
  for (int angle = 0; angle <= 180; angle += 1) {
    servoD.write(angle);  // Move to the specified angle
    delay(20);            // Small delay for smoother motion
  }
}

void dropping() {
  for (int angle = 180; angle >= 0; angle -= 1) {
    servoD.write(angle);  // Move to the specified angle
    delay(20);            // Small delay for smoother motion
  }
}




void inverse_test1() {

  int a = map(117, 0, 180, 5, 135);  //maping for A
  int b = map(112, 0, 180, 0, 150);  // maping for B

  servoA.write(a);
  delay(1000);
  servoB.write(b);
  delay(1000);
}

void setup() {

  // Servos attached to corresponding PWM pins.
  servoA.attach(servoPinA);
  servoB.attach(servoPinB);
  servoC.attach(servoPinC);
  servoD.attach(servoPinD);

  int pick_angle1 = 90;
  int pick_angle2 = 123;
  int pick_angle3 = 0;

  int place_angle1 = 170;
  int place_angle2 = 115;
  int place_angle3 = 180;


  //start with beging position.
  resetArm();
  delay(1000);
  pick_position(pick_angle1, pick_angle2, pick_angle3);
  delay(1000);
  dropping();
  delay(1000);
  place_position(pick_angle1, pick_angle2, pick_angle3, place_angle1, place_angle2, place_angle3);

  

  delay(1000);
  back_to_initial(place_angle1, place_angle2-40, place_angle3);
//
  delay(100);
//  dropping();
//  fk_test1();

  
}

void loop() {
  // for (int angle = 0; angle <= 180; angle += 1) {
  //   servoD.write(angle);  // Move to the specified angle
  //   delay(20);            // Small delay for smoother motion
  // }

  // delay(500);
  // for (int angle = 180; angle >= 0; angle -= 1) {
  //   servoD.write(angle);  // Move to the specified angle
  //   delay(20);            // Small delay for smoother motion
  // }

  //fk_test1();
  //inverse_test1();
  // pick_position(117, 125, 0);
  // place_position(117, 125, 0, 20, 50, 90);
  // back_to_initial(20, 50, 90);
}
