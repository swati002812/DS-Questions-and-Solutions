#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main(int argc, char *argv[])
{
	int temp,j;
	
	char s[100];
	int si=0, k=0, i, x;
	int len;
	len = strlen(argv[1]);

	for(int i=0;i<len;i++)
	{

	
		if(argv[1][i]==' ')
		{
			k++;
			continue;
			
		}

	}
	k++;
	si =0;
	int a[k],ai=0;

	for(i=0;i<len;i++)
	{
		if(argv[1][i] == ' ')
		{
			s[si] = '\0';
			x= atoi(s);
			a[ai] = x;
			ai++;
			si=0;
			continue;
		}
		s[si] = argv[1][i];
		si++;
	}
	s[si]='\0';
	x=atoi(s);
	a[ai]=x;
	ai++;
	
	

	for(i=0;i<k-1;i++)
	{
		for(j=0;j<k-i-1;j++)
		{
		if(a[j]>a[j+1])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
		}
	}

	for(i=0;i<k;i++)
		cout<<a[i]<<" ";
cout<<endl;
return 0;
}

		

