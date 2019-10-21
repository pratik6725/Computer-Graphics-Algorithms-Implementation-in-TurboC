#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void bresenham(float x1,float y1,float x2,float y2)
{
float dx=abs(x2-x1),dy=abs(y2-y1),xinc,yinc,x,y,e;
if(x1<x2)
	xinc=1;
else
	xinc=-1;
if(y1<y2)
	yinc=1;
else
	yinc=-1;
x=x1;
y=y1;
putpixel(x,y,CYAN);
if(dx>=dy)
{
	e=(2*dy)-dx;
	while(x!=x2)
	{
		if(e<0)
		{
			e=e+(2*dy);
		}
		else
		{
			e=e+2*(dy-dx);
			y=y+yinc;
		}
		x=x+xinc;
		putpixel(x,y,CYAN);
	}
}
else
{
	e=(2*dx)-dy;
	while(y!=y2)
	{
		if(e<0)
		{
			e=e+(2*dx);
		}
		else
		{
			e=e+2*(dx-dy);
			x=x+xinc;
		}
		y=y+yinc;
		putpixel(x,y,CYAN);
	}
}
}

void main()
{
int gm,gd=DETECT;
initgraph(&gd,&gm,":C\\TurboC4\\TC\\BGI");
float x1,y1,x2,y2;
cout<<"Enter the 2 endpoints of the line:"<<endl;
cin>>x1>>y1>>x2>>y2;
bresenham(x1,y1,x2,y2);
getch();
closegraph();
}