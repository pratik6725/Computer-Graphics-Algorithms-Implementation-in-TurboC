#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

void dda(float x1,float y1,float x2,float y2)
{
float dx=x2-x1, dy=y2-y1,length,xinc,yinc,x,y;
if(abs(dx)>=abs(dy))
{
	length=abs(dx);
}
else
{
	length=abs(dy);
}
xinc=dx/length;
yinc=dy/length;
x=x1;
y=y1;
putpixel(x,y,CYAN);
int i=0;
while(i<length)
{
	x=x+xinc;
	y=y+yinc;
	putpixel(x,y,CYAN);
	i=i+1;
}
}

void main()
{
int gm,gd=DETECT;
initgraph(&gd,&gm,":C\\TurboC4\\TC\\BGI");
float x1,y1,x2,y2;
cout<<"Enter the 2 endpoints of the line:"<<endl;
cin>>x1>>y1>>x2>>y2;
dda(x1,y1,x2,y2);
getch();
closegraph();
}