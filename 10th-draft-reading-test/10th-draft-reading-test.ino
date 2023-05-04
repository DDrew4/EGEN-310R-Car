
#define ledPin 7
int state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
digitalWrite(ledPin, LOW);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    state = Serial.read();
  }
  if (state == '0') {
    digitalWrite(ledPin, LOW);
    Serial.println("LED: OFF");
    state = 0;
  }
  else if (state == '1') {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED: ON");
    state = 0;
  }
}
