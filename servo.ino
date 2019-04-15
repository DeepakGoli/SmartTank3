#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int incomingByte = 0;   // for incoming serial data

void setup() {
  Serial.begin(9600);
  myservo.attach(12);  // attaches the servo on pin 9 to the servo object
}
int x;
void loop() {
  if(Serial.available()){
   x=Serial.read();
   if(x=='0'){ 
        myservo.write(135); 
        delay(500);
   }
   if(x=='1'){
     myservo.write(30);
     delay(500);
   }
  }
} 

