#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdio.h>

void flood_fill4(int x,int y,int old_colour,int new_colour)
{
if(getpixel(x,y)==old_colour)
{
	putpixel(x,y,new_colour);
	flood_fill4(x+1,y,old_colour,new_colour);
	flood_fill4(x-1,y,old_colour,new_colour);
	flood_fill4(x,y+1,old_colour,new_colour);
	flood_fill4(x,y-1,old_colour,new_colour);
}
}

void flood_fill8(int x,int y,int old_colour,int new_colour)
{
if(getpixel(x,y)==old_colour)
{
	putpixel(x,y,new_colour);
	flood_fill8(x+1,y,old_colour,new_colour);
	flood_fill8(x-1,y,old_colour,new_colour);
	flood_fill8(x,y+1,old_colour,new_colour);
	flood_fill8(x,y-1,old_colour,new_colour);
	flood_fill8(x+1,y+1,old_colour,new_colour);
	flood_fill8(x+1,y-1,old_colour,new_colour);
	flood_fill8(x-1,y+1,old_colour,new_colour);
	flood_fill8(x-1,y-1,old_colour,new_colour);
}
}

void main()
{
clrscr();
int gm,gd=DETECT;
int choice=0;
int x1,y1,x2,y2,radius,new_colour,xs,ys,old_colour;
initgraph(&gd,&gm,"C:\\TurboC4\\BGI");
while(choice!=3)
{
	cout<<"1: For 4 connected approach 2: For 8 connected approach 3:Exit"<<endl;
	cout<<"Enter your choice: ";
	cin>>choice;
	if(choice==3)
	{
		break;
	}
	cout<<"Enter the coordinates of the endpoints of the diagonal: "<<endl;
	cout<<"xmin=";
	cin>>x1;
	cout<<"xmax=";
	cin>>y1;
	cout<<"ymin=";
	cin>>x2;
	cout<<"ymax=";
	cin>>y2;
	cout<<"Enter the fill colour: ";
	cin>>new_colour;
	cout<<"Enter the seed point: "<<endl;
	cout<<"x=";
	cin>>xs;
	cout<<"y=";
	cin>>ys;
	switch(choice)
	{
		case 1:
		{
			cleardevice();
			setcolor(5);
			rectangle(x1,y1,x2,y2);
			old_colour=getpixel(xs,ys);
			flood_fill4(xs,ys,old_colour,new_colour);
			break;
		}
		case 2:
		{
			cleardevice();
			setcolor(5);
			rectangle(x1,y1,x2,y2);
			old_colour=getpixel(xs,ys);
			flood_fill8(xs,ys,old_colour,new_colour);
			break;
		}
		case 3:
		{
			break;
		}
		default:
		{
			cout<<"Invalid choice"<<endl;
			break;
		}
	}
}
getch();
closegraph();
}
