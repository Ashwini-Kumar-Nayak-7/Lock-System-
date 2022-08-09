#include<reg51.h>
sbit rs=P1^1;
sbit rw=P1^2;
sbit en=P1^3;
 int cmmd1[]={0x38,0x0E,0x01,0x06,0x80};
 int row[]={0xFE,0xFD,0xFB,0xF7};
 int col[]={0xEF,0xDF,0xBF,0x7F};
 char key[]="/987*654-321+=0C";
 char enter[]="ENTER CODE";
 char psw[]="123456";
 char getpsw[6];
 char wrg[]="DENIED!TRY AGAIN";
 char correct[]="CORRECT ENTRY!";
int a,b,y,z,count=0,i,j,b1;
unsigned int x;
void delay()
{
		for(x=0;x<30000;x++);
}
void cmm()
{
	rs=0;rw=0;en=1;
	delay();
	en=0;
}
void dat()
{
	rs=1;rw=0;en=1;
	delay();
	en=0;
}
void compare() //compare password
{
for(j=0;j<6;j++)
	{
		if(psw[j]!= getpsw[j])
			{
				break;
			}
		}			
}
void correctpsw()	//display for correct password
{
	for(b1=0;b1<14;b1++)
	{
		P2=correct[b1];dat();count=0;
	}
}
void wrgpsw()		// dislay wrong password
{
	for(b=0;b<16;b++)
	{
		P2=wrg[b];dat();count=0;
	}
}

void main()
{	
	
	while(1)
	{
		for(b=0;b<5;b++)//lcd setup
		{
			P2=cmmd1[b];
			cmm();
		}
		for(i=0;i<10;i++)
		{
		P2=enter[i];dat();
		}
		for(b=0;b<6;b++)
			{
		a=0;
		P3=0xF0;
		while(P3==0xF0);
		for(y=0;y<4;y++)
		{
			P3=row[y];
			for(z=0;z<4;z++)
			{
				if((P3|0x0F)==col[z])
				{
					
					P2=key[a]; dat(); delay();
					getpsw[count]=key[a];
					count++;
					if(count==6)
					{
						P2=0xc0;
						cmm();
						compare();
						if(j==6)
							correctpsw();
						else
							wrgpsw();
					}
				
				}
				else
				{
					a++;
				}
			}
		}
	}}
}
		
		
		
		