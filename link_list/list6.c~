#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insert(char );       //function to create a node and insert it at the end of linked list
void print(void );     //function to print the nodes in the linked list
void delete(int );
void reverse();

typedef struct node{
	char data;
	struct node* next;
}Node;

Node* Head = NULL;
//Node* Head2 = NULL;
Node* temp;
Node* temp1; 

void insert(char x)
{
	temp = (Node*)malloc(sizeof(Node)); //creating memory for a node in heap
	temp->data = x;                     //assigning the data value to its data field 
	temp->next = NULL;	            // assigning a NULL pointer to its next pointer field	
	if(Head == NULL)		    // When the list is empty, initialize Head1 with the newly created node
		Head = temp;
	else
	{
		temp1 = Head;		        //use another pointer to traverse the list and initialize it with Head1	
		while(temp1->next)
			temp1 = temp1->next;
		temp1->next = temp;		//make a link between the newly created node and the last member of the existing Llist
	}
}


void print()
{
	
	if(Head == NULL)
	{
		printf("list empty\n");
		return;
	}
	
		temp1 = Head;
		while(temp1 != NULL)
		{
			printf("%c->",temp1->data);
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

void reverse()
{
	Node* prev;
	Node* ahead;
	Node* curr;
	curr = Head;
	prev = NULL;
	ahead = Head;
	while(curr != NULL)
	{
		ahead = ahead->next;		
		curr->next = prev;
		prev = curr;		
		curr = ahead;
	}
	Head = prev;
}		
/*
int compare(int n)
{
	temp = Head1;
	temp1 = Head2;
	int i = 0;
	while(i!=count/2)
	{
*/	
				

int main()
{
	int n,i, data;
	char* str;
	str = malloc(256);
	printf("enter the string you want to check\n");
	scanf("%s", str);
	//printf("%s\n", str); 
	n = strlen(str);
	for(i=0;i<n;i++)
		insert(str[i]);
	print();
	reverse();
	print();
		

return 0;
}

