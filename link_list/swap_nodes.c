#include<stdio.h>
#include<stdlib.h>

struct node{
	int x;
	struct node* next;
};

struct node* makenode(int n)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->x = n;
	new->next = NULL;
	return new;
}

void insert(struct node** head, int data)
{
	
	struct node* new = makenode(data);	
	new->next = *head;
	*head = new;
}

void print(struct node* head)
{
	struct node *temp = head;
	while(temp)
	{
		printf("%d\t", temp->x);
		temp = temp->next;
	}
	printf("\n");
} 

void swap(struct node** head, int x, int y)
{
	if(x==y)
		return;
	struct node* temp;
	struct node* prevX=NULL; 
	struct node* prevY;
	struct node* currX=NULL; 
	struct node* currY;
	
	currX = *(head);
	while(currX!=NULL && currX->x!=x)
	{
		prevX = currX;
		currX = currX->next;
	}
	
	while(currY!=NULL && currY->x!=y)
	{
		prevY = currY;
		currY = currY->next;
	}				
	
	if(currX == NULL || currY == NULL)
	{
		printf("integers entered not found\n");
		return;
	}
	
	if(prevX!= NULL)
		prevX->next = currY;
	else
		*(head) = currY;
	
	if(prevY!= NULL)
		prevY->next = currX;
	else
		*(head) = currX;
	temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
}

		
int main()
{
	struct node* first = NULL;
	
	insert(&first, 60);
	insert(&first, 6);
	insert(&first, 90);
	insert(&first, 13);
	insert(&first, 19);
	insert(&first, 31);
	
	printf("unswapped list\n");
	print(first);
	swap(&first, 6, 60);
	printf("swapped list\n");
	print(first);
	
	
return 0;
}
