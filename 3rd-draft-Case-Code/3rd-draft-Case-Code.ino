#include <DRV8835MotorShield.h>

int ledpin = 13;    // led on D13 will show blink on / off
int BluetoothData;  // the data given from Computer

int rxPin = 2;
int txPin = 3;

int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;

int in5;
int in6;
int in7;
int in8;

DRV8835MotorShield motors;


void setup() {

  Serial.begin(9600);
  Serial.println("Bluetooth On.");
  pinMode(ledpin, OUTPUT);

  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  BluetoothData = Serial.read();
  if (Serial.available()) {
    switch (BluetoothData) {

      case 1:
        digitalWrite(ledpin, 1);
        for (int speed = 0; speed <= 400; speed++) {
          motors.setM1Speed(speed);
          motors.setM2Speed(speed);
          delay(2);
        }
        for (int speed = 400; speed >= 0; speed--) {
          motors.setM1Speed(speed);
          motors.setM2Speed(speed);
          delay(2);
        }
        Serial.println("Driving Forward!");
        digitalWrite(ledpin, 0);
        break;

      case 2:
        digitalWrite(ledpin, 1);
        for (int speed = 0; speed >= -400; speed--) {
          motors.setM1Speed(speed);
          motors.setM2Speed(speed);
          delay(2);
        }

        for (int speed = -400; speed <= 0; speed++) {
          motors.setM1Speed(speed);
          motors.setM2Speed(speed);
          delay(2);
        }
        Serial.println("Driving Backward!");
        digitalWrite(ledpin, 0);
        break;

      case 3:
        motors.flipM1(true);
        digitalWrite(ledpin, 1);
        for (int speed = 0; speed >= -400; speed--) {
          motors.setM1Speed(speed);
          motors.setM2Speed(speed);
          delay(2);
        }

        for (int speed = -400; speed <= 0; speed++) {
          motors.setM1Speed(speed);
          motors.setM2Speed(speed);
          delay(2);
        }
        Serial.println("Driving Right!");
        digitalWrite(ledpin, 0);
        break;

      case 4:
        motors.flipM2(true);
        digitalWrite(ledpin, 1);
        for (int speed = 0; speed >= -400; speed--) {
          motors.setM1Speed(speed);
          motors.setM2Speed(speed);
          delay(2);
        }

        for (int speed = -400; speed <= 0; speed++) {
          motors.setM1Speed(speed);
          motors.setM2Speed(speed);
          delay(2);
        }
        Serial.println("Driving Left!");
        digitalWrite(ledpin, 0);
        break;

      case 5:
        digitalWrite(ledpin, 1);
        motors.setM1Speed(0);
        motors.setM2Speed(0);
        Serial.println("Driving Nowhere!");
        digitalWrite(ledpin, 0);
        break;
    }
    /*if (Serial.available()) {
    BluetoothData = Serial.read();

    if (BluetoothData == '1') {  // if number 1 is pressed ....

      digitalWrite(ledpin, 1);
      for (int speed = 0; speed <= 400; speed++) {
        motors.setM1Speed(speed);
        motors.setM2Speed(speed);
        delay(2);
      }

      for (int speed = 400; speed >= 0; speed--) {
        motors.setM1Speed(speed);
        motors.setM2Speed(speed);
        delay(2);
      }
      Serial.println("Driving Forward!");
      digitalWrite(ledpin, 0);
    }

    if (BluetoothData == '2') {  // if number 2 is pressed ....

      digitalWrite(ledpin, 1);
      for (int speed = 0; speed >= -400; speed--) {
        motors.setM1Speed(speed);
        motors.setM2Speed(speed);
        delay(2);
      }

      for (int speed = -400; speed <= 0; speed++) {
        motors.setM1Speed(speed);
        motors.setM2Speed(speed);
        delay(2);
      }
      Serial.println("Driving Backward!");
      digitalWrite(ledpin, 0);
    }

    if (BluetoothData == '3') {  // if number 3 is pressed ....

      motors.flipM1(true);
      digitalWrite(ledpin, 1);
      for (int speed = 0; speed >= -400; speed--) {
        motors.setM1Speed(speed);
        motors.setM2Speed(speed);
        delay(2);
      }

      for (int speed = -400; speed <= 0; speed++) {
        motors.setM1Speed(speed);
        motors.setM2Speed(speed);
        delay(2);
      }
      Serial.println("Driving Right!");
      digitalWrite(ledpin, 0);
    }

    if (BluetoothData == '4') {  // if number 4 is pressed ....

      motors.flipM2(true);
      digitalWrite(ledpin, 1);
      for (int speed = 0; speed >= -400; speed--) {
        motors.setM1Speed(speed);
        motors.setM2Speed(speed);
        delay(2);
      }

      for (int speed = -400; speed <= 0; speed++) {
        motors.setM1Speed(speed);
        motors.setM2Speed(speed);
        delay(2);
      }
      Serial.println("Driving Left!");
      digitalWrite(ledpin, 0);
    }

    if (BluetoothData == '5') {  // if number 5 is pressed ....

      digitalWrite(ledpin, 1);
      motors.setM1Speed(0);
      motors.setM2Speed(0);
      Serial.println("Driving Nowhere!");
      digitalWrite(ledpin, 0);
    }
  }*/
    delay(100);  // prepare for next input ...
  }
}
