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
		printf("%d->", temp->x);
		temp = temp->next;
	}
	printf("\n");
}

int delmid(struct node* mid)
{
	if(mid == NULL || mid->next == NULL)
		return 0;
	struct node* temp;
	temp = mid->next;
	mid->x = temp->x;
	mid->next = temp->next;
	free(temp);
	return 1;
}	
	

int main()
{
	struct node* head = NULL;
	
	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	insert(&head, 5);
	insert(&head, 6);
	insert(&head, 7); 

	print(head);
	int res = delmid(head->next->next->next);
	print(head);
return 0;
}
	
