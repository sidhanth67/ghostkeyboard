// C++ code
//
int echo_left = 9;
int echo_right = 6;
int trig_left = 8;
int trig_right = 5;
int i; // for the for loop
int butt_blue = 10;
int butt_red = 11;
int butt_white = 12;
bool state_blue = LOW;
bool state_red = LOW;
bool state_white = LOW;
bool laststate_blue = LOW;
bool laststate_red = LOW;
bool laststate_white = LOW;
int cnt = 1; //handles alternating loop error
void detection1(float);
void detection2(float);
void detection3(float);
void detection4(float);
#include <math.h>


void setup() {

  pinMode(trig_left, OUTPUT);
  pinMode(trig_right, OUTPUT);
  pinMode(echo_left, INPUT);
  pinMode(echo_right, INPUT);

  pinMode(butt_blue, INPUT);
  pinMode(butt_red, INPUT);
  pinMode(butt_white, INPUT);
  digitalWrite(trig_left, LOW);
  digitalWrite(trig_right, LOW);
  delayMicroseconds(10);
  Serial.begin(9600);
}

void loop() {


  float total_distance_right=0;
  float total_distance_left=0;
  float avg_distance_left;
  float avg_distance_right;
  int buttstate_blue = digitalRead(butt_blue);
  int buttstate_red = digitalRead(butt_red);
  int buttstate_white = digitalRead(butt_white);



if (laststate_blue==HIGH && buttstate_blue==LOW ) {
    state_blue = !state_blue;
    state_red = LOW;
    state_white = LOW;
    }

else if (laststate_white==HIGH && buttstate_white==LOW ) {
    state_white = !state_white;
    state_red = LOW;
    state_blue = LOW;
    }

else if (laststate_red==HIGH && buttstate_red==LOW ) {
    state_red = !state_red;
    state_blue = LOW;
    state_white = LOW;
    }
  
  

//------------------------------------------------------AVERAGING THE DISTANCE FOR KEY-----------------------------------------------------------

// for(i=0;i<20;i++){
//   digitalWrite(trig_left, LOW);
//   digitalWrite(trig_right,LOW);
//   delay(50);
//   digitalWrite(trig_left, HIGH);
//   digitalWrite(trig_right,HIGH);
//   delay(50);
//   digitalWrite(trig_left, LOW);
//   digitalWrite(trig_right,LOW);
//   float duration_left = pulseIn(echo_left, HIGH, 20000);
//   float duration_right = pulseIn(echo_right, HIGH, 20000);
//   float distance_left = (duration_left * 0.0343) / 2;
//   float distance_right = (duration_right * 0.0343) / 2;
//   if (cnt % 2 == 0) {
//     Serial.println(distance_left);
//     Serial.println(distance_right);
//     total_distance_left=total_distance_left+distance_left;
//     total_distance_right=total_distance_right + distance_right;
//   }
//   cnt++;
//   }
for(i=0;i<20;i++){
  digitalWrite(trig_right, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_right,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_right,LOW);
  float duration_right = pulseIn(echo_right, HIGH, 20000);
  delay(60);
  float distance_right = (duration_right * 0.0343) / 2;
  if (cnt % 2 == 0 && distance_right <= 17 ) {
    total_distance_right=total_distance_right + distance_right;
  }
  cnt++;
  }

for(i=0;i<20;i++){
  digitalWrite(trig_left, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_left,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_left,LOW);
  float duration_left = pulseIn(echo_left, HIGH, 20000);
  delay(60);
  float distance_left = (duration_left * 0.0343) / 2;
  if (cnt % 2 == 0 && distance_left <= 17) {
    total_distance_left=total_distance_left + distance_left;
  }
  cnt++;
  }
//-----------------------------------------------------------------------------------------------------------------------------------------------
  avg_distance_right=total_distance_right/10.0;
  avg_distance_left=total_distance_left/10.0;
  //detection(avg_distance);
  
  if (state_blue == LOW && state_white == LOW && state_red == LOW) {
    detection1(avg_distance_left,avg_distance_right);
  } 
  else if (state_blue == HIGH && state_white == LOW && state_red == LOW) {
    detection2(avg_distance_left,avg_distance_right);
  }
  else if (state_blue == LOW && state_white == HIGH && state_red == LOW) {
    detection4(avg_distance_left,avg_distance_right);
  }
  else if (state_blue == LOW && state_white == LOW && state_red == HIGH) {
    detection3(avg_distance_left,avg_distance_right);
  }


laststate_blue = buttstate_blue;
laststate_red = buttstate_red;
laststate_white = buttstate_white;
  
}


