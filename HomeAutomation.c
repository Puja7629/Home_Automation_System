#include<reg52.h>
#include<stdio.h>
sbit b= P0^0;
sbit c=P0^1:
unsigned int a;
void recieve()
{
   TMOD = 0X20; //Time 1 Auto Reload
   TH1 = 0XFD;  //Set BAUD Rate =9600
   SCON = 0X50;   //Set a Bit UART Mode
   TR1 = 1;       //Enable timer1

   while(RI==0);
   a=SBUF;
   RI=0;
}
void main()
{
PO=0X00;  //Setting Port 0 to zero
    
 while(1)    //infinite loop
   {
    receive();    //call the receive function
    if(a=='a')    //comapre the bit patterns of variable a and ASCII value of alphabet 'a'
    {
     b=0;
    }
   if(a=='A')  //compare the bit patterns of variable a and ASCII value of alphabet 'A'
   {
    b=1;    //Sets input to relay 1 as high at port 0
    }
   if(a=='b')   //Simillar comparision as above
   {
    c=0; //sets input to Relay 2 as low
   }
  if(a=='B')
   {
   c=1;   //sets input to realy 2 as high
   }
}
  }
}