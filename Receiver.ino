#include <SoftwareSerial.h>
#include<Mouse.h>
#include<Keyboard.h>
char input,mode,x,modeblue,butt;
String str="",xin="",yin="",lin="",rin="";
int i,ix,iy,lc,rc,in=0,brf=0,count=0;
SoftwareSerial HC12(8,9);
SoftwareSerial blue(10,11);
void gloves()
{ 
   while (HC12.available()) {
   input= (char)HC12.read();
   if ((input=='@')||(input=='#')||(input=='!'))
    {
      mode=input;
      goto m;
    }
    else
   str+=input;
   in=1;
  }
  m: 
  switch(mode)
  {
    case '@': {
      mousecontrol();
      break;
    }
    case '#': {
      mpccontrol();
      break;
    }
    case '!': {
      Serial.println("Off");
      break;
    }
  }
   str="";
  xin="";
  yin="";
  lin="";
  rin="";
}

void mpccontrol()
{

 ix=str.indexOf('X');
 iy=str.indexOf('Y');
 lc=str.indexOf('L');
 rc=str.indexOf('R');
 in=0;

for(i=ix+1;i<iy;i++)
{
  xin+=str[i];
}
for(i=iy+1;i<lc;i++)
{
  yin+=str[i];
}
for(i=lc+1;i<rc;i++)
{
  lin+=str[i];
}
for(i=rc+1;i<str.length();i++)
{
  rin+=str[i];
}

ix=xin.toInt();
iy=yin.toInt();
lc=lin.toInt();
rc=rin.toInt();
Serial.println(ix); 
Serial.println(iy);
Serial.println(lc); 
Serial.println(rc);
if(iy<-40&&lc==1)
{
  Serial.println("Volume up");
  Keyboard.write(0xDA);        //// 0xDA = Up Arrow = Volume ++  //////////////
  delay(5);
   Keyboard.write(0xDA);        //// 0xDA = Up Arrow = Volume ++  //////////////
  delay(5);
}
if(iy>40&&lc==1)
{
  Serial.println("Volume Down");
  Keyboard.write(0xD9);
delay(5);
Keyboard.write(0xD9);
delay(5);
}
if(ix>50&&lc==1)
{
  Keyboard.write(0xD7);        //// 0xD7 = Right Arrow = Fast Forward //////
        delay(5);
        Keyboard.write(0xD7);
        delay(5);        
}
if(ix<-40&&lc==1)
{
  Keyboard.write(0xD8);       //// 0xD8 = Left Arrow = Revind ///////////////
        delay(5);
        Keyboard.write(0xD8);       //// 0xD8 = Left Arrow = Revind ///////////////
        delay(5);
}
}

void mousecontrol()
{
 ix=str.indexOf('X');
 iy=str.indexOf('Y');
 lc=str.indexOf('L');
 rc=str.indexOf('R');
 in=0;

for(i=ix+1;i<iy;i++)
{
  xin+=str[i];
}
for(i=iy+1;i<lc;i++)
{
  yin+=str[i];
}
for(i=lc+1;i<rc;i++)
{
  lin+=str[i];
}
for(i=rc+1;i<str.length();i++)
{
  rin+=str[i];
}

ix=xin.toInt();
iy=yin.toInt();
lc=lin.toInt();
rc=rin.toInt();
Serial.println(ix); 
Serial.println(iy);
Serial.println(lc); 
Serial.println(rc);
if(lc==1)
{
  Serial.println("Left Click");
  Mouse.press();
  delay(10);
}
else{
  Serial.println("Left Click Released");
  Mouse.release();
}
if(rc==1)
{
  Serial.println("Right Click");
Mouse.press(MOUSE_RIGHT);
delay(10);
}
else
{
Mouse.release(MOUSE_RIGHT);
Serial.println("Right Click Released");
}
Mouse.move(ix,iy,0);
}

