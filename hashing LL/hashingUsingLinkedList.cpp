//hasing using linked list


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

struct Node* insertIntoLinkedList(struct Node *head,int data){
	

	struct Node *temp,*node;
	if(head==NULL){
		temp = createNewNode();
		temp->data = data;
		temp->next= NULL;
		head = temp;
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
	}
	return head;
	
}


int searchIntoLinkedList(struct Node* head, int data){
	
	int comparisons = 0;
	struct Node* temp = head;
	while(temp!=NULL){
		if(temp->data==data){
			comparisons++;
			return comparisons;
		}
		temp = temp->next;
		comparisons++;
	}
	
	return 0;
}

string line;
int main(int argc,char *argv[]){
	
	struct Node* array[200];
	fstream inputFile,outputFile;
	struct Node *head;
	head = NULL;
	inputFile.open(argv[1],ios::in);
	outputFile.open(argv[2],ios::out);
	int i;
	int size = 0;
	
	while(getline(inputFile,line)){
			
		if(size==0){
			const char *char_size = line.c_str();
			size = atoi(char_size);
			for(i=0;i<size;i++){
				array[i] = NULL;
			}
			continue;
		}
		const char *options = (line.substr(0,1)).c_str();
		
		const char *i = "i";
		const char *s = "s";

		
		if(strcmp(options,i)==0){
			
			const char *tempLine = line.c_str();
			char data[strlen(tempLine)-2];
			string new_line  = line.substr(2,strlen(tempLine)-2);
			strcpy(data,new_line.c_str());

			
			char temp[10];
			int i,j=0;
			int len = strlen(data);
			for(i=0;i<len;i++){
				if(data[i]==','){
					temp[j] = '\0';
				
					int linked_list_data = atoi(temp);
					head = array[linked_list_data%size];
					head =insertIntoLinkedList(head,linked_list_data);
					array[linked_list_data%size] = head;
					j=0;
					
				}
				
				else{
					temp[j] = data[i];
					j++;
				}
			}
			temp[j] = '\0';
			int linked_list_data = atoi(temp);
			head = array[linked_list_data%size];
			head =insertIntoLinkedList(head,linked_list_data);
			array[linked_list_data%size] = head;
			
			
		}
		else if(strcmp(options,s)==0){
			const char *tempLine = line.c_str();
			const char *data = (line.substr(2,strlen(tempLine)-2)).c_str();
			int x = atoi(data);
			head = array[x%size];
			int comparisons = searchIntoLinkedList(head,x);
			if(comparisons==0)
				outputFile<<"not found"<<endl;
			else
				outputFile<<comparisons<<" comparisons"<<endl;
			
		}
	}
	
	return 0;
	
}
