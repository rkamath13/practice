#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};


struct node* makenode(int data)
{
	struct node* temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void cyclic(struct node** head)
{
	struct node* tortoise = *head;
	struct node* hare = *head;
	
	while(tortoise!=NULL && hare != NULL)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if(tortoise == hare)
		{
			printf("there is a cycle\n");
			break;
		}
		
	}
	if(tortoise == NULL || hare == NULL)
		printf("no cycle\n");
	
}

void print(struct node* head)
{
	while(head != NULL)
	{
		printf("%d\t", head->data);
		head = head->next;
	}
	printf("\n");
}

int main()
{
	
	struct node* head = makenode(20);
	head->next = makenode(40);
	head->next->next = makenode(35);
	head->next->next->next = makenode(12);
	head->next->next->next->next = makenode(67);
	head->next->next->next->next->next = head->next;
	cyclic(&head);
	
}

	


