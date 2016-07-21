#include<stdio.h>
#include "queue.h"

int main()
{
	struct node* front = NULL;
	struct node* rear = NULL;
	rear = EnQueue(front,rear,10);
	rear = EnQueue(front,rear,14);
	rear = EnQueue(front,rear,5);
	rear = EnQueue(front,rear,7);
	rear = EnQueue(front,rear,56);
	
	struct node* temp = rear;
	while(temp)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
	//PrintQueue(front);
	//front = DeQueue(front);
	//front = DeQueue(front);
	//PrintQueue(front);
return 0;
}
