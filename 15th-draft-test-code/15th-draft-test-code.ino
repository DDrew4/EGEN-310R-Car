#include <DRV8835MotorShield.h>
#include <Servo.h>

int dir1 = 7;
int dir2 = 8;

int spd1 = 9;
int spd2 = 10;

Servo Lservo;  // create servo object to control a servo
Servo Aservo;
int pos = 0;  // variable to store the servo position


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Lservo.attach(11);  // attaches the servo on pin 11 to the servo object
  Aservo.attach(5);
  Serial.println("Driving!");

  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(spd1, OUTPUT);
  pinMode(spd2, OUTPUT);

  /*for (pos = 90; pos >= 30; pos -= 1) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Aservo.write(pos);  // tell servo to go to position in variable 'pos'
    delay(15);           // waits 15ms for the servo to reach the position
  }*/

  Lservo.write(30);
  Aservo.write(40);
  delay(1000);
  //Aservo.write(180);

  /*digitalWrite(dir1, 1);
  digitalWrite(spd1, HIGH);  
  digitalWrite(dir2, 1);
  digitalWrite(spd2, HIGH);
  delay(2000);

  digitalWrite(dir1, 1);
  digitalWrite(spd1, LOW);  
  digitalWrite(dir2, 1);
  digitalWrite(spd2, LOW);*/
  //delay(2000);

  //myservo.write(-40);

  for (pos = 30; pos <= 60; pos += 1) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Lservo.write(pos);  // tell servo to go to position in variable 'pos'
    delay(15);           // waits 15ms for the servo to reach the position
  }

  delay(2000);

  for (pos = 40; pos <= 200; pos += 1) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Aservo.write(pos);  // tell servo to go to position in variable 'pos'
    delay(15);           // waits 15ms for the servo to reach the position
  }

  /*Lservo.write(0);
  Aservo.write(50);
  delay(10000);


  Lservo.write(70);
  Aservo.write(200);*/

  digitalWrite(dir1, 1);
  digitalWrite(spd1, HIGH);
  digitalWrite(dir2, 1);
  digitalWrite(spd2, HIGH);
  delay(2000);

  for (pos = 200; pos >= 40; pos -= 1) {  // goes from 180 degrees to 0 degrees
    Aservo.write(pos);                   // tell servo to go to position in variable 'pos'
    delay(15);                            // waits 15ms for the servo to reach the position
  }

  delay(2000);

  for (pos = 60; pos >= 30; pos -= 1) {  // goes from 180 degrees to 0 degrees
    Lservo.write(pos);                   // tell servo to go to position in variable 'pos'
    delay(15);                            // waits 15ms for the servo to reach the position
  }

  //Lservo.write(0);
  //Aservo.write(100);

  digitalWrite(dir1, 1);
  digitalWrite(spd1, LOW);
  digitalWrite(dir2, 1);
  digitalWrite(spd2, LOW);
  delay(2000000);
}

void loop() {}
