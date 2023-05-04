#include <DRV8835MotorShield.h>

int ledpin = 13;
int BTdata;

int rxPin = 2;
int txPin = 3;

int dir1 = 7;
int dir2 = 8;

int spd1 = 9;
int spd2 = 10;


void setup() {

  Serial.begin(9600);
  Serial.println("Bluetooth On.");
  pinMode(ledpin, OUTPUT);

  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(spd1, OUTPUT);
  pinMode(spd2, OUTPUT);
}

void loop() {

  if (Serial.available()) {
    BTdata = Serial.read();

    Serial.println("Driving Forward!");
    digitalWrite(ledpin, 1);
    
    digitalWrite(dir1, 1);
    digitalWrite(spd1, HIGH);
    delay(2000);
    digitalWrite(dir2, 1);
    digitalWrite(spd2, HIGH);
    delay(2000);

    digitalWrite(ledpin, 0);
    delay(10);  // prepare for next input ...
  }

  else {
    Serial.println(",");
    digitalWrite(ledpin, 1);
    delay(200);
    digitalWrite(ledpin, 0);
    delay(200);
    digitalWrite(ledpin, 1);
    delay(200);
    digitalWrite(ledpin, 0);
    delay(200);
    digitalWrite(ledpin, 1);
    delay(200);
    digitalWrite(ledpin, 0);
    delay(1000);
    digitalWrite(ledpin, 1);
    delay(1000);
    digitalWrite(ledpin, 0);
    delay(200);
  }
}
