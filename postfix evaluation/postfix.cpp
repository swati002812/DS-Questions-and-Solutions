#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
int top = -1;
//int maxSize;

int main(int argc, char *argv[])
{
	int i, len;
	len = strlen(argv[1]);

	int a[len],bi,ai, flag=0;
	char s[5];
	int si=0;
	for(i=0; i<len; i++)
	{
		if(argv[1][i] == '+')
		{
			if(top>=1){
			//cout<<"+++"<<endl;
			ai = a[top];
			top--;
			bi = a[top];
			//cout<<"ai = "<<ai<<"    bi = "<<bi<<endl;
			a[top] = bi+ai;
			//cout<<"top in + ="<<top<<"   a["<<top<<"]= "<<a[top];
			continue;
			}
			else{
			cout<<"invalid\n";
			flag =1;
			break;
			}
		}
		
		else if(argv[1][i] == '-')
                {
			if(top>=1){
                        ai = a[top];
                        top--;
                        bi = a[top];
                        a[top] = bi-ai;
                        continue;
			}
			else{
			cout<<"invalid\n";
			flag=1;
			break;}
                }
                
		else if(argv[1][i] == '*')
                {
			if(top>=1){
                        ai = a[top];
                        top--;
                        bi = a[top];
                        a[top] = bi*ai;
                        continue;
			}
			else{
			cout<<"invalid\n";
			flag=1;
			break;
			}
                }
                
		else if(argv[1][i] == '/')
                {
			if(top>=1){
                        ai = a[top];
                        top--;
                        bi = a[top];
                        a[top] = bi/ai;
                        continue;
			}
			else{
			cout<<"invalid\n";
			flag=1;
			break;}
                }
                else
		{
			s[si] = argv[1][i];
			si++;
			s[si] = '\0';
			top++;
			
			int x = atoi(s);
			a[top] = x;
			si=0;
		}
	//cout<<"top = "<<top<<"\na["<<top<<"]= "<<a[top]<<endl;
	}

//cout<<"top = "<<top;
//cout<<endl<<"a[top] = "<<a[top]<<endl;

if(flag == 0){
	if(top != 0)
	cout<<"invalid"<<endl;

	else
	{
		if((a[top] == '+')||(a[top] == '-')||(a[top] == '*')||(a[top] == '/'))
		cout<<"invalid"<<endl;

		else
		cout<<a[top]<<endl;
	}
}
return 0;
}
