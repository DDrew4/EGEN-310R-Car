#include <DRV8835MotorShield.h>

int ledpin = 13;
int BTdata;

//int rxPin = 0;
//int txPin = 1;

int dir1 = 7;
int dir2 = 8;

int spd1 = 9;
int spd2 = 10;


void setup() {

  Serial.begin(9600);
  //BTdata.begin(9600);
  Serial.println("Bluetooth On.");
  pinMode(ledpin, OUTPUT);

//  pinMode(rxPin, INPUT);
//  pinMode(txPin, OUTPUT);

  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(spd1, OUTPUT);
  pinMode(spd2, OUTPUT);
}

void loop() {
  //Serial.println("Looping!");
  //if (Serial.available() > 0) {
    BTdata = Serial.read();
    //Serial.println("Reading!");
  //}
  //Serial.println("Switching!");
Serial.println(BTdata);  
  switch (BTdata) {

    case 1:
      digitalWrite(ledpin, 1);

      digitalWrite(dir1, 1);
      digitalWrite(spd1, HIGH);
      //delay(2000);
      digitalWrite(dir2, 1);
      digitalWrite(spd2, HIGH);
      //delay(2000);

      Serial.println("Driving Forward!");
      digitalWrite(ledpin, 0);
      break;

    case 2:
      digitalWrite(ledpin, 1);

      digitalWrite(dir1, 0);
      digitalWrite(spd1, HIGH);
      //delay(2000);
      digitalWrite(dir2, 0);
      digitalWrite(spd2, HIGH);
      //delay(2000);

      Serial.println("Driving Backward!");
      digitalWrite(ledpin, 0);
      break;

    case 3:
      //motors.flipM1(true);
      digitalWrite(ledpin, 1);
      digitalWrite(dir1, 0);
      digitalWrite(spd1, HIGH);
      //delay(2000);
      digitalWrite(dir2, 1);
      digitalWrite(spd2, HIGH);
      //delay(2000);
      Serial.println("Driving Right!");
      digitalWrite(ledpin, 0);
      break;

    case 4:
      //motors.flipM2(true);
      digitalWrite(ledpin, 1);
      digitalWrite(dir1, 1);
      digitalWrite(spd1, HIGH);
      //delay(2000);
      digitalWrite(dir2, 0);
      digitalWrite(spd2, HIGH);
      //delay(2000);
      Serial.println("Driving Left!");
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