#include <Servo.h>
//
Servo sv;
int i=0; 
int ctr = 0;
String str;
int sv08 = 8;
        
void setup() {
  Serial.begin(9600);
  sv.attach(sv08);  // attaches the servo on pin 9 to the servo object
  pinMode(OUTPUT,13);

}


int svrun(int o){
  sv.write(o);
  delay(500);
  sv.write(90);
  return ;
}

void loop() {


if(Serial.available()>0){
  str = Serial.readString();
  ctr = str.toInt();
//  blinkled(ctr);
  svrun(ctr);
  Serial.println(ctr);
  
}

//svrun(1);
//sv.write(1);
//delay(2000);
      
//for(i=0;i<180;i+=1){
//  sv.write(i); 
//  delay(30);
//}
//delay(500);
//for(i=180;i>0;i-=1){
//  sv.write(i); 
//  delay(30);
//}


  
} 
