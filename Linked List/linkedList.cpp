//linked list


#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>

using namespace std;


struct Node{
	
	struct Node *next;
	int data;
};

struct Node *createNewNode(){
	
	struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
	return temp;
}

struct Node* insertIntoLinkedList(struct Node *head,int data,char *fileName){
	
	fstream outputFile;
	outputFile.open(fileName,ios::out|ios::app);
	struct Node *temp,*node;
	if(head==NULL){
		temp = createNewNode();
		temp->data = data;
		temp->next= NULL;
		head = temp;
		outputFile<<data;
	}
	else{
		temp = head;
		struct Node *par= temp;
		while(temp!=NULL){
			par = temp;
			temp = temp->next;
		}
		node = createNewNode();
		node->data = data;
		node->next = NULL;
		par->next = node;
		outputFile<<","<<data;
	}
	return head;
	
}


void print(struct Node* head,char* fileName){
	
	fstream outputFile;
	outputFile.open(fileName,ios::out|ios::app);
	struct Node* temp;
	temp = head;
	int i=0;
	while(temp!=NULL){
		if(i==0){
			outputFile<<temp->data;
		}
		else
			outputFile<<","<<temp->data;
		
		temp = temp->next;
		
		i++;
	}
	outputFile<<endl;
}

struct Node* updateLinkedList(struct Node* head, int x,int y,char *fileName){
	
	struct Node *temp = head;
	int flag= 0;
	fstream outputFile;
	outputFile.open(fileName,ios::out|ios::app);
	while(temp!=NULL){
		if((temp->data)==x){
			flag= 1;
			break;
		}
		temp= temp->next;
	}
	
	if(flag==1){
		temp->data= y;
		print(head,fileName);
	}
	else{
		outputFile<<"not found"<<endl;
	}
	
	return head;
}

struct Node* del(struct Node* head,int x,char *fileName){
	struct Node *temp = head;
	struct Node *prev= head;
	int flag= 0;
	fstream outputFile;
	outputFile.open(fileName,ios::out|ios::app);
	
	while(temp!=NULL){
		
		if(temp->data==x){
			flag= 1;
			break;
			
		}
			
		
		prev = temp;
		temp= temp->next;
	}
	
	
	if(flag==1){
		prev->next = temp->next;
		print(head,fileName);
	}
	else{
		outputFile<<"not found"<<endl;
	}
	
	return head;
	
}

std::string line;
int main(int argc,char *argv[]){
	
	fstream inputFile,outputFile;
	struct Node *head;
	head = NULL;
	inputFile.open(argv[1],ios::in);
	outputFile.open(argv[2],ios::out|ios::app);
	//int i;
	while(std::getline(inputFile,line)){
		
		const char *options = (line.substr(0,1)).c_str();
		const char *i = "i";
		const char *u = "u";
		const char *d = "d";
	//	const char *p = "p";
		
		if(strcmp(options,i)==0){
			
			const char *tempLine = line.c_str();
			int len = strlen(tempLine);
			const char *data = (line.substr(2,len-2)).c_str();
			char temp[10];
			int i,j=0;
			int lendata = strlen(data);
			for(i=0;i<lendata;i++){
				if(data[i]==','){
					temp[j] = '\0';
					head =insertIntoLinkedList(head,atoi(temp),argv[2]);
					j=0;
					
					
				}
				
				else{
					temp[j] = data[i];
					j++;
				}
			}
			temp[j] = '\0';
			head = insertIntoLinkedList(head,atoi(temp),argv[2]);
			outputFile<<endl;
		}
		else if(strcmp(options,u)==0){
			const char *tempLine = line.c_str();
			const char *data = (line.substr(2,strlen(tempLine)-2)).c_str();
			char temp[10];
			int x,y;
			int i,j=0;
			int lendata = strlen(data);
			for(i=0;i<lendata;i++){
				if(data[i]==','){
					temp[j] = '\0';
					x = atoi(temp);
					j=0;
				}
				else{
					temp[j] = data[i];
					j++;
				}
				
			}
			temp[j] = '\0';
			y = atoi(temp);
			head = updateLinkedList(head,x,y,argv[2]);
		}
		else if(strcmp(options,d)==0){
			
			const char *tempLine = line.c_str();
			const char *data = (line.substr(2,strlen(tempLine)-2)).c_str();
			int x = atoi(data);
			head = del(head,x,argv[2]);
			
			
		}
		
		else {
			
			print(head,argv[2]);
		}
	}
	
}