void app()
{
  if (blue.available()){
x=blue.read();
if ((x=='0')||(x=='1')||(x=='2')||(x=='3')||(x=='4')||(x=='5')||(x=='6')||(x=='7')||(x=='8')||(x=='9'))
    mode=x;
    else
   butt=x;
/////////////////////////////////////////////////////////Code Starts from Here//////////////////////////////////////////////////
switch (mode){
  ////////////////////////////////////Starting of MPC-HC code section////////////////////////////////////////////////////////
  case '1' : {
    switch (butt) {
      case 'a' : {
        Keyboard.write(0xDA);        //// 0xDA = Up Arrow = Volume ++  //////////////
        delay(50);
        Keyboard.releaseAll();
        break;
      }
      case 'b' : {
        Keyboard.write(0xD8);       //// 0xD8 = Left Arrow = Revind ///////////////
        delay(50);
        Keyboard.releaseAll();
        break;
      }
      case 'c' : {
        Keyboard.write(0x20);       ///// 0x20 = Space bar = Play/Pause //////////
        delay(50);
        Keyboard.releaseAll();
        break;
      }
      case 'd' : {
        Keyboard.write(0xD7);        //// 0xD7 = Right Arrow = Fast Forward //////
        delay(50);
        Keyboard.releaseAll();
        break;
      }
      case 'e' : {
        Keyboard.write(0xD9);       //// 0xD9 = Down Arrow = Volume --  //////////////
        delay(50);
        Keyboard.releaseAll();
        break;
      }        
      case 'f' : {
        Keyboard.write(0xD3);       ///// 0xD3 = Page Up = Previous File //////////
        delay(50);
        Keyboard.releaseAll();
        break;
      }
      case 'g' : {
        Keyboard.write(0xCC);       //// 0xCC = Fu11 = Toggle Full Screen ////////
        delay(50);
        Keyboard.releaseAll();
        break;
      }
      case 'h' : {
        Keyboard.write(0xD6);       ///// 0xD6 = Page Down = Next File //////////
        delay(50);
        Keyboard.releaseAll();
        break;
      }
      case 'i' : {
        Keyboard.print("b");        //// b = Minimize ////////////
        delay(50);
        Keyboard.releaseAll();
        break;
      }
      case 'j' : {
        Keyboard.press(0x80);       //// 0x80 = ctrl key///////
        delay(5);
         Keyboard.print("m");       //// ctrl+m = mute ///////
        delay(50);
        Keyboard.releaseAll();
        break;
      }
      case 'k' : {
        Keyboard.press(0x82);
        break;
      }
       case 'l' : {
        Keyboard.write(0xB3);
      //  delay(100); 
        break;
      }
      case 'm' : {
        Keyboard.releaseAll();
        break;
      }
      default : {
        Keyboard.releaseAll();
        break;
      }
    }
    break;
  }
///////////////////////////////////////////End of MPC-HC Code Section///////////////////////////////////////////////////////

////////////////////////////////////////Starting of Vlc code section////////////////////////////////////////////////////////
  case '2' : {
    switch (butt) {
      case 'a' : {
        Keyboard.press(0x80);       //// 0x80 = ctrl key///////
        delay(5);
         Keyboard.press(0xDA);       //// ctrl+up = vol++ ///////
        delay(5);
        Keyboard.releaseAll();
        break;
      }
      case 'b' : {
        Keyboard.press(0x80);       //// 0x80 = ctrl key///////
        delay(5);
         Keyboard.press(0xD8);       //// ctrl+left = rewind ///////
        delay(5);
        Keyboard.releaseAll();
        break;
      }
      case 'c' : {
        Keyboard.write(0x20);       ///// 0x20 = Space bar = Play/Pause //////////
        delay(50);
        Keyboard.releaseAll();
        break;
      }
      case 'd' : {
        Keyboard.press(0x80);       //// 0x80 = ctrl key///////
        delay(5);
         Keyboard.press(0xD7);       //// ctrl+right = fast forward ///////
        delay(5);
        Keyboard.releaseAll();
        break;
      }
      case 'e' : {
         Keyboard.press(0x80);       //// 0x80 = ctrl key///////
        delay(5);
         Keyboard.press(0xD9);       //// ctrl+down = vol-- ///////
        delay(5);
        Keyboard.releaseAll();
        break;
      }
      case 'f' : {
        Keyboard.print("p");       ///// p = Previous File //////////
        delay(50);
        Keyboard.releaseAll();
        break;
      }
      case 'g' : {
        Keyboard.print("f");       ////F = Toggle Full Screen ////////
        delay(50);
        Keyboard.releaseAll();
        break;
      }
      case 'h' : {
        Keyboard.print("n");       ///// n = Next File //////////
        delay(50);
        Keyboard.releaseAll();
        break;
      }
      case 'i' : {
        Keyboard.press(0x80);       //// 0x80 = ctrl key///////
        delay(5);
         Keyboard.print("q");       //// ctrl+q = quit ///////
        delay(5);
        Keyboard.releaseAll();
        break;
      }
      case 'j' : {
         Keyboard.print("m");       //// m = mute ///////
        delay(50);
        Keyboard.releaseAll();
        break;
      }
      case 'k' : {
        Keyboard.press(0x82);
        break;
      }
       case 'l' : {
        Keyboard.write(0xB3);
      //  delay(100); 
        break;
      }
      case 'm' : {
        Keyboard.releaseAll();
        break;
      }
      default : {
        Keyboard.releaseAll();
        break;
      }
    }
    break;
  }
///////////////////////////////////////////////End of Vlc Code Section///////////////////////////////////////////////////////

///////////////////////////////////////////Starting of Youtube Code Section///////////////////////////////////////////////////////
case '3' : {
    switch (butt) {
      case 'a' : {
        Keyboard.write(0xDA);                      //// 0xDA = Up Arrow = Volume ++  //////////////
        delay(50);
        break;
      }
      case 'b' : {
        Keyboard.print("j");                      //// j = Revind ////
        delay(50);
        break;
      }
      case 'c' : {
        Keyboard.print("k");                    //// k = Play/Pause ////
        delay(50);
        break;
      }
      case 'd' : {
        Keyboard.print("l");                    //// l = Fast Forward ////
        delay(50);
        break;
      }
      case 'e' : {
        Keyboard.write(0xD9);                ////// 0xD9 = Down Arrow = Volume --  //////////////
        delay(50);
        break;
      }
      case 'f' : { 
        Keyboard.press(0x81);             //// Shift + p = previous ////////
        delay(5);
        Keyboard.print("p");
        delay(50);
        Keyboard.releaseAll();
         break;
      }
      case 'g' : {
        Keyboard.print("f");             ////// f = fullscreen //////////
        delay(50);
        break;
      }
      case 'h' : {
        Keyboard.press(0x81);             ////// Shift + n = next /////////
        delay(5);
        Keyboard.print("n");
        delay(50);
       Keyboard.releaseAll();
       break;
      }
      case 'i' : {
        Keyboard.press(0x80);             ////// ctrl + w = quit /////////
        delay(5);
        Keyboard.print("w");
        delay(50);
       Keyboard.releaseAll();
       break;
      }
      case 'j' : {
        Keyboard.print("m");              /////// m = mute //////////
        delay(50);
        break;
      }
      case 'k' : {
        Keyboard.press(0x82);
        break;
      }
       case 'l' : {
        Keyboard.write(0xB3);
      //  delay(100); 
        break;
      }
      case 'm' : {
        Keyboard.releaseAll();
        break;
      }
      default : {
        Keyboard.releaseAll();
        break;
      }
    }
    break;
  }
 ///////////////////////////////////////////End of Youtube Code Section/////////////////////////////////////////////////////// 

   ////////////////////////////////////Starting of Groove code section////////////////////////////////////////////////////////
  case '4' : {
    switch (butt) {
      case 'a' : {
        Keyboard.write(0xCA);        //// 0xCA = F9 = Volume ++  //////////////
        delay(50);
        break;
      }
      case 'b' : {
        Keyboard.press(0x80);       ///// 0x80 = ctrl + b = previous //////////
        delay(5);
        Keyboard.print("b");
        delay(50);
        Keyboard.releaseAll();
        break;
      }
      case 'c' : {
        Keyboard.press(0x80);       ///// 0x80 = ctrl + p = Play/Pause //////////
        delay(5);
        Keyboard.print("p");
        delay(50);
        Keyboard.releaseAll();
        break;
      }
      case 'd' : {
          Keyboard.press(0x80);       ///// 0x80 = ctrl + f = next //////////
        delay(5);
        Keyboard.print("f");
        delay(50);
        Keyboard.releaseAll();
        break;
      }
      case 'e' : {
        Keyboard.write(0xC9);       //// 0xC9 = F8 = Volume --  //////////////
        delay(50);
        break;
      }
      case 'f' : {
        Keyboard.write(0xC8);       ///// 0xC8 = C8 = mute //////////
        delay(50);
        break;
      }
      case 'g' : {
        Keyboard.press(0x82);
        break;
      }
       case 'i' : {
        Keyboard.write(0xB3);
      //  delay(100); 
        break;
      }
      case 'h ' : {
        Keyboard.releaseAll();
        break;
      }
      default : {
        Keyboard.releaseAll();
        break;
      }
    }
    break;
  }
///////////////////////////////////////////End of Groove Code Section///////////////////////////////////////////////////////

 default : {
    Keyboard.releaseAll();
    break;
  }
}
//////////////////////////////////////////////////Thats it ////////////////////////////////////////////////////////////////////
  }
  
}

void setup() {
  Serial.begin(9600);             
  HC12.begin(9600);
  blue.begin(9600);    
  pinMode(13,OUTPUT);
  pinMode(3,INPUT_PULLUP);           
}
void loop() {
  brf=digitalRead(3);
  if(brf==LOW)
      count++;    
  if(count%2==0)
  {
    digitalWrite(13,HIGH);
    HC12.listen();
  gloves();
  }
  else
  {
    digitalWrite(13,LOW);
  blue.listen();
  app();
  }
}



