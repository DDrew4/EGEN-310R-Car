int R_IS = 22;
int R_EN = 24;
int R_PWM = 3;
int L_IS = 23;
int L_EN = 25;
int L_PWM = 5;

int TR_IS = 27;  //T indicates top motor
int TR_EN = 29;
int TR_PWM = 6;
int TL_IS = 26;
int TL_EN = 28;
int TL_PWM = 7;

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


int count;

// Include iBusBM Library
#include <IBusBM.h>
#include <DRV8835MotorShield.h>
#include <Servo.h>

// Create iBus Object
IBusBM ibus;

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
  // Start serial monitor
  Serial.begin(9600);

  // Attach iBus object to serial port
  //ibus.begin(Serial1);

  // Lower Moter
  pinMode(R_IS, OUTPUT);
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
}

void loop() {


  // Cycle through first 5 channels and determine values
  // Print values to serial monitor
  // Note IBusBM library labels channels starting with "0"

  for (byte i = 0; i < 10; i++) {
    int value = readChannel(i, -100, 100, 0);
    channelArray[i] = value;
    ///*

    Serial.print("Ch");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(value);
    Serial.print(" | ");
    //*/
  }

  //Drive Control---------

  /* Channel Check
  for(int j=0; j<10; j++){
    //Serial.print(channelArray[j]);
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

  /*
  vertical = 100; 
  if(count > 100){
    vertical = -100; 
  }
  */

  topSpeed = (140 - minValue) + channelArray[5];  //50 to 250 range

  //Acceleration control
  if (currentVertical < vertical) {
    if ((vertical - currentVertical) < acceleration) {
      currentVertical += (vertical - currentVertical);
    } else {
      currentVertical += acceleration;
    }
  } else if (currentVertical > vertical) {
    if ((vertical - currentVertical) > acceleration) {
      currentVertical -= (vertical - currentVertical);
    } else {
      currentVertical -= acceleration;
    }
  }

  //UP
  if (currentVertical >= 0) {
    //left
    if (horizontal <= 0) {
      rightTrack = topSpeed * (((horizontal / -2) + (currentVertical * (100 - (horizontal / -2))) / 100) / 100);
      leftTrack = topSpeed * ((currentVertical + (horizontal / 2)) / 100);
    }

    //right
    else if (horizontal > 0) {
      rightTrack = topSpeed * ((currentVertical + (-1 * horizontal / 2)) / 100);
      leftTrack = topSpeed * (((horizontal / 2) + (currentVertical * (100 - (horizontal / 2))) / 100) / 100);
    }
  }

  //DOWN
  else if (currentVertical < 0) {
    //left
    if (horizontal <= 0) {
      rightTrack = -1 * topSpeed * (((horizontal / -2) - (currentVertical * (100 - (horizontal / -2))) / 100) / 100);
      leftTrack = topSpeed * ((currentVertical - (horizontal / 2)) / 100);
    }

    //right
    else if (horizontal > 0) {
      rightTrack = topSpeed * ((currentVertical - (-1 * horizontal / 2)) / 100);
      leftTrack = -1 * topSpeed * (((horizontal / 2) - (currentVertical * (100 - (horizontal / 2))) / 100) / 100);
    }
  }

  /*
  Serial.print("Left: ");
  Serial.print(leftTrack); 
  Serial.print(" Right: ");
  Serial.print(rightTrack); 
  */

  /*
  right track
  speed1 = negative
  speed2 = positive
  left track   
  speed3 = negative
  speed4 = positive
  */

  //Turn track values into speed values
  if (rightTrack < 0) {
    speed1 = ((rightTrack * -1) + minValue);
    speed2 = 0;
  } else if (rightTrack > 0) {
    speed1 = 0;
    speed2 = (rightTrack + minValue) * (1 - veer);
  } else {
    speed1 = 0;
    speed2 = 0;
  }

  if (leftTrack < 0) {
    speed3 = (leftTrack * -1) + minValue;
    speed4 = 0;
  } else if (leftTrack > 0) {
    speed3 = 0;
    speed4 = leftTrack + minValue;
  } else {
    speed3 = 0;
    speed4 = 0;
  }

  //if going from + to - or - to + motor values single cycle is 0,0
  //if right negative    right postive    right positive      right negative
  if (((speed1Past > 0) && (speed2 > 0)) || ((speed2Past > 0) && (speed1 > 0))) {
    speed1 = 0;
    speed2 = 0;
  }
  if (((speed3Past > 0) && (speed4 > 0)) || ((speed4Past > 0) && (speed3 > 0))) {
    speed3 = 0;
    speed4 = 0;
  }


  //DRIVE PINS

  analogWrite(R_PWM, speed1);
  analogWrite(L_PWM, speed2);
  //Upper Motor
  analogWrite(TR_PWM, speed3);
  analogWrite(TL_PWM, speed4);

  /*
  Serial.print("speed1 ");
  Serial.print(speed1);
  Serial.print(" speed2 ");
  Serial.print(speed2);
  Serial.print(" speed3 ");
  Serial.print(speed3);
  Serial.print(" speed4 ");
  Serial.print(speed4);  
  */

  //Save speed values
  speed1Past = speed1;
  speed2Past = speed2;
  speed3Past = speed3;
  speed4Past = speed4;

  Serial.println();
  count += 1;
  //Serial.print(count);
  delay(1);
}
