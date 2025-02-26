#include <SoftwareSerial.h>
SoftwareSerial BTserial(2,3);

#define ledPin 7
int state = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
Serial.begin(9600);
  BTserial.begin(9600); 
}

void loop() {
  if(BTserial.available() > 0){ 
    state = BTserial.read(); 
 }

 if (state == '0') {
  digitalWrite(ledPin, LOW); 
  Serial.println("LED: OFF"); 
  state = 1;
 }
 else if (state == '1') {
  digitalWrite(ledPin, HIGH);
  Serial.println("LED: ON");
  state = 0;
 } 
}
