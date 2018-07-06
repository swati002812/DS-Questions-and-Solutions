#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(int argc,char *argv[]){

	char s[100];
	int si;
	int a[100000]={0};
	int k= 0;
	int flag= 0;
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

	for(int i=0;i<len;i++)
	{

		
		if(argv[1][i]==' ')
		{
			s[si] = '\0';
			int x = atoi(s);
			a[x]++;	
			//cout<<"a["<<x<<"]="<<a[x]<<endl;
			if(a[x]>=(k/2)){
				cout<<x<<endl;
				flag = 1;
				break;
			}
			si= 0;
			continue;
			
		}
		s[si] = argv[1][i];
		si++;

		if(i==len-1)
		{
		s[si] = '\0';
		int x= atoi(s);
		a[x]++;
		if(a[x]>=(k/2)){
			cout<<x<<endl;
			flag=1;
			break;
			}
		si=0;
		}

	}
	if(flag==0){
		cout<<"NONE"<<endl;
	}
	return 0;
}
