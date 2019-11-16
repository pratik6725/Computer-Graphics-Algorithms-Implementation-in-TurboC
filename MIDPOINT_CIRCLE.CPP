#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void midpoint_circle(float xc,float yc,float r)
{
float e=1-r,x=0,y=r;
do
{
	putpixel(xc+x,yc+y,CYAN);
	putpixel(xc+x,yc-y,CYAN);
	putpixel(xc-x,yc+y,CYAN);
	putpixel(xc-x,yc-y,CYAN);
	putpixel(xc+y,yc+x,CYAN);
	putpixel(xc+y,yc-x,CYAN);
	putpixel(xc-y,yc+x,CYAN);
	putpixel(xc-y,yc-x,CYAN);
	if(e<0)
	{
		e=(2*x)+3+e;
	}
	else
	{
		e=2*(x-y)+5+e;
		y=y-1;
	}
	x=x+1;
}
while(x<y);
}

void main()
{
int gm,gd=DETECT;
initgraph(&gd,&gm,":C\\TurboC4\\TC\\BGI");
float xc,yc,r;
cout<<"Enter the coordinates of the centre point:"<<endl;
cout<<"xc=";
cin>>xc;
cout<<"yc=";
cin>>yc;
cout<<"Enter the radius of the circle:"<<endl;
cin>>r;
midpoint_circle(xc,yc,r);
getch();
closegraph();
}