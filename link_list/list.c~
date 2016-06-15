#include<stdio.h>
#include<stdlib.h>

void data(int );       //function to create a node and insert it at the end of linked list
void print(void );     //function to print the nodes in the linked list

typedef struct node{
	int data;
	struct node* next;
}Node;

Node* Head = NULL;
Node* temp;
Node* temp1; 

void list(int x)
{
	temp = (Node*)malloc(sizeof(Node)); //creating memory for a node in heap
	temp->data = x;                     //assigning the data value to its data field 
	temp->next = NULL;	            // assigning a NULL pointer to its next pointer field	
	if(Head == NULL)		    // When the list is empty, initialize head with the newly created node
		Head = temp;
	else
	{
		temp1 = Head;		        //use another pointer to traverse the list and initialize it with head	
		while(temp1->next)
			temp1 = temp1->next;
		temp1->next = temp;		//make a link between the newly created node and the last member of the existing Llist
	}
}

void print()
{
	temp1 = Head;
	while(temp1 != NULL)
	{
		printf("%d->",temp1->data);
		temp1 = temp1->next;
	}
	printf("\n");
}


int main()
{
	int n,i, data;
	printf("No of nodes to be created\n");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		printf("enter the data for the %dth node\n",i+1);
		scanf("%d", &data); 
		list(data);
		print();
	}

return 0;
}

