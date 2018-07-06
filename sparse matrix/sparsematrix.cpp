// sparse matrrix


#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>



using namespace std;

int main(int argc, char *argv[]){
	
	string line;
	fstream inputFile,outputFile;
	inputFile.open(argv[1],ios::in);
	outputFile.open(argv[2],ios::out);
	
	int columns=0, rows=0;
	int rowValue[100],colValue[100],value[100];
	int len;
	int k=0,i,j,x;
	while(getline(inputFile,line)){
		
		j=0;
		columns =0;
		const char* str = line.c_str();
		char number[10];
		len = strlen(str);
		i=0;
		while(i<len){
			
			if(line[i]==' '){
				number[j] = '\0';
				x = atoi(number);
				if(x!=0){
					rowValue[k] = rows+1;
					colValue[k] = columns+1;
					value[k] = x;
					k++;
				}
				columns++;
				j=0;
				
			}
			else{
				number[j] = str[i];
				j++;
			}
			i++;
		}
		
		number[j] = '\0';
		x = atoi(number);
		if(x!=0){
			rowValue[k] = rows+1;
			colValue[k] = columns+1;
			value[k]= x;
			k++;
		}
		columns++;
		
		rows++;
		
	}
	
	for(i=-1;i<k;i++){
		
		if(i==-1){
			outputFile<<rows<<" "<<columns<<" "<<k<<endl;
		}
		else{
			outputFile<<rowValue[i]<<" "<<colValue[i]<<" "<<value[i]<<endl;
		}
		
	}
	
	
	
	
	return 0;
	
	
}
