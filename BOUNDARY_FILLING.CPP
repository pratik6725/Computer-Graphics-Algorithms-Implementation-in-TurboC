#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

void boundary_fill(int x,int y,int fill_colour,int boundary_colour)
{
	if(getpixel(x,y)!=fill_colour && getpixel(x,y)!=boundary_colour)
	{
		putpixel(x,y,fill_colour);
		boundary_fill(x+1,y,fill_colour,boundary_colour);
		boundary_fill(x-1,y,fill_colour,boundary_colour);
		boundary_fill(x,y+1,fill_colour,boundary_colour);
		boundary_fill(x,y-1,fill_colour,boundary_colour);
	}
}

void main()
{
clrscr();
int gm,gd=DETECT;
int choice,x1,y1,x2,y2,fill_colour,radius;
initgraph(&gd,&gm,"C:\\TurboC4\\BGI");
cout<<"Boundary: 1.Rectangle 2.Circle "<<endl;
cout<<"Select the desired boundary: "<<endl;
cin>>choice;
switch(choice)
{
	case 1:
	{
		cout<<"Enter the coordinates of the endpoint of the diagonal: "<<endl;
		cin>>x1>>y1>>x2>>y2;
		cout<<"Enter the desired fill colour: "<<endl;
		cin>>fill_colour;
		cleardevice();
		rectangle(x1,y1,x2,y2);
		boundary_fill(x1+5,y1+5,fill_colour,15);
		break;
	}
	case 2:
	{
		cout<<"Enter the coodinates of the centre: "<<endl;
		cin>>x1>>y1;
		cout<<"Enter the desired radius: "<<endl;
		cin>>radius;
		cout<<"Enter the fill colour: "<<endl;
		cin>>fill_colour;
		cleardevice();
		circle(x1,y1,radius);
		boundary_fill(x1,y1,fill_colour,15);
		break;
	}
	default:
	{
		cout<<"Invalid Choice"<<endl;
		break;
	}
}
getch();
closegraph();
}