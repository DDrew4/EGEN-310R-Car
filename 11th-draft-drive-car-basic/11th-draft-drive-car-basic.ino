#include <DRV8835MotorShield.h>
#include <Servo.h>

int dir1 = 7;
int dir2 = 8;

int spd1 = 9;
int spd2 = 10;

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(spd1, OUTPUT);
  pinMode(spd2, OUTPUT);

  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dir1, 1);
  digitalWrite(spd1, HIGH);
  //delay(2000);
  digitalWrite(dir2, 1);
  digitalWrite(spd2, HIGH);
  //delay(2000);

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }  

  // OR myservo.write(90); , which writes it to 90 degrees

  //Serial.println("Driving Forward!");
}
