#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int front = -1, rear = -1;

void enque(FILE *file,int queue[],int size, int data)
{
	if(rear-front == size-1)
	{
		fprintf(file,"overflow\n");
	}
	else 
	{
		if(front == -1)
			front = 0;
		rear = rear + 1;
		queue[rear] = data;
		fprintf(file,"%d added\n",data);
	}
}
void deque(FILE *file,int queue[])
{
	if(front == -1 || front > rear)
	{
		fprintf(file,"underflow\n");
		return;
	}
	else
	{	
		fprintf(file,"removed %d\n",queue[front]);
		front = front + 1;
	}
}

int main(int argc, char *argv[])
{
	FILE *ifile = fopen(argv[1],"r");
	if(ifile==NULL)
		return -1;
	FILE *ofile = fopen(argv[2],"w+");
	if(ofile==NULL)
		return -1;
	int size;
	fscanf(ifile,"%d",&size);

	int queue[size];

	char str[80];
	int val;
	
	while(!feof(ifile)) 
	{
		fscanf(ifile,"%s %d",str,&val);
		if (strcmp(str,"enq")==0)
			enque(ofile,queue,size,val);

		else if(strcmp(str,"print")==0)
		{	

			int i;
			for(i=front;i<=rear;i++)
				fprintf(ofile,"%d ",queue[i]);
			fprintf(ofile,"\n");
		}
		else
			deque(ofile,queue);

		
	}
	fclose(ifile);
	fclose(ofile);
	return 0;
}
