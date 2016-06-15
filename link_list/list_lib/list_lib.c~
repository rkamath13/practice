#include<stdio.h>
#include<stdlib.h>
#include "list_lib.h"

typedef struct node{
	int data;
	struct node* next;
}Node;

Node* Head = NULL;

void insert_tail(int x)
{
	Node* temp;
	Node* temp1;
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

void insert_head(int x )      //function takes the address of the pointer to head
{
	Node* temp;
	temp = (Node*)malloc(sizeof(Node)); //creating memory for a node in heap
	temp->data = x;                     //assigning the data value to its data field 
	temp->next = Head;	    // assigning cuurent HEAD to its next pointer field by dereferencing the address of ponter to head	
        Head = temp;			// assign the New head as the created node temp
}


void print()
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


void delete(int n)
{
	Node* temp1;
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
		

