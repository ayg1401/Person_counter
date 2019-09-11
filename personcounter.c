/* Copyright © reserved to Ayush and Avinash
 * TEAM MEMBERS : AYUSH GOSWAMI,AVINASH PRASAD,INDROJEET DUTTA 
 * PERSON COUNTER AND TIME DISPLAY
 *
 * This program displays the timing in mm:ss & counts the no of person inside the shopping mall;
 * ATmega8 should be clocked from a 12MHz crystal
 * Created: 05-04-2018 PM 11:47:49
 * Author:Ayush & Avinash
 * 16ECE047 & 16ECE026 
 * 2nd year b_tech ,Giet Gunupur 
 */


#define F_CPU	20000
#include "avr/io.h"
#include<util/delay.h>
void display();// display for no. of persons 
void number(int);////display no. of persons in 7_segment
void timedisplay();//display time in mm:ss 
void timenumber(int);//display time on 7_segment
void constant();//display stored values 
int bitOne, bitTwo,bitOne1, bitTwo2;//variables for sevent segment ports
int bitThree, bitFour,z=0;//variables for 7-segment ports
char seg[]={0x7B,0x0A,0xB3,0x9B,0xCA,0xD9,0xF9,0x0B,0xFF,0xCF};//array for 7-segment ports
int main()
{      //Set PORTD as output
        DDRD=0xFF;
	//Set PORTB as output
	DDRB=0xFF;
	//Set PORTC as input
	DDRC=0b00000000;
	for(int k=0;k<1000;k++)// FOR CHECKING $EVEN $EGMENT       
	{
	   PORTC=0b00000011;PORTD=0b11101111; _delay_ms(25);PORTC=0b00110000;PORTB=0b11101111; _delay_ms(25);}
	while(1)
	{
			for(int j=0;j<=60;j++)// loop for mm
			{
		        for(int i = 0;i<60;i++ )// loop for ss
			    {  
				//extraction of digits for min & secs

				 	bitOne=i/10;
					bitTwo=i%10;
					bitThree=j/10;
					bitFour=j%10;
					timedisplay();//calling function to display time
				}
    		}
	}
}

void timedisplay()
{  
        int x,y;
		x=PINC&0b00000100;//sensor1
		y=PINC&0b00001000;//sensor2
		if((z>100)||(z<0))//condition for counter 0-99
		z=0;
        while(1)
	    {
			if(x==0b00000100&&y==0b00000000&&z<100)//condition for checking sensors on/off
			{
			   ++z;
			   bitTwo2 =z% 10;	
			   bitOne1 =z/10;
			   display();
			}
		    else if(x==0b00000000&&y==0b00001000&&z>0)//condition for checking sensors on/off
		    { 
		       --z;
		       bitTwo2 =z% 10;	
			   bitOne1 =z/10;
			   display();  } 
		   
		   else if(x==0b00000000&&y==0b00000000)//condition for checking sensors on/off
		 	    break;
		   else
		        constant();

		   x=PINC&0b00000100;
		   y=PINC&0b00001000;
   		}
        for(int k=0;k<100;k++)//loop for constant 7_segment time display
		{
			PORTC=0b00000010;
			timenumber(bitThree);
			_delay_ms(50);
			PORTC=0b00000001;
			timenumber(bitFour);
			_delay_ms(50);

			PORTC=0b00010000;
			timenumber(bitTwo);
			_delay_ms(50);
			PORTC=0b00100000;
			timenumber(bitOne);
			_delay_ms(50);
		}

}
void display() 
{ 
	int  x,y;   
	do{
	     for(int k=0;k<100;k++)
	        {	 
	           PORTC=0b00000001;
		   number(bitTwo2);
		   _delay_ms(25);
		   PORTC=0b00000010;
		   number(bitOne1);
		   _delay_ms(25);
		}
	    x=PINC&0b00000100;
	    y=PINC&0b00001000;
	 }while((x==0b00000100&&y==0b00000000)||(x==0b00000000&&y==0b00001000));//condition for checking sensors on/off
}

void constant()
{
    for(int k=0;k<100;k++)
    {	
       PORTC=0b00000001;
       number(bitTwo2);
       _delay_ms(25);
       PORTC=0b00000010;
       number(bitOne1);
       _delay_ms(25);
    }
}


void timenumber(int num) 
{

	switch(num)
	{ 
		case 0 : PORTD=seg[num];
		         PORTB=seg[num];
				 break;

		case 1 : PORTD=seg[num];
			 PORTB=seg[num];
				 break;

		case 2 :  PORTD=seg[num];
		          PORTB=seg[num];
				 break;

		case 3 : PORTD=seg[num];
			 PORTB=seg[num];
				 break;

		case 4 : PORTD=seg[num];
                         PORTB=seg[num];
				 break;

		case 5 : PORTD=seg[num];
                         PORTB=seg[num];
				 break;

		case 6 :  PORTD=seg[num];
			  PORTB=seg[num];
				 break;

		case 7 : PORTD=seg[num];
			 PORTB=seg[num];
				 break;

		case 8 : PORTD= seg[num];
		    	 PORTB=seg[num];
				 break;

		case 9 :  PORTD=seg[num];
			  PORTB=seg[num];
				 break;

		default : break;
	}
}

void number(int num) 
{
	switch(num)
 { 
		case 0 : PORTD=seg[num];
				 break;

		case 1 : PORTD= seg[num];
				 break;

		case 2 : PORTD=seg[num];
				 break;

		case 3 : PORTD= seg[num];
				 break;

		case 4 : PORTD= seg[num];
				 break;

		case 5 : PORTD=seg[num];
				 break;

		case 6 : PORTD=seg[num];
				 break;

		case 7 : PORTD=seg[num];
				 break;

		case 8 : PORTD= seg[num];
				 break;

		case 9 : PORTD=seg[num];
		                 break;

		default : break;
	}


}


