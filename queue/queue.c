#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

struct node* MakeNode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void EnQueue(struct node* rear,struct node* front, int data)
{
	struct node* temp = MakeNode(data);
	if(rear == NULL && front == NULL)
	{
		rear = front = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void DeQueue(struct node* front)
{
	if(front == NULL)
		return;
	else
		front = front->next;
	free(front);
}

int Front(struct node* rear)
{
	if(rear == NULL)
	{
		printf("Empty Queue\n");
		return NULL;
	}
	else
		return rear->data;
}

int IsEmpty(struct node* rear, struct node* front)
{
	if(rear==NULL && front==NULL)
		return 1;
	else
		return 0;
}

void Print(struct node* front)
{
	if (front == NULL)
		return;
	else
	{
		while(front->next)
		{
			printf("%d ", front->data);
			front = front->next;
		}
	}
	printf("\n");
}
