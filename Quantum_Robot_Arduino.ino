#include <Servo.h>

Servo mouth, R_hand, L_hand;

int x;
char newArray[5]="00000";
int arrayPosition=0; 
int mo=0;
int deg=0;


void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
  
mouth.attach(8); 
R_hand.attach(9); 
L_hand.attach(10); 
  
R_hand.write(15);
L_hand.write(180);
mouth.write(2);


}

void loop() {
delay(100);
 while (!Serial.available());
 x = Serial.readString().toInt();
 
 
mo=0;
deg=0;
newArray[5]="00000";



  for(int a=16; a>=1; a=a/2){   
    if((x-a)>=0){         
      newArray[arrayPosition]='1'; 
      x-=a;}           
    else{
      newArray[arrayPosition]='0';} 
      arrayPosition++;    
    }


if(newArray[0]=='1')
{
mo=mo+4;
}
if(newArray[1]=='1')
{
mo=mo+2;
}
if(newArray[2]=='1')
{
mo=mo+1;
}

deg=mo*10;
mouth.write(deg);


if(newArray[3]=='1')
{
R_hand.write(60);
}
else if(newArray[3]=='0')
{
R_hand.write(15);
}


if(newArray[4]=='1')
{
L_hand.write(130);
}
else if(newArray[4]=='0')
{
L_hand.write(180);
}


}
