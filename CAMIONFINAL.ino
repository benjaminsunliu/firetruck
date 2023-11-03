#include <Servo.h>
#include "SR04.h"

//SENSORS:
#define waterlvl 46

#define flame1 A1
#define flame2 A3
#define flame3 A5

#define flame4 A9
#define flame5 A10
#define flame6 A7
#define flame7 A8
#define flame8 A6

#define trigF 29
#define echoF 23
#define trigL 33
#define echoL 31
#define trigR 37
#define echoR 27
#define trigB 25
#define echoB 35
SR04 sr04F = SR04(echoF, trigF);
SR04 sr04L = SR04(echoL, trigL);
SR04 sr04R = SR04(echoR, trigR);
SR04 sr04B = SR04(echoB, trigB);

//MOTORS:
#define enALB 5
#define in1LB 49
#define in2LB 51
#define in3RB 47
#define in4RB 45
#define enBRB 4

//PUMPS:
#define enAOUT 8
#define in1OUT 9
#define in2OUT 10
#define in3IN 11
#define in4IN 12
#define enBIN 3

//SERVO:
#define servopin 41
Servo wateraim;

//BUTTON:
#define fillbutton 13

//WATERLIGHTS:
#define led1 22
#define led2 24
#define led3 26
#define led4 28
#define led5 30
#define led6 32
#define led7 34
#define led8 36
#define led9 38
#define led10 40

//BUZZER: 
#define buzzerpin 39


void setup() {
  //Sensors:
  Serial.begin(2000000);
  pinMode(waterlvl, INPUT);
  pinMode(flame1, INPUT);
  pinMode(flame2, INPUT);
  pinMode(flame3, INPUT);
  pinMode(flame4, INPUT);
  pinMode(flame5, INPUT);
  pinMode(flame6, INPUT);
  pinMode(flame7, INPUT);
  pinMode(flame8, INPUT);

  //Motors:
  pinMode(enALB, OUTPUT);
  pinMode(in1LB, OUTPUT);
  pinMode(in2LB, OUTPUT);
  pinMode(in3RB, OUTPUT);
  pinMode(in4RB, OUTPUT);
  pinMode(enBRB, OUTPUT);

  analogWrite(enALB, 255);
  digitalWrite(in1LB, LOW);
  digitalWrite(in2LB, LOW);
  digitalWrite(in3RB, LOW);
  digitalWrite(in4RB, LOW);
  digitalWrite(enBRB, HIGH);

  //Pumps:
  pinMode(enAOUT, OUTPUT);
  pinMode(in1OUT, OUTPUT);
  pinMode(in2OUT, OUTPUT);
  pinMode(in3IN, OUTPUT);
  pinMode(in4IN, OUTPUT);
  pinMode(enBIN, OUTPUT);

  analogWrite(enAOUT, 255);
  digitalWrite(in1OUT, LOW);
  digitalWrite(in2OUT, LOW);
  digitalWrite(in3IN, LOW);
  digitalWrite(in4IN, LOW);
  digitalWrite(enBIN, HIGH);

  //Servo:
  wateraim.attach(servopin);

  //Button:
  pinMode(fillbutton, INPUT_PULLUP);

  //Waterlights:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  
  //Buzzer:
  pinMode(buzzerpin, OUTPUT);

}

//Motor functions:
void motorreset(){
  analogWrite(enALB, 255);
  digitalWrite(in1LB, LOW);
  digitalWrite(in2LB, LOW);
  digitalWrite(in3RB, LOW);
  digitalWrite(in4RB, LOW);
  digitalWrite(enBRB, HIGH);
}

void forward(){
  analogWrite(enALB, 255);
  digitalWrite(enBRB, HIGH);
  digitalWrite(in1LB, HIGH); //LEFT
  digitalWrite(in2LB, LOW); //LEFT
  digitalWrite(in3RB, HIGH); //RIGHT
  digitalWrite(in4RB, LOW); //RIGHT
}

void backward(){
  analogWrite(enALB, 255);
  digitalWrite(enBRB, HIGH);
  digitalWrite(in1LB, LOW); //LEFT
  digitalWrite(in2LB, HIGH); //LEFT
  digitalWrite(in3RB, LOW); //RIGHT
  digitalWrite(in4RB, HIGH); //RIGHT
  
}

