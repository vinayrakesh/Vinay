
#include <LiquidCrystal.h>
LiquidCrystal LCD(10, 9, 5, 4, 3, 2);
int trigPin=13; //trig pin connected to arduino 13
int echoPin=11; //Echo pin connected to arduino 11
int myCounter=0;
int servoControlPin=6;
float pingTime;
float targetDistance;
float speedOfSound=776.5;
void setup()
{
Serial.begin(9600);
pinMode(trigPin, OUTPUT); //Trig pin connected to output
pinMode(echoPin, INPUT);  //echo pin to input
LCD.begin(16,2);
LCD.setCursor(0,0);
LCD.print("Distance :"); //print distance in LCD
}
void loop()
{
digitalWrite(trigPin, LOW);
delayMicroseconds(20); digitalWrite(trigPin, HIGH); delayMicroseconds(10); digitalWrite(trigPin, LOW); delayMicroseconds(10);
pingTime = pulseIn(echoPin, HIGH);
pingTime=pingTime/1000000; pingTime=pingTime/3600;
targetDistance= speedOfSound * pingTime;
targetDistance=(targetDistance/2);
targetDistance= targetDistance*63360;
  LCD.setCursor(0,1);
  LCD.print("                ");
  LCD.setCursor(0,1);
  LCD.print("  inch: ");
  LCD.print(targetDistance);
}
 
