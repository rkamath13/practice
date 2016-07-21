#include<stdio.h>
#include<stdlib.h>
#include "link_list.h"

struct node* MakeNode(int x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
}
	
struct node* Insert(struct node* root, int x)
{
	if(root == NULL)
	{	
		struct node* temp = MakeNode(x);
		root = temp;
		return root;
	}

	else
	{
		struct node* temp = MakeNode(x);
		temp->next = root;
		root = temp;
		return root;
	}
}

void PrintList(struct node* root)
{
	if(root == NULL)
		printf("Empty Linked List\n");
	else
	{
		struct node* temp = root;
		while(temp)
		{
			printf("%d->", temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

struct node* ReturnMid(struct node* root)
{
	if(root == NULL)
	{
		printf("No nodes\n");
		return NULL;
	}
	
	struct node* temp = root;
	int count = 1,i;
	while(temp)
	{
		count++;
		temp = temp->next;
	}
	
	for(i=0;i<count/2;i++)
		root = root->next;
	
	return root;
}
		
