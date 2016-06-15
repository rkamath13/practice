#include<stdio.h>
#include<stdlib.h>

int adjmat[10][10];
char nodemap[10];

struct node{
	char n;
	struct node* next;
};

to_adjlist(int N)
{
	struct node* ptr[N];
	int i,j;
	for(i=0;i<N;i++)
	{
		ptr[i] = (struct node*)malloc(sizeof(struct node));
		ptr[i]->n = ' ';
		ptr[i]->next = NULL;
	}
	
	for(i=0;i<N;i++)
	{
		struct node* last = ptr[i];
		for(j=0;j<N;j++)
		{
		 	if(i!=j && adjmat[i][j]==1)
			{	
				struct node* tmp = (struct node*)malloc(sizeof(struct node));
				tmp->n = j+65;
				tmp->next = NULL; 
				last->next = tmp;
				last = tmp;
			}
		}
	}
	
	for(i=0;i<N;i++)
	{
		struct node* tmp = ptr[i];
		while(tmp)
		{
			printf("%c->", tmp->n);
			tmp = tmp->next;
		}
		printf("NULL");
		printf("\n");
	}
}

int main()
{
	int N;
	printf("Enter the no of nodes\n");
	scanf("%d", &N);
	
	int i,j;
		
	adjmat[N][N];
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("connection between %d and %d ",i,j);
			scanf("%d", &adjmat[i][j]);	
		}
	}

	to_adjlist(N);
return 0;
}