void horaire(){
  analogWrite(enALB, 255);
  digitalWrite(enBRB, HIGH);
  digitalWrite(in1LB, HIGH); //LEFT
  digitalWrite(in2LB, LOW); //LEFT
  digitalWrite(in3RB, LOW); //RIGHT
  digitalWrite(in4RB, HIGH); //RIGHT
}

void antihoraire(){
  analogWrite(enALB, 255);
  digitalWrite(enBRB, HIGH);
  digitalWrite(in1LB, LOW); //LEFT
  digitalWrite(in2LB, HIGH); //LEFT
  digitalWrite(in3RB, HIGH); //RIGHT
  digitalWrite(in4RB, LOW); //RIGHT
}

void LF(){
  digitalWrite(in1LB, LOW); //LEFT
  digitalWrite(in2LB, HIGH); //LEFT
  digitalWrite(in3RB, HIGH); //RIGHT
  digitalWrite(in4RB, LOW); //RIGHT
  delay(700);
  analogWrite(enALB, 0);
  digitalWrite(enBRB, LOW);
}

void LB(){
  digitalWrite(in1LB, LOW); //LEFT
  digitalWrite(in2LB, HIGH); //LEFT
  digitalWrite(in3RB, HIGH); //RIGHT
  digitalWrite(in4RB, LOW); //RIGHT
  delay(1075);
  analogWrite(enALB, 0);
  digitalWrite(enBRB, LOW);

}

void B(){
  digitalWrite(in1LB, LOW); //LEFT
  digitalWrite(in2LB, HIGH); //LEFT
  digitalWrite(in3RB, HIGH); //RIGHT
  digitalWrite(in4RB, LOW); //RIGHT
  delay(1760);
  analogWrite(enALB, 0);
  digitalWrite(enBRB, LOW);
}

void RF(){
  digitalWrite(in1LB, HIGH); //LEFT
  digitalWrite(in2LB, LOW); //LEFT
  digitalWrite(in3RB, LOW); //RIGHT
  digitalWrite(in4RB, HIGH); //RIGHT
  delay(840);
  analogWrite(enALB, 0);
  digitalWrite(enBRB, LOW);
}

void RB(){
  digitalWrite(in1LB, HIGH); //LEFT
  digitalWrite(in2LB, LOW); //LEFT
  digitalWrite(in3RB, LOW); //RIGHT
  digitalWrite(in4RB, HIGH); //RIGHT
  delay(1340);
  analogWrite(enALB, 0);
  digitalWrite(enBRB, LOW);
}

void L(){
  digitalWrite(in1LB, LOW); //LEFT
  digitalWrite(in2LB, HIGH); //LEFT
  digitalWrite(in3RB, HIGH); //RIGHT
  digitalWrite(in4RB, LOW); //RIGHT
  delay(450);
  analogWrite(enALB, 0);
  digitalWrite(enBRB, LOW);
}

void R(){
  digitalWrite(in1LB, HIGH); //LEFT
  digitalWrite(in2LB, LOW); //LEFT
  digitalWrite(in3RB, LOW); //RIGHT
  digitalWrite(in4RB, HIGH); //RIGHT
  delay(450);
  analogWrite(enALB, 0);
  digitalWrite(enBRB, LOW);
}

void toflame(){
  digitalWrite(in1LB, HIGH); //LEFT
  digitalWrite(in2LB, LOW); //LEFT
  digitalWrite(in3RB, HIGH); //RIGHT
  digitalWrite(in4RB, LOW); //RIGHT
  delay(100);
  analogWrite(enALB, 0);
  digitalWrite(enBRB, LOW);
}

//Pump functions:
void shoot(){
  digitalWrite(in1OUT, LOW);
  digitalWrite(in2OUT, HIGH);
}

void stopshoot(){
  digitalWrite(in1OUT, LOW);
  digitalWrite(in2OUT, LOW);
}

void fill(){
  digitalWrite(in3IN, LOW);
  digitalWrite(in4IN, HIGH);
}

void stopfill(){
  digitalWrite(in3IN, LOW);
  digitalWrite(in4IN, LOW);
}

//Servo functions:
void servoreset(){
  wateraim.attach(servopin);
}

void aim(){
  int pos = 0;
  for (pos = 50; pos <= 100; pos += 1) { 

    wateraim.write(pos); 

    delay(10);  

  }

  for (pos = 100; pos >= 50; pos -= 1) { 

    wateraim.write(pos); 

    delay(10);

  }
  for (pos = 50; pos <= 100; pos += 1) { 

    wateraim.write(pos); 

    delay(10);  

  }

  for (pos = 100; pos >= 50; pos -= 1) { 

    wateraim.write(pos); 

    delay(10);

  }
  for (pos = 50; pos <= 100; pos += 1) { 

    wateraim.write(pos); 

    delay(10);  

  }

  for (pos = 100; pos >= 50; pos -= 1) { 

    wateraim.write(pos); 

    delay(10);

  }
  wateraim.detach();
}

