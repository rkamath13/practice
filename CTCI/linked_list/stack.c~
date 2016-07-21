#include<stdio.h>
#include<stdlib.h>
#include "stack.h"


struct node* Push(struct node* root, int x)
{
	struct node* temp = Insert(root,x);
	return temp;
}

struct node* Pop(struct node* root)
{
	if(root == NULL)
	{
		printf("stack is Empty\n");
		return;
	}
	struct node* temp = root;
	root = root->next;
	free(temp);
	return root;
}

int IsEmpty(struct node* root)
{
	if(root == NULL)
		return 1;
	else
		return 0;
}

int Top(struct node* root)
{
	if(IsEmpty(root))
		return 0;
	else
		return root->data;
}

void PrintStack(struct node* root)
{
	PrintList(root);
}


