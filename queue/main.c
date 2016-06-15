#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

struct node* MakeNode(int x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	return temp;
}

void EnQueue(int x)
{
	struct node* temp = MakeNode(x);
	if(rear == NULL && front == NULL)
	{
		rear = front = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void DeQueue()
{
	struct node* temp = front;
	if(front == NULL)
		return;
	else
		front = front->next;
	free(temp);
}

int Front()
{
	if(rear == NULL)
	{
		printf("Empty Queue\n");
		return NULL;
	}
	else
		return rear->data;
}

int IsEmpty()
{
	if(rear==NULL && front==NULL)
		return 1;
	else
		return 0;
}

void Print()
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

int main()
{

	EnQueue(3);
	Print();
	EnQueue(9);
	Print();
	EnQueue(4);
	Print();
	DeQueue();
	Print();
	int front_data = Front();
	printf("%d\n", front_data);
return 0;
}


