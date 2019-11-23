#include<iostream.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>

void main()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TurboC4\\TC\\BGI");
int x,y,temp;
int n,i,j,k,dx,dy;
int a[20][2],xi[20];
float slope[20];
cout<<"Enter the no. of edges of the polygon:";
cin>>n;
cout<<"Enter the coordinates of the polygon:"<<endl;
for(i=0;i<n;i++)
{
	cout<<"X"<<i<<" Y"<<i<<"=";
	cin>>a[i][0]>>a[i][1];
}
a[n][0]=a[0][0];
a[n][1]=a[0][1];
//detectgraph(&gd,&gm);  not needed
setcolor(2);
//draw polygon
for(i=0;i<n;i++)
{
	line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
}
getch();
cleardevice();
for(i=0;i<n;i++)
{
	dy=a[i+1][1]-a[i][1];
	dx=a[i+1][0]-a[i][0];
	if(dy==0)
	{
		slope[i]=1.0;
	}
	if(dx==0)
	{
		slope[i]=0.0;
	}
	if((dy!=0)&&(dx!=0)) //calculates inverse slope
	{
		slope[i]=(float)dx/dy;
	}
}
for(y=0;y<480;y++)
{
	k=0;
	for(i=0;i<n;i++)
	{
		if(((a[i][1]<=y)&&(a[i+1][1]>y))||((a[i][1]>y)&&(a[i+1][1]<=y)))
		{
			xi[k]=(int)(a[i][0]+slope[i]*(y-a[i][1]));
			k++;
		}
	}
	for(j=0;j<k-1;j++)
	{
		for(i=0;i<k-1;i++)
		{
			if(xi[i]>xi[i+1])
			{
				temp=xi[i];
				xi[i]=xi[i+1];
				xi[i+1]=temp;
			}
		}
	}
	setcolor(1);
	for(i=0;i<k;i+=2)
	{
		delay(10);
		line(xi[i],y,xi[i+1]+1,y);
	}
	setcolor(2);
	for(i=0;i<n;i++)
	{
		line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
	}
}
getch();
closegraph();
}






