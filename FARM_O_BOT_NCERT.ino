
#include <Stepper.h>
const int stepsPerRevolution = 200;  
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
int stepCount = 0;  

#include <SoftwareSerial.h>
#include <Servo.h> 
Servo myservo1, myservo2 ;
int bluetoothTx = 0;
int bluetoothRx = 1;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
char x;
void setup(){
  myservo1.attach(2);
  myservo2.attach(3);
  pinMode(4,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);}
void loop(){
  if(bluetooth.available()>= 2 ){
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1 *256) + servopos; 
    Serial.println(realservo); 
    if (realservo >= 1000 && realservo <1180){
    int servo1 = realservo;
    servo1 = map(servo1, 1000,1180,0,180);
    myservo1.write(servo1);
    Serial.println("servo 1 ON");
    delay(10); }
    if (realservo >=2000 && realservo <2180){
    int servo2 = realservo;
    servo2 = map(servo2,2000,2180,0,180);
    myservo2.write(servo2);
    Serial.println("servo 2 On");
    delay(10);}}
{
   if(bluetooth.available()>= 0 ){
x=bluetooth.read();
 Serial.println(x);
     if(x== 'L' ){
  digitalWrite(4,HIGH);
}
if(x== 'R' ){
  digitalWrite(6,HIGH);
  }
if(x== 'S' ){
  digitalWrite(4,LOW);
  digitalWrite(6,LOW);
}
if(x== 'T' ){
 Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);
  }
  
  }}}
