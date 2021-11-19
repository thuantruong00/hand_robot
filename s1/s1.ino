#include <Servo.h>
//
Servo svx1;
Servo svx2;
Servo svx3;
Servo svx4;
Servo svx5;
Servo svx6;

int i=0; 
int ctr = 0;
String str;

int p8 = 8;
int p9 = 9;
int p10 = 10;
int p11 = 11;
int p12 = 12;
int p13 = 13;
        
void setup() {
  Serial.begin(9600);
//  sv.attach(sv08);  // attaches the servo on pin 9 to the servo object
  svx1.attach(p8);
  svx2.attach(p9);
  svx3.attach(p10);
  svx4.attach(p11);
  svx5.attach(p12);
  svx6.attach(p13);
  svx6.write(0);
}



int svrun1(String o, String otime){
  if(o.toInt()>0){
    svx1.write(111);
  }
  else{
    svx1.write(0);
  }
  int v = otime.toInt();
  v=v*100;
  delay(v);
  svx1.write(90);
  return ;
}
//int svrun2(String s0, String s1,String s2, String s3,String s4, String s5,String s6, String s7,String s8, String s9)
int svrun2(int s0, int s1,int s2, int s3,int s4, int s5,int s6, int s7,int s8, int s9, int deg1){
  
  int var = 5;
   for(int i=0;i<180;i+=1){
    svx6.write(i);
    delay(15);
  }
  if(s0==1){
    svx1.write(111);
  }
  else{
    svx1.write(0);
  }
  if(s2==1){
    svx2.write(111);
  }
  else{
    svx2.write(0);
  }
  if(s4==1){
    svx3.write(111);
  }
  else{
    svx3.write(0);
  }
  if(s6==1){
    svx4.write(111);
  }
  else{
    svx4.write(0);
  }
  if(s8==1){
    svx5.write(111);
  }
  else{
    svx5.write(0);
  }
//  svx1.write(s0);
//  svx2.write(s2);
//  svx3.write(s4);
//  svx4.write(s6);
//  svx5.write(s8);
  while(var > 0){
    if(s1==0){
      svx1.write(90);
      var-=1;
    }
    if(s3==0){
      svx2.write(90);
      var-=1;
    }
    if(s5==0){
      svx3.write(90);
      var-=1;
    }
    if(s7==0){
      svx4.write(90);
      var-=1;
    }
    if(s9==0){
      svx5.write(90);
      var-=1;
    }
    s1-=1;
    s3-=1;
    s5-=1;
    s7-=1;
    s9-=1;
    delay(100);
  }
  return ;
}

String temp0 ;
String temp1 ;
String temp2;
String temp3 ;
String temp4;
String temp5 ;
String temp6 ;
String temp7;
String temp8 ;
String temp9;
String temp10;
void loop() {

if(Serial.available()>0){
  str = Serial.readString();
  Serial.println(str);
//  ctr = str.toInt();
//  --blinkled(ctr);
//  svrun(ctr);
  str.toCharArray(1,1);
  temp0 = str[0];
  temp1 = str[1];
  temp2 = str[2];
  temp3 = str[3];
  temp4 = str[4];
  temp5 = str[5];
  temp6 = str[6];
  temp7 = str[7];
  temp8 = str[8];
  temp9 = str[9];
  temp10 = str[10];
//  svrun1(temp0,temp1);
  svrun2(temp0.toInt(),temp1.toInt(),temp2.toInt(),temp3.toInt(),temp4.toInt(),temp5.toInt(),temp6.toInt(),temp7.toInt(),temp8.toInt(),temp9.toInt(),temp10.toInt());

//  temp = str.indexOf(2);
//  Serial.println(str[1]);
  
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
