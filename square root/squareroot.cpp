#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{

float num, prec, sum, sum1;

num = atof(argv[1]);
prec = atof(argv[2]);

float lower=1;

while((lower*lower)<num)
{
	lower++;
}

if((lower*lower)!=num)
lower--;

sum = lower + prec;
//cout<<"sum ="<<sum<<endl;

while((sum*sum)<=num)
{
	sum = sum+prec;
}

float prec1=0.01;
if((sum*sum)!=num)
{
	sum1=sum-prec;
	sum1= sum1+prec1;
}
	while((sum1*sum1)<=num)
	{
		sum1= sum1+prec1;
	}


if((sum1*sum1)!=num)
sum1=sum1-prec1;


printf("%.2f",sum1);
cout<<endl;
return 0;
}
