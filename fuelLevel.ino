 #include <SoftwareSerial.h>
const int trigPin =11;
const int echoPin = 12;
void setup() {
  // put your setup code here, to run once:
    pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   
}

double fuel_level(){
  double distance[20];
  double mean=0;
  double duration=0;
  double avg_distance=0;
  int i;
  for(i=0;i<20;i++){
    digitalWrite(trigPin ,LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(15);
    duration = pulseIn(echoPin,HIGH);
    distance[i] = duration*0.034/2;
    mean = mean+distance[i]/20;
  }
  int j=0;
  for(i=0;i<20;i++){
    double squaredError=(distance[i]-mean)*(distance[i]-mean);
    if(squaredError <=4){
      j=j+1;
      avg_distance = avg_distance+distance[i];
    }
  }
  avg_distance=avg_distance/j;
}

