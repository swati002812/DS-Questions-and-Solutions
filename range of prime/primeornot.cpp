#include<iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isPrime(int n){

	for(int i=2;i<=sqrt(n);i++){

		if(n%i==0){
			return 0;
		}
	}

	return 1;
}



int main(int argc,char *argv[]){
	
	int s = atoi(argv[1]);
	int e = atoi(argv[2]);
	int i;
	for(i=s;i<=e;i++){

		printf("%d ",isPrime(i));
	}
	printf("\n");

	return 0;

}
