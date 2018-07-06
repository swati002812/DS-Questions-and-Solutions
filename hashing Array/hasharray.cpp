#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>

using namespace std;

string line;

int main(int argc, char *argv[])
{
	fstream inputFile, outputFile;
	inputFile.open(argv[1], ios::in);
	outputFile.open(argv[2], ios::out);
	int count=0,j,len,x,hf,h,c,y,z,firstEntry =0,a[1000][1000];
	int first[2], k=0, q=0, totalrun;
	
	while(getline(inputFile,line))
	{
		if(count==0)
		{
			const char *templine = line.c_str();
			//const char *data =  (line.substr(0, stlen(templine))).c_str();
			len = strlen(templine);
			char temp1[len];
			
			for(j=0;j<len;j++)
			{
				if(templine[j] == ' '){
					temp1[k] = '\0';
					x = atoi(temp1);
					first[q] = x;
					q++;
					k=0;
					}

				else{
					temp1[k] = templine[j];
					k++;
				}
			}
			temp1[k] = '\0';
			x = atoi(temp1);
			first[q] = x;
			k=0;

		}
		
		else
		{
			const char *i ="i";
			const char *s ="s";
			const char *option = (line.substr(0,1)).c_str();
			char temp1[100];	
			if((strcmp(option,i)) == 0)
			{
				if(firstEntry == 0){
					for(y=0; y<first[0];y++)
                                		for(z=0;z<first[1];z++)
                                        		a[y][z] = -1;
					}

				firstEntry = 1;
				const char *templine = line.c_str();
				len = strlen(templine); 
				char data[strlen(templine)-2];
				string new_line = (line.substr(2,strlen(templine)-2));
				strcpy(data, new_line.c_str());
	//			cout<<"len of data ="<<strlen(data)<<endl;
				k=0;
				c=0;
			
				for(j=0; j<len; j++)
				{
					if(data[j] == ','){
					temp1[k] = '\0';
					x = atoi(temp1);
					k=0;
					hf = x%first[0]; 
					h=0;
					totalrun = first[0]*first[1];
					
					while(h<totalrun){
						if(a[hf][c] == (-1)){
							a[hf][c] = x;// cout<<"assigned value in array a["<<hf<<"]["<<c<<"] ="<<a[hf][c]<<endl;
							hf=0; c=0;
							break;
							}	
						else{
							if(c<(first[1]-1))
							c++;
							else{
								hf++;
								c=0;
								if(hf == first[0]){
									hf=0;
									c=0;
								}
							}
						}
						h++;
					}
					}

					else{
					temp1[k] = data[j];
					k++;
					}
				}
					
					temp1[k] = '\0';
                                        x = atoi(temp1);
                                        hf = x%first[0];
					k=0;
					totalrun = first[0]*first[1];
					h=0;
                                        while(h<totalrun){
                                                if(a[hf][c] == (-1)){
                                                        a[hf][c] = x;// cout<<"assigned value in array a["<<hf<<"]["<<c<<"] ="<<a[hf][c]<<endl;
                                                        hf=0; c=0;
                                                        break;
                                                        }
                                                else{
                                                        if(c<(first[1]-1))
                                                        c++;
                                                        else{
                                                                hf++;
                                                                c=0;}
                                                                if(hf == first[0]){
									hf=0;
									c=0;
                                                     			}
							}
							h++;
					}
			}// end of insertion
		
		else if((strcmp(option,s)) == 0)
		{
			const char *templine = line.c_str();
			char data1[strlen(templine)-2];
			string value = (line.substr(2,strlen(templine)-2));
			strcpy(data1, value.c_str());
			int val;
			val = atoi(data1);
			//cout<<"value to be searched ="<<val<<endl;
			hf = val%first[0];
			//cout<<"value of hf in search = "<<hf<<endl;
			j=0;
			c=0;
			totalrun = first[0]*first[1];
			int flag=0;
	
			while(a[hf][c] != (-1))
			{
				//cout<<"inside while loop\n";
				if(a[hf][c] == val)
				{
					flag =1;
					break;
				}
				else
				{
					if(c<(first[1]-1))
					c++;
					else{
						hf++;
						c=0;
						if(hf == first[0])
						{
							hf=0;
							c=0;
						}
					}
				}
				j++;
			}

			if(flag ==1)
			outputFile<<j+1<<" comparisons"<<endl;

			else
			outputFile<<"not found"<<endl;
		}
	}//end of if(i=0) wala else
		
	count++;
	}//end of while

	return 0;
}
