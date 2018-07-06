#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;


//Node Structure
struct Node{
	
	struct Node *left;
	struct Node *right;
	int data;
};

//Create New Node
struct Node *createNewNode(int data){
	
	struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
};

//Insert
struct Node* insertBST(struct Node *node, int data){

if(node == NULL)
return createNewNode(data);

if(data < node->data)
node->left = insertBST(node->left, data);

else if(data > node->data)
node->right = insertBST(node->right, data);

return node;
}

//Search
struct Node* searchBST(struct Node *node, int data, FILE *output, int level){

if(node == NULL){
fprintf(output,"%d not found\n",data);
return node;
}

else if(data == node->data){
fprintf(output,"%d found at level %d\n",data,level);
return node;
}

else if(data < node->data)
node->left = searchBST(node->left, data, output, ++level);

else if(data > node->data)
node->right = searchBST(node->right, data, output, ++level);

return node;

}

//In order Sucessor
struct Node* inorderSuc(struct Node *current){
while(current->left != NULL)
current = current->left;

return current;
}

//Delete
struct Node* deleteBST(struct Node *node, int data){

if(node == NULL)
return node;

else if(data < node->data)
node->left = deleteBST(node->left, data);

else if(data > node->data)
node->right = deleteBST(node->right, data);

else{
	// one or no child
	if (node->left == NULL)
        {
            struct Node *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            struct Node *temp = node->left;
            free(node);
            return temp;
        }
 
	// Two children
        // Get the inorder successor (smallest in the right subtree)
        struct Node *temp = inorderSuc(node->right);
 
        // Copy the inorder successor's content to this node
        node->data = temp->data;
 
        // Delete the inorder successor
        node->right = deleteBST(node->right, temp->data);

}
return node;
}//end of deleteBST function

//Pre order
void preorder(struct Node *root, FILE *output, int last){
if(root != NULL){
	if(last == 0){
		fprintf(output,"%d",root->data);
		preorder(root->left,output,1);
		preorder(root->right,output,1);
	}

	else{
		fprintf(output,", %d",root->data);
		preorder(root->left,output,1);
		preorder(root->right,output,1);
	}
}
}

//Main function
int main(int argc, char *argv[]){

FILE *input;
FILE *output;
struct Node *root = NULL;
int data, count=0;
char ch;
char *op = (char*)"i";
input = fopen(argv[1],"r");
if(input==NULL)
return -1;

output = fopen(argv[2],"w");
if(output==NULL)
return -1;

while(!feof(input)){

fscanf(input,"%s ",op);
if((strcmp(op,"i")) == 0){
	do{
		fscanf(input,"%d%c ",&data,&ch);
		//cout<<"data = "<<data<<"\n";
		
		if(count == 0){
		root = insertBST(root, data);
		//preorder(root,output,0);
		//fprintf(output,"\n"); 
		count = 1;
		}
		
		else{
		insertBST(root, data);
		//preorder(root,output,0);
		//fprintf(output,"\n"); 
		}
	}while(ch==',');
	preorder(root, output, 0);
	count=0;
	fprintf(output,"\n");
}

else if((strcmp(op,"s")) == 0){
	fscanf(input,"%d\n",&data);
	root = searchBST(root, data, output, 0);
}

else if((strcmp(op,"a")) == 0){
	fscanf(input,"%d\n",&data);
	insertBST(root, data);
	preorder(root, output, 0);
	fprintf(output,"\n");
}

else if((strcmp(op,"d")) == 0){
	fscanf(input,"%d\n",&data);
	root = deleteBST(root, data);
	preorder(root, output, 0);
	fprintf(output,"\n");
}

else
exit(1);

} // end of while(!foef(input))
fclose(input);
fclose(output);
return 0;
}

