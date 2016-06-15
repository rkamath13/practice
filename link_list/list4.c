#include<stdio.h>
#include<stdlib.h>

void data(int );       //function to create a node and insert it at the end of linked list
void print(void );     //function to print the nodes in the linked list
void delete(int );

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


void delete(int n)
{
	temp1 = Head;
	Node* temp2;
	int i;
	if(n==1)
	{
		Head = temp1->next;
		free(temp1);
		return;
	}

	for(i=0;i<n-2;i++)
		temp1=temp1->next;      //n-1 node
	
	temp2 = temp1->next;              //nth node

	temp1->next = temp2->next;
	free(temp2);
}

int main()
{
	int n,i, data;
	list(3);
	list(4);
	list(1);
	list(7);
	list(8);
	print();
	delete(3);
	print();
	list(17);
	print();
	delete(2);
	print();
	delete(4);
	print();
	list(21);
	print();
	delete(1);
	print();

return 0;
}

