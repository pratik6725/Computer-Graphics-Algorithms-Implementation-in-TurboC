#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>

void bezier(int x[4],int y[4])
{
int i;
double u;
for(u=0.0;u<1.0;u+=0.0005)
{
	double xu=x[0]*pow(1-u,3)+x[1]*3*u*pow(1-u,2)+x[2]*3*u*u*(1-u)+x[3]*pow(u,3);
	double yu=y[0]*pow(1-u,3)+y[1]*3*u*pow(1-u,2)+y[2]*3*u*u*(1-u)+y[3]*pow(u,3);
	putpixel(xu,yu,WHITE);
}

for(i=0;i<4;i++)
{
	putpixel(x[i],y[i],RED);
}
}

void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TurboC4\\TC\\BGI");
int x[4],y[4];
cout<<"Enter the X,Y co-ordinates of the 4 control points:"<<endl;
for(int i=0;i<4;i++)
{
	cout<<"Control point "<<i+1<<": ";
	cin>>x[i]>>y[i];
}
cleardevice();
bezier(x,y);
getch();
closegraph();
}