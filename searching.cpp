#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;
int main(int argc, char *argv[])
{
	char s[100];
	int si=0, k=0, ai=0, i, x;
	int len = strlen(argv[1]), flag=0;

	for(i=0;i<len;i++)
	{
		if(argv[1][i] == ' ')
		{
			k++;
			continue;
		}
	}
	k++;
	int a[k];

	for(i=0;i<len;i++)
	{
		if(argv[1][i] == ' ')
		{
			s[si] = '\0';
			x = atoi(s);
			a[ai] = x;
			ai++;
			si=0;
			continue;
		}
		s[si] =argv[1][i];
		si++;
	}

s[si] ='\0';
x= atoi(s);
a[ai] = x;
ai++;

//searching
int key = atoi(argv[2]);

for(i=0;i<k;i++)
{
	if(a[i] == key){
	cout<<i+1<<endl;
	flag=1;
	break;
	}
}

if(flag==0)
cout<<"0"<<endl;

return 0;
}
