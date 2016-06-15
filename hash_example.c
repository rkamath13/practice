#include<stdio.h>
#include<stdlib.h>

int A[10] = {0};

struct node{
	int number;
	struct node* next;
};

struct node* hash_fun(int a)
{
struct node* top;
struct node* start;
struct node* new;

	if(a%2==0 && A[2]==0)
	{
			A[2] = a;
			
			int *temp = &A[2];
			top = (struct node*)malloc(sizeof(struct node));
		 	start = top;
			start->number = *temp;
			start->next = NULL;
	}
	else if(a%2 == 0 && A[2]!=0)
	{
			new = (struct node*)malloc(sizeof(struct node));
			new->number = a;
			new->next = NULL;
			start->next = new;
			start = new;
	}
	else
		A[3] = 1;
return top;
}

void print(struct node* temp)
{
	while(temp)
	{
		printf("%d->", temp->number);
		temp = temp->next;
	}
	printf("\n");
}					
			
int main()
{
	int count = 7;
	while(count)
	{
		int num;
		printf("Enter a number\n");
		scanf("%d",&num);
		struct node* temp;
		temp = hash_fun(num);
		print(temp);
		count--;
	}
return 0;
}
