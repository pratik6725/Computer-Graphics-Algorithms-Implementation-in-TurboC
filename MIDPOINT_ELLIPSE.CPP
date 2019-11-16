#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void myellipse(float a,float b,float xc,float yc)
{
float x=0,y=b;

//Region I IDP
float e=(b*b)-(a*a*b)+(0.25*a*a);
do
{
	putpixel(xc+x,yc+y,3);
	putpixel(xc+x,yc-y,3);
	putpixel(xc-x,yc+y,3);
	putpixel(xc-x,yc-y,3);
	if(e<0)
	{
		x++;
		e=e+(2*b*b*x)+(b*b);
	}
	else
	{
		x++;
		y--;
		e=e+(2*b*b*x)-(2*a*a*y)+(b*b);
	}
}while((2*a*a*y)>(2*b*b*x));

//Region II IDP
e=(x*b*b)+(0.25*b*b)-(2*y*a*a)+(a*a);
do
{
	putpixel(xc+x,yc+y,3);
	putpixel(xc+x,yc-y,3);
	putpixel(xc-x,yc+y,3);
	putpixel(xc-x,yc-y,3);
	if(e>0)
	{
		y--;
		e=e-(2*y*a*a)+(a*a);
	}
	else
	{
		y--;
		x++;
		e=e-(2*a*a*y)+(2*b*b*x)+(a*a);
	}
}while(y!=0);
}

void main()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TurboC4\\TC\\BGI");
float a,b,xc,yc;
cout<<"Enter the x-radius & the y-radius:"<<endl;
cout<<"x-radius=";
cin>>a;
cout<<"y-radius=";
cin>>b;
cout<<"Enter the coordinates of the center point of the ellipse:"<<endl;
cout<<"x-center=";
cin>>xc;
cout<<"y-center=";
cin>>yc;
cleardevice();
myellipse(a,b,xc,yc);
getch();
closegraph();
}