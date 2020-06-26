#include<Servo.h>

int servoPin = 11;
int writeVal;
int readVal1;
int readVal2;
int readPin1 = A0;    //left sensor
int readPin2 = A5;    //right sensor
int i=0;

Servo myservo;
void setup(){
  Serial.begin(9600);
  pinMode(readPin1, INPUT);
  pinMode(readPin2, INPUT);
  myservo.attach(11);
  Serial.begin(9600);
}

void loop(){
  readVal1 = analogRead(readPin1);
  readVal2 = analogRead(readPin2);
  Serial.print(readVal2);
  Serial.print(" ");
  Serial.println(readVal1);
  if(readVal2+20<readVal1){
    i-=2;
    myservo.write(i);
    delay(50);
  }
  else if(readVal1+20<readVal2){
    i+=2;
    myservo.write(i);
    delay(50);
  }
}