void detection1(float dist_left,float dist_right){
  if (fabs(dist_left - 4) < 0.8) {
   Serial.print("A");
  } else if (fabs(dist_left - 7) < 0.8) {
   Serial.print("B");
  } else if (fabs(dist_left - 10) < 0.8) {
   Serial.print("C");
  } else if (fabs(dist_left - 13) < 0.8) {
   Serial.print("D");
  } else if (fabs(dist_left - 16) < 0.8) {
   Serial.print("E");
  }
  if (fabs(dist_right - 4) < 0.8) {
   Serial.print("P");
  } else if (fabs(dist_right - 7) < 0.8) {
   Serial.print("Q");
  } else if (fabs(dist_right - 10) < 0.8) {
   Serial.print("R");
  } else if (fabs(dist_right - 13) < 0.8) {
   Serial.print("S"); 
  } else if (fabs(dist_right - 16) < 0.8) {
   Serial.print("T"); 
  }
}

void detection2(float dist_left,float dist_right){
  if (fabs(dist_left - 4) < 0.8) {
   Serial.print("F");
  } else if (fabs(dist_left - 7) < 0.8) {
   Serial.print("G");
  } else if (fabs(dist_left - 10) < 0.8) {
   Serial.print("H");
  } else if (fabs(dist_left - 13) < 0.8) {
   Serial.print("I");
  } else if (fabs(dist_left - 16) < 0.8) {
   Serial.print("J");
  }
  if (fabs(dist_right - 4) < 0.8) {
   Serial.print("U");
  } else if (fabs(dist_right - 7) < 0.8) {
   Serial.print("V");
  } else if (fabs(dist_right - 10) < 0.8) {
   Serial.print("W");
  } else if (fabs(dist_right - 13) < 0.8) {
   Serial.print("X");
  } else if (fabs(dist_right - 16) < 0.8) {
   Serial.print("Y");
  }
}

void detection3(float dist_left,float dist_right){
  if (fabs(dist_left - 4) < 0.8) {
   Serial.print("K");
  } else if (fabs(dist_left - 7) < 0.8) {
   Serial.print("L");
  } else if (fabs(dist_left - 10) < 0.8) {
   Serial.print("M");
  } else if (fabs(dist_left - 13) < 0.8) {
   Serial.print("N");
  } else if (fabs(dist_left - 16) < 0.8) {
   Serial.print("O");
  }
  if (fabs(dist_right - 4) < 0.8) {
   Serial.print("Z");
  } else if (fabs(dist_right - 7) < 0.8) {
   Serial.print(" ");
  } else if (fabs(dist_right - 10) < 0.8) {
   Serial.print(".");
  } else if (fabs(dist_right - 13) < 0.8) {
   Serial.print(",");
  } else if (fabs(dist_right - 16) < 0.8) {
   Serial.print(";");
  }
}

void detection4(float dist_left,float dist_right){
  if (fabs(dist_left - 4) < 0.8) {
   Serial.print("0");
  } else if (fabs(dist_left - 7) < 0.8) {
   Serial.print("1");
  } else if (fabs(dist_left - 10) < 0.8) {
   Serial.print("2");
  } else if (fabs(dist_left - 13) < 0.8) {
   Serial.print("3");
  } else if (fabs(dist_left - 16) < 0.8) {
   Serial.print("4");
  }
  if (fabs(dist_right - 4) < 0.8) {
   Serial.print("5");
  } else if (fabs(dist_right - 7) < 0.8) {
   Serial.print("6");
  } else if (fabs(dist_right - 10) < 0.8) {
   Serial.print("7");
  } else if (fabs(dist_right - 13) < 0.8) {
   Serial.print("8");
  } else if (fabs(dist_right - 16) < 0.8) {
   Serial.print("9");
  }
}
