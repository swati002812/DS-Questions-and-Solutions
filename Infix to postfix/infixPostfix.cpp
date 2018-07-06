#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

int top =-1;

int main(int argc, char *argv[])
{
	int i, len;
	len = strlen(argv[1]);

	int brac=0, si=0;
	char s[5], op[len];

	for(i=0;i<len;i++)
	{
		if(argv[1][i] == '(')
		brac++;

		else if((argv[1][i] == '+')||(argv[1][i] == '-')||(argv[1][i] == '*')||(argv[1][i] == '/'))
		{
			top++;
			op[top] = argv[1][i];
			
		}

		else if(argv[1][i] == ')')
		{
			brac--;
			cout<<op[top];
			top--;
		}

		else
		{
			s[si] = argv[1][i];
			si++;
			s[si] = '\0';
			int x = atoi(s);
			si=0;
			cout<<x;
		}
	}
	cout<<endl;
	return 0;
}

