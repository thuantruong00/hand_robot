#include <Servo.h>
//
Servo svx1;
Servo svx2;
Servo svx3;
Servo svx4;
Servo svx5;
Servo rot0;

int p8 = 8;
int p9 = 9;
int p10 = 10;
int p11 = 11;
int p12 = 12;
int p13 = 13;

int valF = 0;
int i=0; 
int ctr = 0;
String str;
String temp0;
int tempi;

        
void setup() {
  Serial.begin(9600);
//  sv.attach(sv08);  // attaches the servo on pin 9 to the servo object
  svx1.attach(p8);
  svx2.attach(p9);
  svx3.attach(p11);
  svx4.attach(p10);
  svx5.attach(p12);
  rot0.attach(p13);
  rot0.write(90);
  tempi = 200;

}


int ctrlServo(int temp){
  Serial.print("temp- ");
  Serial.println(temp);
  int valFi = checkPos();
  Serial.print("F ");
  Serial.println(valFi);
  if(valFi > temp + 50){
    svx4.write(111);
    Serial.println("111");
    delay(100);
    svx4.write(90);
  }
  if(valFi < temp - 50){
    svx4.write(0);
    Serial.println("0");
    delay(100);
    svx4.write(90);
  }

  delay(20);
  return ;
}
int checkPos(){
  int val = analogRead(A1);
  Serial.print("F ");
  Serial.println(val);
  return val;
}



void loop() {

if(Serial.available()>0){
  str = Serial.readString();
  Serial.println(str);
  str.toCharArray(1,1);
  temp0 = str;
  tempi = temp0.toInt();
}
valF = checkPos();
if((valF >= tempi+30) || (valF <= tempi-30)){
  ctrlServo(tempi);
}
else{
  svx4.write(90);
}
delay(500);
}
