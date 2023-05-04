#include <DRV8835MotorShield.h>
#include <SoftwareSerial.h>
#include <Servo.h>

int ledpin = 13;
int BTdata;

//int rxPin = 2;
//int txPin = 3;

int dir1 = 7;
int dir2 = 8;

int spd1 = 9;
int spd2 = 10;

SoftwareSerial bt(2, 3);

Servo lservo;
Servo rservo;
Servo gservo;

int lpos = 0;  // variable to store the servo position
int rpos = 0;  // variable to store the servo position
int gpos = 0;  // variable to store the servo position

void setup() {

  Serial.begin(9600);
  bt.begin(9600);
  Serial.println("Bluetooth On.");
  pinMode(ledpin, OUTPUT);

  //pinMode(rxPin, INPUT);
  //pinMode(txPin, OUTPUT);

  lservo.attach(3);
  rservo.attach(5);
  gservo.attach(11);

  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(spd1, OUTPUT);
  pinMode(spd2, OUTPUT);
}

void loop() {
  while (bt.available() > 0) {
    BTdata = bt.read();
    delay(2);
    switch (BTdata) {

      case 1:
        digitalWrite(ledpin, 1);

        digitalWrite(dir1, 1);
        digitalWrite(spd1, HIGH);
     
        digitalWrite(dir2, 1);
        digitalWrite(spd2, HIGH);

        Serial.println("Driving Forward!");
        digitalWrite(ledpin, 0);
        break;

      case 2:
        digitalWrite(ledpin, 1);

        digitalWrite(dir1, 0);
        digitalWrite(spd1, HIGH);
       
        digitalWrite(dir2, 0);
        digitalWrite(spd2, HIGH);

        Serial.println("Driving Backward!");
        digitalWrite(ledpin, 0);
        break;

      case 3:
        //motors.flipM1(true);
        digitalWrite(ledpin, 1);
        digitalWrite(dir1, 0);
        digitalWrite(spd1, HIGH);

        digitalWrite(dir2, 1);
        digitalWrite(spd2, HIGH);
    
        Serial.println("Driving Right!");
        digitalWrite(ledpin, 0);
        break;

      case 4:
        //motors.flipM2(true);
        digitalWrite(ledpin, 1);
        digitalWrite(dir1, 1);
        digitalWrite(spd1, HIGH);
     
        digitalWrite(dir2, 0);
        digitalWrite(spd2, HIGH);
      
        Serial.println("Driving Left!");
        digitalWrite(ledpin, 0);
        break;

      case 5:
        digitalWrite(ledpin, 1);
        lservo.write(90);
        rservo.write(90);

        Serial.println("Lifting!");
        digitalWrite(ledpin, 0);
        break;

      case 6:
        digitalWrite(ledpin, 1);
        lservo.write(0);
        rservo.write(0);

        Serial.println("Dropping!");
        digitalWrite(ledpin, 0);
        break;

      case 7:
        digitalWrite(ledpin, 1);
        gservo.write(0);

        Serial.println("Reaching!");
        digitalWrite(ledpin, 0);
        break;

      case 8:
        digitalWrite(ledpin, 1);
        gservo.write(90);

        Serial.println("Grabbing!");
        digitalWrite(ledpin, 0);
        break;

      default:
        digitalWrite(ledpin, 1);

        digitalWrite(spd1, LOW);
        digitalWrite(spd2, LOW);

        Serial.println(";");
        digitalWrite(ledpin, 0);
        break;
        //while using cases, shouldn't need a stop button.  If needed, change "default" to "case 5"
    }
  }
}