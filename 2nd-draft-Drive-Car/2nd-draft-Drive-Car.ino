
//Date Updated: 4/2/23

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

  if (Serial.available()) {
    BluetoothData = Serial.read();
    if (BluetoothData == '1') {  // if number 1 is pressed ....

      digitalWrite(ledpin, 1);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);

      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      Serial.println("Driving Forward!");
      digitalWrite(ledpin, 0);
    }
    
    if (BluetoothData == '2') {  // if number 2 is pressed ....

      digitalWrite(ledpin, 1);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);

      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      Serial.println("Driving Backward!");
      digitalWrite(ledpin, 0);
    }

    if (BluetoothData == '3') {  // if number 2 is pressed ....

      digitalWrite(ledpin, 1);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);

      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      Serial.println("Driving Right!");
      digitalWrite(ledpin, 0);
    }

    if (BluetoothData == '4') {  // if number 2 is pressed ....

      digitalWrite(ledpin, 1);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);

      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      Serial.println("Driving Left!");
      digitalWrite(ledpin, 0);
    }
    
    if (BluetoothData == '5') {  // if number 2 is pressed ....

      digitalWrite(ledpin, 1);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);

      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      Serial.println("Driving Nowhere!");
      digitalWrite(ledpin, 0);
    }

  }
  delay(100);  // prepare for next input ...
}
