#include<stdio.h>
#include<stdlib.h>



typedef struct node{
	int data;
	struct node* next;
}Node;

void data(int ,Node** );       //function to create a node and insert it at BEGINNING of linked list
void print(Node* );     //function to print the nodes in the linked list

void list(int x,Node** pointerHead )      //function takes the address of the pointer to head
{
	Node* temp;
	temp = (Node*)malloc(sizeof(Node)); //creating memory for a node in heap
	temp->data = x;                     //assigning the data value to its data field 
	temp->next = *pointerHead;	    // assigning cuurent HEAD to its next pointer field by dereferencing the address of ponter to head	
        *pointerHead = temp;			// assign the New head as the created node temp
}

void print(Node* Head)
{
	Node* temp1;
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
	Node* Head = NULL;						//making head as a local variable in main, not a global variable
	int n,i, data;
	printf("No of nodes to be created\n");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		printf("enter the data for the %dth node\n",i+1);
		scanf("%d", &data); 
		list(data, &Head);                                     //passing the address of head(call by reference)
		print(Head);
	}

return 0;
}

