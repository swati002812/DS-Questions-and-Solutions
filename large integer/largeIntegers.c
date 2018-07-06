#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
	int i,j,k,l;
	
	long long int firstNumber = 0;
	long long int secNumber  = 0;

	int firstLength = strlen(argv[1]);
	int secondLength = strlen(argv[3]);
	j = firstLength-1;
	k = secondLength -1;
	for(int i=0;i<firstLength;i++){

		long long int p = (pow(10,i));
		int n = (argv[1][j]-'0');
		p = p*n;
		j--;
		firstNumber += p;
	}

	for(int i=0;i<secondLength;i++){

		long long int p = (pow(10,i));
		int n = (argv[3][k]-'0');
		p = p*n;
		k--;
		secNumber += p;
	}

	if((strcmp(argv[2],"+"))==0){


		printf("%lld",firstNumber+secNumber);

	}
	else if((strcmp(argv[2],"-"))==0){

		printf("%lld\n", firstNumber-secNumber);


	}
	else if((strcmp(argv[2],"*"))==0){
		printf("%lld\n", firstNumber*secNumber);
	}
	else if((strcmp(argv[2],"/"))==0){

		printf("%lf\n", (double)firstNumber/secNumber);
	}
	else{
		printf("Not a Valid Input.");
	}
	return 0;
}