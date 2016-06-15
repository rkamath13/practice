#include<stdio.h>
#include<stdlib.h>

struct node{
	int x;
	struct node* next;
	struct node* child;
	};

struct node* makenode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->x = data;
	temp->next = NULL;
	int val;
	printf("do you want a child for this node; 0 for no and value if yes");
	scanf("%d", &val);	

	if(val)
	{
		temp->child = makenode(val);
	}
	else
		temp->child = NULL;		
	return temp;
}
	
	
void insert(struct node** head, int data)
{	
	struct node* new = makenode(data);
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

void flatten(struct node** head)
{
	struct node* temp = *(head);
	struct node* tail = *(head);
	while(tail->next != NULL)
		tail = tail->next;	
	
	while(temp != NULL)
	{
		if(temp->child)
		{
			tail->next = temp->child;
			//temp->child = NULL; //unlinking its parent (optional)(should not do if you want to unflatten again)
			tail = tail->next;
			temp = temp->next;
		}

		else
			temp = temp->next;
	}
}

void unflatten(struct node** head)
{
	struct node* temp = *(head);
	struct node* tail = *(head);
	while(tail != NULL)
	{
		if(tail->child)
		{
			struct node* find = tail;
			while(tail->child != find->next)
				find = find->next;
			tail = find;
			break;
		}
		tail = tail->next; 
	}
	
	struct node* new = *(head);
	while(tail->next != NULL)
	{
		if(new->child)
			tail->next = tail->next->next;
		new = new->next;
	}
}

		

int main()
{
	struct node* first = NULL;
	struct node* temp;
	
	int n,i;
	printf("Enter the number of nodes in the main link\n");
	scanf("%d", &n);
	
	for(i=0;i<n;i++)
	{
		int val;
		printf("value of node %d", i);
		scanf("%d", &val);
		insert(&first, val);
	}

	print(first);
	flatten(&first);
	printf("after flattening\n");
	print(first);
	printf("after unflatenning\n");
	unflatten(&first);
	print(first);
return 0;
}
