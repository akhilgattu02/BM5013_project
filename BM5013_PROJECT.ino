#include<math.h>
int trig1=2,trig2=4,trig3=6;
int echo1=3,echo2=5,echo3=7;
int fsr1=A0,fsr2=A1,fsr3=A2,fsr4=A3;
int dist1,dist2,dist3;
int d1=-1,d2=-1,d3=-1;
float y1 = 14;
float y2 = 17.5;
long currentTime;
long count = 0;
float distance(int trig ,int echo){
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  long t=pulseIn(echo,HIGH);
  float d=t*(0.034)/2;
  return d;
}

float angle(float x1,float x2,float y){
  float theta=atan(y/x2-x1);
}

bool isInCorrectPosture(int di1, int di2, int di3)
{
  if(di1==-1 || di2==-1 || di3==-1){
    return true;
  }
}

void assignDistance(int dist,int &d){
  if(dist<=50){
    d=dist;
  }
  else{
    d=-1;
  }
}

void setup() {
 pinMode(trig1,OUTPUT);
 pinMode(trig2,OUTPUT);
 pinMode(trig3,OUTPUT);
 pinMode(echo1,INPUT);
 pinMode(echo2,INPUT);
 pinMode(echo3,INPUT);
 Serial.begin(115200);
 currentTime=millis();
}

void loop() {
  int f1=analogRead(fsr1);
  int f2=analogRead(fsr2);
  int f3=analogRead(fsr3);
  int f4=analogRead(fsr4);
  Serial.println("Force 1");
  Serial.println(f1);
  Serial.println("Force 2");
  Serial.println(f2);
  Serial.println("Force 3");
  Serial.println(f3);
  Serial.println("Force 4");
  Serial.println(f4);
  dist1=distance(trig1,echo1);
  assignDistance(dist1,d1);
  dist2=distance(trig2,echo2);
  assignDistance(dist2,d2);
  dist3=distance(trig3,echo3);
  assignDistance(dist3,d3);
  Serial.println("Sensor 1");
  Serial.println(d1);
  Serial.println("Sensor 2");
  Serial.println(d2);
  Serial.println("Sensor 3");
  Serial.println(d3);
 if(f1>900 or f2>900 or f3>900 or f4>900){
    Serial.println("Objected Detected");
   if(d1==-1 and d2==-1 or d1==-1 and d3==-1 or d2==-1 and d3==-1){
      Serial.println("Incorrect Posture");
   }
   else{
     Serial.println("Correct Posture");
  }
 }
 else{
    Serial.println("No Object Detected");
 }
  delay(1000);
}
