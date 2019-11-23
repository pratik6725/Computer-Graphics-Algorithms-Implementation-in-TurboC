#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<iostream.h>
#include<math.h>


void bezier(int,int[],int[]);
float binomial(float,int,int);
float fact(int x);
float ncr(int n,int i);

void bezier(int n,int x[],int y[])
{
float u=0,sum_x,sum_y,temp_x,temp_y;
int i;
while(u<=1)
{
sum_x=0;
sum_y=0;
for(i=0;i<n;i++)
{
temp_x=x[i]*binomial(u,i,n);
sum_x+=temp_x;
temp_y=y[i]*binomial(u,i,n);
sum_y+=temp_y;
}
putpixel((int)sum_x,(int)sum_y,3);
u+=0.0001;
}
}

float binomial(float u,int i,int n)
{
float coeff=0;
coeff=ncr(n,i)*pow(u,i)*pow(1-u,n-i-1);
return coeff;
}

float ncr(int n,int i)
{
float calc=0;
calc=fact(n-1)/(fact(i)*fact(n-i-1));
return calc;
}

float fact(int x)
{
float f=1;
int i=1;
for(i=1;i<=x;i++)
f*=i;
return f;
}

void main()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TurboC4\\TC\\BGI");
int x[4]={420,220,220,420};
int y[4]={185,155,225,195};
bezier(4,x,y);
getch();
closegraph();
}
