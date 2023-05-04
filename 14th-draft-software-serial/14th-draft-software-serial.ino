#include <SoftwareSerial.h>
#include <IBusBM.h>
#include <DRV8835MotorShield.h>
#include <Servo.h>

//const byte rxPin = 3;
//const byte txPin = 2;
//SoftwareSerial Cereal(rxPin, txPin);
SoftwareSerial Cereal(3, 2);

int dir1 = 7;
int dir2 = 8;
int spd1 = 9;
int spd2 = 10;

Servo Aservo;  // create servo object to control a servo
Servo Lservo;

int pos = 0;  // variable to store the servo position

IBusBM ibus;  // Create iBus Object

/*
//int R_IS = 22;
//int R_EN = 24;
int R_PWM = 3;
//int L_IS = 23;
//int L_EN = 25;
int L_PWM = 5;

//int TR_IS = 27;  //T indicates top motor
//int TR_EN = 29;
int TR_PWM = 6;
//int TL_IS = 26;
//int TL_EN = 28;
int TL_PWM = 7;
*/

int speed = 60;
int T_SPEED;
int B_SPEED;

int speed1;
int speed2;
int speed3;  //3 and 4 are used for turning
int speed4;

//past speed values
int speed1Past;
int speed2Past;
int speed3Past;
int speed4Past;

bool on1 = false;
bool on2 = false;

int channelArray[6];
double vertical;
double horizontal;
double rightTrack;
double leftTrack;
double currentVertical = 0;

double topSpeed;
double veer = 0.04;       //- for left veer + for right
double acceleration = 3;  //vertical decrease per cycle
double minValue = 20;



// Read the number of a given channel and convert to the range provided.
// If the channel is off, return the default value
int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue) {
  uint16_t ch = ibus.readChannel(channelInput);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}

// Read the channel and return a boolean value
bool readSwitch(byte channelInput, bool defaultValue) {
  int intDefaultValue = (defaultValue) ? 100 : 0;
  int ch = readChannel(channelInput, 0, 100, intDefaultValue);
  return (ch > 50);
}


void setup() {
  
  Serial.begin(9600);
  Serial.println("Hello World");
  Cereal.begin(9600);
  //while(!Serial){
  //Cereal.println("Goodnight Moon");
  //}

  Aservo.attach(5);
  Lservo.attach(11);

  /*pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);*/
  pinMode(3, INPUT);
  pinMode(2, OUTPUT);

  // Attach iBus object to serial port
  ibus.begin(Serial);

  // Lower Moter
  /*pinMode(R_IS, OUTPUT);
  pinMode(R_EN, OUTPUT);
  pinMode(R_PWM, OUTPUT);
  pinMode(L_IS, OUTPUT);
  pinMode(L_EN, OUTPUT);
  pinMode(L_PWM, OUTPUT);
  digitalWrite(R_IS, LOW);
  digitalWrite(L_IS, LOW);
  digitalWrite(R_EN, HIGH);
  digitalWrite(L_EN, HIGH);


  //Upper Motor
  pinMode(TR_IS, OUTPUT);
  pinMode(TR_EN, OUTPUT);
  pinMode(TR_PWM, OUTPUT);
  pinMode(TL_IS, OUTPUT);
  pinMode(TL_EN, OUTPUT);
  pinMode(TL_PWM, OUTPUT);
  digitalWrite(TR_IS, LOW);
  digitalWrite(TL_IS, LOW);
  digitalWrite(TR_EN, HIGH);
  digitalWrite(TL_EN, HIGH);
*/


  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(spd1, OUTPUT);
  pinMode(spd2, OUTPUT);
}


void loop() {
  
  // Cycle through first 5 channels and determine values
  // Print values to serial monitor
  // Note IBusBM library labels channels starting with "0"

  while (Cereal.available() > 0) {
    char inByte = Cereal.read();
    Serial.write(inByte);
  }
  /*for (byte i = 0; i < 4; i++) {
    int value = readChannel(i, -100, 100, 0);
    //channelArray[i] = value;
    Cereal.print("Ch");
    Cereal.print(i + 1);
    Cereal.print(": ");
    Cereal.print(value);
    Cereal.print(" | ");
  }*/

  //Drive Control---------

  /* Channel Check
  for(int j=0; j<10; j++){
    //Cereal.print(channelArray[j]);
  }
  */
  /*
  channelArray[0] horizontal right
  channelArray[1] vertical right
  channelArray[2] vertical left
  channelArray[3] horizontal left 
  channelArray[4] left knob
  channelArray[5] right knob 
  channelArray[6] switch a
  channelArray[7] switch b 
  channelArray[8] switch c (-100,0,100)
  channelArray[9] switch d 
  */

  horizontal = channelArray[0];
  vertical = channelArray[1];




  //Cereal.println();
  /*count += 1;
  //Cereal.print(count);
  delay(1);*/
}
