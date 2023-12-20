#include <LiquidCrystal.h>

int counter1 = 20;
int counter2 = 40;
int counter3 = 60;
char s1 = 'g';
char s2 = 'y';
char s3 = 'r';
const int trig1 = 2, echo1 = 3, rs1 = 1, en1 = 2, d41 = 4, d51 = 5, d61 = 6, d71 = 7;
const int trig2 = 4, echo2 = 5, rs2 = 14, en2 = 30, d42 = 22, d52 = 24, d62 = 26, d72 = 28;
const int trig3 = 6, echo3 = 7, rs3 = 16, en3 = 40, d43 = 32, d53 = 34, d63 = 36, d73 = 38;

LiquidCrystal lcd1(rs1, en1, d41, d51, d61, d71);
LiquidCrystal lcd2(rs2, en2, d42, d52, d62, d72);
LiquidCrystal lcd3(rs3, en3, d43, d53, d63, d73);

void setup() {
  lcd1.begin(16, 2); lcd2.begin(16, 2);
  pinMode(trig1, OUTPUT); pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT); pinMode(echo2, INPUT);
  pinMode(trig3, OUTPUT); pinMode(echo3, INPUT);
}

void loop(){
  float dist1 = measureDistance(trig1, echo1);
  float dist2 = measureDistance(trig2, echo2);
  float dist3 = measureDistance(trig3, echo3);

  lcd1.setCursor(0, 0); lcd1.print("Sensor 1:"); lcd1.print(dist1); lcd1.print(" cm");
  lcd2.setCursor(0, 0); lcd2.print("Sensor 2:"); lcd2.print(dist2); lcd2.print(" cm");
  lcd3.setCursor(0, 0); lcd3.print("Sensor 3:"); lcd3.print(dist3); lcd3.print(" cm");

  if(counter1==0){
    s1 = state(s1);
  }else if (counter2==0)
  {
    s2 = state(s2);
  }else if (counter3==0)
  {
    s3 = state(s3);
  }

  if(dist1<=50 || dist2<=50 || dist3<=50){
    // counter1 = counter1 - 5;
    // counter2 = counter2 - 5;
    // counter3 = counter3 - 5;
    delay(500);
  }else{
    delay(1000);
  }
}

float measureDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW); delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH); delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

char state(char s){
    if(s == 'g'){
        s = 'y';
    }
    else if (s == 'y')
    {
        s = 'r';
    }
    else if (s == 'r')
    {
        s = 'g'
    }   
    return s
}
