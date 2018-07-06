#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
int i, n1copy, n2copy, count1=0, count2=0, sum=0,x,y,n1,n2;
n1copy= atoi(argv[1]);
n2copy= atoi(argv[2]);
n1=n1copy;
n2=n2copy;
while(n1copy != 0)
{
n1copy = n1copy/10;
++count1;
}

while(n2copy != 0)
{
n2copy = n2copy/10;
++count2;
}

if(count1 != count2)
cout<<-1<<endl;

else
{
for(i=0;i<count1;i++)
{
	x=n1%10;
	n1=n1/10;
	y=n2%10;
	n2=n2/10;

	sum = sum + (x*y);
}

cout<<sum<<endl;
}
return 0;
}
