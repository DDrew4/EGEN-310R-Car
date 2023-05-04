#include<SoftwareSerial.h>

SoftwareSerial bt(2,3);

void setup() {
  // put your setup code here, to run once:
  bt.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(";");
  if(bt.available())
  {
    Serial.write(bt.read());
    Serial.println("pop");
  }
}
