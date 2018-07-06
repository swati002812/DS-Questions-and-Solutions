//stack operations 

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;
int stack1[1000];
int stack2[1000];
int maxSizeofStack1;
int maxSizeofStack2;
int top1=-1;
int top2=-1;

string line;

int main(int argc,char *argv[]){
	
	fstream inputFile,outputFile;
	inputFile.open(argv[1],ios::in);
	outputFile.open(argv[2],ios::out);
	
	int i=0,j;
	while(getline(inputFile,line))
	{	
		if(i==0){
			const char *str = line.c_str();
			int temp_size = atoi(str);
			maxSizeofStack1 = 	temp_size/2;
			maxSizeofStack2 = temp_size-maxSizeofStack1;

			for(j=0;j<maxSizeofStack1;j++)
			stack1[j] = (-1);

			for(j=0;j<maxSizeofStack2;j++)
			stack2[j] = (-1);
			
		}
		else{
	//		const char *str = line.c_str();
			const char *temp = (line.substr(0,3)).c_str();
			const char *psh = "psh";
			const char *pop = "pop";
			cout<<stack1[1]<<"   "<<stack2[1];
			
			if(strcmp(temp,psh)==0){
				const  char *data = (line.substr(4,1)).c_str();
				const char *stack_number = (line.substr(6,1)).c_str();
				
				if(atoi(stack_number)==1){
					if(top1+1>=maxSizeofStack1){
						outputFile<<"overflow in stack 1"<<endl;
					}
					else{
						top1++;
						stack1[top1] = atoi(data);
						outputFile<<data<<" pushed in stack 1"<<endl;
					
					}
				}
				else if(atoi(stack_number)==2){
					if(top2+1>=maxSizeofStack2){
						outputFile<<"overflow in stack 2"<<endl;
					}
					else{
						top2++;
						stack2[top2] = atoi(data);
						outputFile<<data<<" pushed in stack 2"<<endl;
					
					}
				}
				
				
			}
			else if(strcmp(temp,pop)==0){
				const char *stack_number = (line.substr(4,1)).c_str();
				if(atoi(stack_number)==1){
					if(top1<0){
						outputFile<<"underflow in stack 1"<<endl;
						
					}
					else{
						outputFile<<"popped "<<stack1[top1]<<" from stack 1"<<endl;
						top1--;	
					}
				}
				if(atoi(stack_number)==2){
					if(top2<0){
						outputFile<<"underflow in stack 2"<<endl;
						
					}
					else{
						outputFile<<"popped "<<stack2[top2]<<" from stack 2"<<endl;
						top2--;	
					}
				}
				
				
				
			}
			else{
				const char *stack_number = (line.substr(6,1)).c_str();
				/*if(strcmp(stack_number,NULL)==0)
					stack_number = "3";*/
				if(atoi(stack_number)==1){
						
					for(j=0;j<=top1;j++){
						if(stack1[j] == (-1)){
							outputFile<<"NIL ";
							continue;
						}
						outputFile<<stack1[j]<<" "; 
					}
					outputFile<<endl;
					
				}
				else if(atoi(stack_number)==2){

                                        for(j=0;j<=top2;j++){
						if(stack2[j] == (-1)){
                                                        outputFile<<"NIL ";
                                                        continue;
                                                }
                                                outputFile<<stack2[j]<<" ";
                                        }
                                        outputFile<<endl;

                                }

				else{
					
					for(j=0;j<=top1;j++){
						if(stack1[j] == (-1)){
                                                        outputFile<<"NIL ";
                                                        continue;
                                                }
						outputFile<<stack1[j]<<" "; 
					}
					for(j=0;j<=top2;j++){
						if(stack2[j] == (-1)){
                                                        outputFile<<"NIL ";
                                                        continue;
                                                }
						outputFile<<stack2[j]<<" ";
					}
					outputFile<<endl;
					
				}
			}
			
		}
		//cout<<line<<endl;
		i++;
	}
	return 0;
	
}
