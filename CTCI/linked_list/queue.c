#include<stdio.h>
#include<stdlib.h>
#include "queue.h"


struct node* EnQueue(struct node* front, struct node* rear, int x)
{
	if(front == NULL && rear == NULL)
	{
		struct node* temp = MakeNode(x);
		front = temp;
		rear = temp;
		return rear;
	}
	else
	{
		struct node* temp = MakeNode(x);
		rear->next = temp;
		rear = temp;
		return rear;
	}
	
}

struct node* DeQueue(struct node* front, struct node* rear)
{
	if(front == NULL)
	{
		printf("queue is Empty\n");
		return;
	}
	struct node* temp = front;
	if(front == rear)
		front = rear = NULL;
	else
	{	
		front = front->next;
	}
	free(temp);
	return front;
}

int IsEmpty(struct node* front)
{
	if(front == NULL)
		return 1;
	else
		return 0;
}

int Top(struct node* front)
{
	if(IsEmpty(front))
		return 0;
	else
		return front->data;
}

void PrintQueue(struct node* front)
{
	PrintList(front);
}


