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
	
struct node* add(struct node* head1, struct node* head2)
{
	struct node* res = NULL;
	struct node* prev = NULL;
	struct node* temp;
	int sum = 0;
	int carry=0;
	
	while(head1!=NULL || head2!=NULL)
	{
		sum = carry + (head1?head1->x:0) + (head2?head2->x:0);
		
		if(sum>=10)
			carry = 1;
		else
			carry = 0;
	
		sum = sum%10;
		
		temp = makenode(sum);
		

		if(res==NULL)
			res = temp;
		else
			prev->next = temp;
			
		prev = temp;
		
		if(head1) head1 = head1->next;
		if(head2) head2 = head2->next;
			
	}
	if(carry>0)
		temp->next = makenode(carry);
	return res;
}	
		
int main()
{
	struct node* first = NULL;
	struct node* second = NULL; 
	struct node* result = NULL;
	
	insert(&first, 9);
	insert(&first, 9);
	insert(&first, 9);
	insert(&first, 9);
	insert(&first, 9);

	insert(&second, 9);
	insert(&second, 9);
	insert(&second, 9);

	
	print(first);
	print(second);
	result = add(first, second);
	print(result);
return 0;
}
