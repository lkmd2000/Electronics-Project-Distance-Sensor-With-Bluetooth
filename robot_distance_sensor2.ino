#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

// defines pins numbers
const int echoPin = 8;
const int trigPin = 9;
// defines variables
long distance;
long duration;
int servoPos = 90;

 
void setup() 
{
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
  
Serial.begin(9600);
  
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
  
servo1.attach(7); 
servo2.attach(6); 
servo3.attach(5); 
servo4.attach(4); 
servo5.attach(3); 
servo6.attach(2); 
  
}
 
void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(3000000);
    
digitalWrite(trigPin, HIGH);
delayMicroseconds(3000000);
digitalWrite(trigPin, LOW);
   
duration = pulseIn(echoPin, HIGH);
    
distance= duration*0.034/2;
   delay(3000);

  
ultra();
  servo6.write(0);
  servo5.write(0);
  servo4.write(0);
  servo3.write(0);
  servo2.write(0);
  servo1.write(0);
  
if(distance <= 15){
  servo6.write(60);
  servo5.write(60);
  servo4.write(60);
  servo3.write(60);
  servo2.write(60);
  servo1.write(60);
delay(2000);
}
else if(distance <= 10){
  servo6.write(120);
  servo5.write(120);
  servo4.write(120);
  servo3.write(120);
  servo2.write(120);
  servo1.write(120);
delay(1000);
}
else if(distance <= 5){
  servo6.write(0);
  servo5.write(0);
  servo4.write(0);
  servo3.write(0);
  servo2.write(0);
  servo1.write(0);
delay(2000);
} 
} 
void ultra(){
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration*0.034/2;

}