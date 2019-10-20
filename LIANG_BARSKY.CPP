#include<iostream.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>

void liang_barsky_function(float xmin,float ymin,float xmax,float ymax,float x1,float y1,float x2,float y2)
{
float dx,dy,t1=0,t2=1;
dx=x2-x1;
dy=y2-y1;
float p[50]={0},q[50]={0},r[50]={0};
p[1]=-(x2-x1);
p[2]=x2-x1;
p[3]=-(y2-y1);
p[4]=y2-y1;
q[1]=x1-xmin;
q[2]=xmax-x1;
q[3]=y1-ymin;
q[4]=ymax-y1;
for(int i=1;i<=4;i++)
{
	r[i]=q[i]/p[i];
}
for(int j=1;j<=4;j++)
{
	if(p[j]==0)
	{
		cout<<"Line is parallel to window"<<endl;
		if(q[i]<0)
		{
			cout<<"Line is lying outside. Hence rejected."<<endl;
		}
	}
}
float max=0.00,min=1.00;
for(int k=1;k<=4;k++)
{
	if(p[k]<0.00 && r[k]>max)
	{
		max=r[k];
	}
	t1=max;
	if(p[k]>0 && r[k]<min)
	{
		min=r[k];
	}
	t2=min;
}
if(t1>t2)
{
	cout<<"Line is outside. Hence rejected"<<endl;
}
else
{
	float x1new,y1new,x2new,y2new;
	x1new=x1+(t1*dx);
	y1new=y1+(t1*dy);
	x2new=x1+(t2*dx);
	y2new=y1+(t2*dy);
	setcolor(RED);
	rectangle(xmin,ymin,xmax,ymax);
	setcolor(CYAN);
	line(x1new,y1new,x2new,y2new);
}
}

void main()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TurboC4\\TC\\BGI");
float xmin,ymin,xmax,ymax;
cout<<"Enter the coordinates of the top-left corner:"<<endl;
cin>>xmin>>ymin;
cout<<"Enter the coordinates of the bottom-right corner:"<<endl;
cin>>xmax>>ymax;
rectangle(xmin,ymin,xmax,ymax);
float x1,y1,x2,y2;
cout<<"Enter the 2 endpoints of the line:"<<endl;
cin>>x1>>y1>>x2>>y2;
line(x1,y1,x2,y2);
delay(1000);
liang_barsky_function(xmin,ymin,xmax,ymax,x1,y1,x2,y2);
getch();
closegraph();
}
