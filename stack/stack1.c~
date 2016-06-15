#include<stdio.h>
#include<stdlib.h>

void push(int );
void pop(void );
int top(void );
int is_empty(void );
void print();
  

typedef struct node{
	int data;
	struct node *next;
}Node;

Node* Top;

void push(int x)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = x;
	temp->next = Top;
	Top = temp;
}

void pop()
{
	if(Top == NULL)
	{
		printf("stack is empty\n");
		return;
	}
	Node* temp;
	temp = Top;
	Top = temp->next;
	free(temp);
}

int is_empty()
{
	if(Top == NULL)
		return 0;
	return 1;
}

int top()
{
	if(is_empty())
		return Top->data;
	else
	{
		printf("Stack is empty\n");
		return;
	}
}	

void print()
{
	if(!is_empty())
	{
		printf("Stack is empty\n");
		return;
	}
	Node* temp = Top;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
	

int main()
{
	push(1);
	push(4);
	push(7);
	push(8);
	push(17);
	print();
	pop();
	print();


	

return 0;
}

