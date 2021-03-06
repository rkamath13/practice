#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node* next;
};


struct node* makenode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));	
	temp->data = data;
	temp->next = NULL;
	return temp;
}
	
void insert(struct node** head, int data)
{
	struct node* temp = makenode(data);
	temp->next = *(head);
	*(head) = temp;
}

void print(struct node* head)
{
	while(head != NULL)
	{
		printf("%d\t",head->data);
		head = head->next;
	}
	printf("\n");
}

struct node* ktolast(struct node* head, int k)
{
	int count = 0, i=0;
	struct node* temp = head;
	struct node* temp4 = head;
	while(temp->next != NULL && temp4->next != NULL)
	{
		if(count == k)
		{
			temp = temp->next;
			temp4 = temp4->next;
			i++;
		}
		else
		{
			temp = temp->next;
			count++;
			i++;
		}
	}
	if(i<k)
		return NULL;
	else
		return temp4;
}

int main()
{
	struct node* head = NULL;
	insert(&head, 4);
	insert(&head, 9);
	insert(&head, 14);
	insert(&head, 23);
	insert(&head, 98);
	insert(&head, 32);
	insert(&head, 56);
	insert(&head, 41);
	
	print(head);
	int k;
	printf("enterk\n");
	scanf("%d", &k);
	struct node* temp = ktolast(head, k);
	if(temp != NULL)
		printf("answer is: %d\n", temp->data);
	else
		printf("out of bounds\n");
	
return 0;
}


