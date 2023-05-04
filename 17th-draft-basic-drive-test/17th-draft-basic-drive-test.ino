#include <DRV8835MotorShield.h>

int dir1 = 7;
int dir2 = 8;

int spd1 = 9;
int spd2 = 10;



void setup() {
  // put your setup code here, to run once:
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(spd1, OUTPUT);
  pinMode(spd2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dir1, 1);
  digitalWrite(spd1, HIGH);
  digitalWrite(dir2, 1);
  digitalWrite(spd2, HIGH);
  delay(2000);
  digitalWrite(dir1, 1);
  digitalWrite(spd1, LOW);
  digitalWrite(dir2, 1);
  digitalWrite(spd2, LOW);
  delay(2000000);
}