//Buzzer:
void siren(){
  tone(buzzerpin, 1500);
  delay(1000);
  tone(buzzerpin, 700);
  delay(1000);
}
void stopsiren(){
  tone(buzzerpin, 0);
}

void loop() {
  //Sensors:
  int level = analogRead(waterlvl);

  int flameL = analogRead(flame1);
  int flameC = analogRead(flame2);
  int flameR = analogRead(flame3);

  int flameLF = analogRead(flame4);
  int flameLB = analogRead(flame5);
  int flameRF = analogRead(flame6);
  int flameRB = analogRead(flame7);
  int flameB = analogRead(flame8);

  int distF = sr04F.Distance();
  int distL = sr04L.Distance();
  int distR = sr04R.Distance();
  int distB = sr04B.Distance();

  //Valeurs de detections
  int threshold1 = 500; //Avant HIGHER = HARDER TO DETECT
  int threshold2 = 400; //Autres LOWER = HARDER TO DETECT

  //Water level lights
  if (level >= 1000){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    digitalWrite(led9, HIGH);
    digitalWrite(led10, HIGH);
  }

  else if (level >= 980){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    digitalWrite(led9, HIGH);
    digitalWrite(led10, HIGH);
  }

  else if (level >= 960){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    digitalWrite(led9, HIGH);
    digitalWrite(led10, HIGH);
  }
  else if (level >= 950){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    digitalWrite(led9, HIGH);
    digitalWrite(led10, HIGH);
  }
  else if (level >= 940){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    digitalWrite(led9, HIGH);
    digitalWrite(led10, HIGH);
  }
  else if (level >= 930){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    digitalWrite(led9, HIGH);
    digitalWrite(led10, HIGH);
  }
  else if (level >= 920){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    digitalWrite(led9, HIGH);
    digitalWrite(led10, HIGH);
  }
  else if (level >= 910){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, HIGH);
    digitalWrite(led9, HIGH);
    digitalWrite(led10, HIGH);
  }
  else if (level >= 900){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, HIGH);
    digitalWrite(led10, HIGH);
  }
  else{
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    digitalWrite(led10, HIGH);
  }

  //LOGIC:
  if (digitalRead(fillbutton) == 1){
    fill();
    delay(10000);
    stopfill();
  }

  if (flameC > threshold1){
    toflame();
    siren();
    shoot();
    aim();
    servoreset();
    aim();
    servoreset();
    aim();
    servoreset();
    delay(500);
    stopshoot();
    servoreset();
    motorreset();
    stopsiren();
  }
  else if (flameL > threshold1){
    siren();
    L();
    delay(100);
    motorreset();
    stopsiren();
  }
  else if (flameR > threshold1){
    siren();
    R();
    delay(100);
    motorreset();
    stopsiren();
  }
  else if (flameLF < threshold2){
    siren();
    LF();
    delay(100);
    if (flameC < threshold1 || flameL < threshold1 || flameR < threshold1){
      forward();
    }
    else{
    motorreset();
    }
    stopsiren();
  }
  else if (flameLB < threshold2){
    siren();
    LB();
    delay(100);
    if (flameC < threshold1 || flameL < threshold1 || flameR < threshold1){
      forward();
    }
    else{
    motorreset();
    }
    stopsiren();
  }
  else if (flameB < threshold2){
    siren();
    B();
    delay(100);
    if (flameC < threshold1 || flameL < threshold1 || flameR < threshold1){
      forward();
    }
    else{
    motorreset();
    }
    stopsiren();
  }
  else if (flameRF < threshold2){
    siren();
    RF();
    delay(100);
    if (flameC < threshold1 || flameL < threshold1 || flameR < threshold1){
      forward();
    }
    else{
    motorreset();
    }
    stopsiren();
  }
  else if (flameRB < threshold2){
    siren();
    RB();
    delay(100);
    if (flameC < threshold1 || flameL < threshold1 || flameR < threshold1){
      forward();
    }
    else{
    motorreset();
    }
    stopsiren();
  }
  if (distF < 5 || distL < 5 || distR < 5 || distB < 5){
    motorreset();
  }
}
