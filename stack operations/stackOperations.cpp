//stack operations 

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;
int stack[1000];
int maxSizeofStack;
int top=-1;

std::string line;


int main(int argc,char *argv[]){
	
	fstream inputFile,outputFile;
	inputFile.open(argv[1],ios::in);
	outputFile.open(argv[2],ios::out);
	
	int i=0;
//	fscanf(inputFile,"%d",s);
//	cout<<s;
	while(std::getline(inputFile,line))
	{	
		if(i==0){
			
			const char *str = line.c_str();
			maxSizeofStack = atoi(str);
			
		}
		else{
			//const char *str = line.c_str();
			const char *temp = (line.substr(0,3)).c_str();
			const char *psh = "psh";
			const char *pop = "pop";
			
			if(strcmp(temp,psh)==0){
				const  char *data = (line.substr(4,1)).c_str();
				if(top+1>=maxSizeofStack){
					outputFile<<"overflow"<<endl;
				}
				else{
					top++;
					stack[top] = atoi(data);
					outputFile<<data<<" pushed"<<endl;
					
				}
				
			}
			else if(strcmp(temp,pop)==0){
				if(top<0){
					outputFile<<"underflow"<<endl;
					
				}
				else{
					outputFile<<"popped "<<stack[top]<<endl;
					top--;	
				}
				
				
				
			}
			else{
				int j=top;
				for(;j>=0;j--){
					outputFile<<stack[j]<<" ";
				}
				outputFile<<endl;
			}
			
		}
		//cout<<line<<endl;
		i++;
	}
	return 0;
	
}
