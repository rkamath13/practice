#include<stdio.h>
#include<stdlib.h>

struct node{
	int x;
	struct node* next;
	struct node* child;
	};

struct node* makenode(int data, int ch)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->x = data;
	temp->next = NULL;
	if(ch)
	{
		temp->child = makenode(ch, 0);
	}
	else
		temp->child = NULL;		
	return temp;
}
	
	
void insert(struct node** head, int data, int child)
{	
	struct node* new = makenode(data, child);
	new->next = *head;
	*head = new;
}

void print(struct node* head)
{
	struct node* temp = head;

	while(temp != NULL)
	{
		printf("%d->",temp->x);
		if(temp->child)
			printf("%d\t",temp->child->x);
		else
			printf("NULL\t");
		temp = temp->next;
	}
	printf("\n");
}


int main()
{
	struct node* first = NULL;
	struct node* temp;
	
	insert(&first, 6,1);
	insert(&first, 28,4);
	insert(&first, 14,0);
	insert(&first, 1,5);
	insert(&first, 87,56);
	insert(&first, 11,0);


	print(first);
return 0;
}
