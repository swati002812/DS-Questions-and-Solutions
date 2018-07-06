#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;


float maximumSum(float *a,int k){

	int i=0,j=0;
	float max = -1000000;
	float temp=0;

	for(i=0;i<k;i++){
		
		temp = a[i];
		if(temp>max)
			max = temp;
		
		for(j=i+1;j<k;j++){
			
			temp = temp+a[j];
			
			if(temp>max)
				max  = temp;
		}

		if(temp>max){
			max = temp;
		}
		

	}

	return max;

}

int main(int argc,char *argv[]){

	char s[100];
	int si;
	int k= 0;
	int len = strlen(argv[1]);
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

	float a[k];
	int ai =0;
	for(int i=0;i<len;i++)
	{

		
		if(argv[1][i]==' ')
		{
			s[si] = '\0';
			float x = atof(s);
			a[ai] = x;
			ai++;
			si= 0;
			continue;
			
		}
		s[si] = argv[1][i];
		si++;

	}

	s[si] = '\0';
	float x = atof(s);
	a[ai] = x;
	ai++;

	// for(int i=0;i<ai;i++){
	// 	cout<<a[i]<<endl;
	// }


	printf("%0.02f",maximumSum(a,ai));
	return 0;
}