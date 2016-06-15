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

//small to big order
struct node* mergeAs(struct node* head1, struct node* head2)
{
	struct node* res = NULL;
	struct node* temp;
	struct node* prev = NULL;
	
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->x <= head2->x)
		{
			temp = makenode(head1->x);
			if(res == NULL)
				res = temp;
			else
				prev->next = temp;
			prev = temp;
			
			if(head1) head1 = head1->next;
		}

		else
		{
			temp = makenode(head2->x);
			if(res == NULL)
				res = temp;
			else
				prev->next = temp;
			prev = temp;
			
			if(head2) head2 = head2->next;
		}
	}
	
	while(head1 != NULL)
	{
		temp = makenode(head1->x);
		if(res == NULL)
			res = temp;
		else
			prev->next = temp;
		prev = temp;
			
		if(head1) head1 = head1->next;
	}
	
	while(head2 != NULL)
	{
		temp = makenode(head2->x);
		if(res == NULL)
			res = temp;
		else
			prev->next = temp;
		prev = temp;
			
		if(head2) head2 = head2->next;
	}
return res;
}

//big to small order
struct node* mergeDes(struct node* head1, struct node* head2)
{
	struct node* res = NULL;
	struct node* temp;
	
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->x <= head2->x)
		{
			temp = makenode(head1->x);
			if(res == NULL)
				res = temp;
			else
				temp->next = res;
			res = temp;
			
			if(head1) head1 = head1->next;
		}

		else
		{
			temp = makenode(head2->x);
			if(res == NULL)
				res = temp;
			else
				temp->next = res;
			res = temp;
			
			if(head2) head2 = head2->next;
		}
	}
	
	while(head1 != NULL)
	{
		temp = makenode(head1->x);
		if(res == NULL)
			res = temp;
		else
			temp->next = res;
		res = temp;
			
		if(head1) head1 = head1->next;
	}
	
	while(head2 != NULL)
	{
		temp = makenode(head2->x);
		if(res == NULL)
			res = temp;
		else
			temp->next = res;
		res = temp;
			
		if(head2) head2 = head2->next;
	}
return res;
}
				
		

		
int main()
{
	struct node* first = NULL;
	struct node* second = NULL; 
	struct node* result = NULL;
	
	insert(&first, 60);
	insert(&first, 45);
	insert(&first, 13);
	insert(&first, 13);
	insert(&first, 6);

	insert(&second, 13);
	insert(&second, 6);
	insert(&second, 6);

	
	printf("first sorted list\n");
	print(first);
	printf("second sorted list\n");
	print(second);
	printf("Ascending merged sorted list\n");
	result = mergeAs(first, second);
	print(result);
	printf("Descending merged sorted list\n");
	result = mergeDes(first, second);
	print(result);
return 0;
}
