 #include <SoftwareSerial.h>
 #include <Servo.h>
SoftwareSerial GPRS(9, 10);
Servo myservo; 
const int trigPin =11;
const int echoPin = 12;
double AVG; 
double distance;
void setup()
{
  GPRS.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);
  myservo.attach(12);// Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
  AVG=0;
}
String msg;
int i ,pos=0;
void loop(){
  if (GPRS.available()>0){
     msg = GPRS.readString();
    Serial.print(msg);    
    delay(10);  
 if(msg.indexOf("Close")>=0)
    closeTank(); 
  if(msg.indexOf("Open")>=0)
      openTank();
   }
}
void closeTank(){
  myservo.write(90);
  Serial.print(" Fuel Tank Has been Locked \n");
}
void openTank(){
  myservo.write(0);
   Serial.print(" Fuel Tank Has been Unlocked \n");
}
double fuel_level(){
  int i;
  int no_of_experiments = 50;
  long duration[50];
  long variance[
  for(i=0;i<no_of_experiments;i++){
    
  }
}
 void loop(){
  i=i+1;
  digitalWrite(trigPin ,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  duration = pulseIn(echoPin,HIGH);
  distance = duration*0.034/2;
  if(i<=n){
  AVG=(AVG+distance/n);
  Serial.print("Distance(in cm): ");
  Serial.println(distance);
  if(i==n){
    Serial.println(AVG);
  }
  }
  }
