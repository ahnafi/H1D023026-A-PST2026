#include <Arduino.h>
#include <Servo.h>

Servo myservo;

const int servoPin = 4;
const int btnPin = 3;
const int ledPin = 2;

void setup(){
  myservo.attach(servoPin);
  pinMode(ledPin,OUTPUT);
  pinMode(btnPin,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop(){

// statbe button
bool valueBtn = digitalRead(btnPin);

// ketika button ditekan dia posisi LOW 
// ketika button dilepas dia posisi HIGH
  if(valueBtn == LOW){
    myservo.write(90);
    Serial.println("DRS: ACTIVE");
    digitalWrite(ledPin,HIGH);
  }else{
    myservo.write(0);
    Serial.println("DRS: CLOSED");
    digitalWrite(ledPin,LOW);
  }

  delay(20);

}