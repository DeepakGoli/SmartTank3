const int trigPin = 9;
const int echoPin = 10;
long duration;
double distance;

void setup(){
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
}
 void loop(){
  digitalWrite(trigPin ,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  duration = pulseIn(echoPin,HIGH);
  distance = duration*0.034/2;
  Serial.print("Distance(in cm): ");
  Serial.println(distance);
  }

