
//Date Updated: 3/31/23


int ledpin = 13;                    // led on D13 will show blink on / off
int BluetoothData;                  // the data given from Computer


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Bluetooth On. Please enter 1 or 0 to blink LED ..");
  pinMode(ledpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    BluetoothData = Serial.read();
    if (BluetoothData == '1') {  // if number 1 pressed ....
      digitalWrite(ledpin, 1);
      Serial.println("LED is On!");
    }
    if (BluetoothData == '0') {  // if number 0 pressed ....
      digitalWrite(ledpin, 0);
      Serial.println("LED is Off!");
    }
  }
  delay(100);  // prepare for next input ...
}
