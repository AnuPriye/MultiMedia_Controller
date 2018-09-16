#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <SoftwareSerial.h>
int lc=4,rc=7,red=3,blue=5,green=6,tab=8,mode=9;//Left click on pin 4.Right Click on pin 7.Rgb on pin 3 5 6.
SoftwareSerial HC12(10,11);
MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int m,vx,vy,lcv=0,rcv=0,modev,tabs,modec=0;

void mpccontrol()
{
  HC12.println("#");
  if(digitalRead(lc)==HIGH)
  {
  lcv=0;
  }
  else
  {
  lcv=1;
  }
  if(digitalRead(rc)==HIGH)
  lcv=0;
  else
  lcv=1;
HC12.print("X");
  HC12.print(vx);
  HC12.print("Y");
  HC12.print(vy);
  HC12.print("L");
  HC12.print(lcv);//1 means pressed
  HC12.print("R");
  HC12.print(rcv);
  HC12.println();
  delay(80);
}

void mousecontrol()
{
  HC12.println("@");
  if(digitalRead(lc)==HIGH)
  {
  lcv=0;
  }
  else
  {
  lcv=1;
  }
  if(digitalRead(rc)==HIGH)
  {
  rcv=0;
  }
  else
  {
  rcv=1;
  }
  HC12.print("X");
  HC12.print(vx);
  HC12.print("Y");
  HC12.print(vy);
  HC12.print("L");
  HC12.print(lcv);//1 means pressed
  HC12.print("R");
  HC12.print(rcv);
  HC12.println();
  delay(80);
}

void pptcontrol()
{
  HC12.println("!");
  if(digitalRead(lc)==HIGH)
  {
  lcv=0;
  }
  else
  {
  lcv=1;
  }
  if(digitalRead(rc)==HIGH)
  {
  rcv=0;
  }
  else
  {
  rcv=1;
  }
  HC12.print("X");
  HC12.print(vx);
  HC12.print("Y");
  HC12.print(vy);
  HC12.print("L");
  HC12.print(lcv);//1 means pressed
  HC12.print("R");
  HC12.print(rcv);
  HC12.println();
  delay(80);
}

void setup() {
  Wire.begin();
  pinMode(lc,INPUT_PULLUP);
  pinMode(rc,INPUT_PULLUP);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(tab,INPUT_PULLUP);
  pinMode(mode,INPUT_PULLUP);
  HC12.begin(9600);
  mpu.initialize();
  if (!mpu.testConnection()) { while (1); }
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  vx = (gx+15)/150;  
  vy = -(gz-100)/150;
  modev=digitalRead(mode);
  if(modev==LOW)
  {
  modec++;
  delay(130);
  }
  m=modec%3;//m=0 for mouse,m=1 for mpc,2 for off
  switch(m)
  {
  case 0 : {
  analogWrite(red,255);
  analogWrite(green,0);
  analogWrite(blue,0);
    mousecontrol();
    break;
    }
  case 1 : {
  analogWrite(red,0);
  analogWrite(green,0);
  analogWrite(blue,255);
  mpccontrol();
    break;
  }
    case 2 : {
  analogWrite(red,0);
  analogWrite(green,255);
  analogWrite(blue,0);
  pptcontrol();
    break;
  }
     
  }//end of mode switch
}
aayush
