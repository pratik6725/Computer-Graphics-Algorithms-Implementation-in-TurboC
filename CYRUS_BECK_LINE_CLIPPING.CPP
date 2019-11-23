#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#define k 4

int round(float num)
{
return num<0 ? num-0.5 : num +0.5;
}

struct point
{
	float x;
	float y;
};
struct point EndPt[2], WinPt[2], NewPt[2]; //stores user input
struct point n[k], D, w[k];    //stores N,D,W vectors

float dn, wn;  //stores the dot product

void main()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TurboC4\\TC\\BGI");
int i;

//initializing t
float t, tmin = 0.0, tmax = 1.0;

cout<<"\nEnter the window corner points: "<<endl;
cout<<"xmin=";
cin>>WinPt[0].x;
cout<<"ymin=";
cin>>WinPt[0].y;
cout<<"xmax=";
cin>>WinPt[1].x;
cout<<"ymax=";
cin>>WinPt[1].y;

cout<<"\nEnter the coordinates of the enpoint of the line:"<<endl;
cout<<"x1=";
cin>>EndPt[0].x;
cout<<"y1=";
cin>>EndPt[0].y;
cout<<"x2=";
cin>>EndPt[1].x;
cout<<"y2=";
cin>>EndPt[1].y;

//drawing initial line and boundary
cleardevice();
line(EndPt[0].x,EndPt[0].y,EndPt[1].x,EndPt[1].y);
rectangle(WinPt[0].x,WinPt[0].y,WinPt[1].x,WinPt[1].y);
delay(3000);

//Finding D i.e P2-P1
D.x = EndPt[1].x - EndPt[0].x;
D.y = EndPt[1].y - EndPt[0].y;

//Finding the normal Vector N
n[0].x = 1; n[0].y = 0;  // normal to left boundary
n[1].x = -1; n[1].y = 0; // normal to right boundary
n[2].x = 0; n[2].y = 1;  // normal to bottom boundary
n[3].x = 0; n[3].y = -1; // normal to top boundary

//calculating W=P0-E for left boundary
w[0].x = EndPt[0].x - WinPt[0].x;
w[0].y = EndPt[0].y - WinPt[0].y;

//calculating W=P0-E for bottom boundary
w[2].x = EndPt[0].x - WinPt[0].x;
w[2].y = EndPt[0].y - WinPt[0].y;

//calculating W=P0-E for right boundary
w[1].x = EndPt[0].x - WinPt[1].x;
w[1].y = EndPt[0].y - WinPt[1].y;

//calculating W=P0-E for top boundary
w[3].x = EndPt[0].x - WinPt[1].x;
w[3].y = EndPt[0].y - WinPt[1].y;

//calculating D.N and W.N for each boundary
for(i=0;i<k;i++)
{
	dn = D.x * n[i].x + D.y * n[i].y; // dot product D dot n
	wn = w[i].x * n[i].x + w[i].y * n[i].y; // dot product w dot n

	//making sure denominator is not zero
	if(dn != 0.0)
	{
		//calculating t
		t=-wn/dn;
		if (dn > 0.0)
		{
			if(t <= 1.0)
				if (t>tmin)
					tmin=t;//finding the largest in t_low column
		}
		else if (dn < 0.0)
		{
			if(t >= 0.0)
				if(t<tmax)
					tmax=t;//finding the smallest in t_up column
		}
	}
}
if(tmax>tmin)
{
	NewPt[1].x = EndPt[0].x + tmax * D.x;
	NewPt[1].y = EndPt[0].y + tmax * D.y;
	NewPt[0].x = EndPt[0].x + tmin * D.x;
	NewPt[0].y = EndPt[0].y + tmin * D.y;
}

//drawing clipped line
cleardevice();
rectangle(WinPt[0].x,WinPt[0].y,WinPt[1].x,WinPt[1].y);
line(round(NewPt[0].x),round(NewPt[0].y),round(NewPt[1].x),round(NewPt[1].y));
getch();
closegraph();
}
