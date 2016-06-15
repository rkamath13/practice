#include<stdio.h>
#include<stdlib.h>



typedef struct node{
	int data;
	struct node* next;
}Node;

void data(int, int);       //function to create a node and insert it at BEGINNING of linked list
void print(void);     //function to print the nodes in the linked list
int is_empty();

Node* Head = NULL;

void list(int x, int n)      //function takes the address of the pointer to head
{
	Node* temp;
	temp = (Node*)malloc(sizeof(Node)); //creating memory for a node in heap	
	temp->data = x;
	temp->next = NULL;
	int i;
	if(n==1)
	{	
		temp->next = Head;	   	
	        Head = temp;
		return;			
	}
	int k = is_empty();
	if(k==1)
	{
		printf("list is empty, enter at position 1 first\n");
		return;
	}
	Node* temp2 = Head;
	for(i=0;i<n-2;i++)                 //loop to go to the n-1 node
		temp2=temp2->next;

	temp->next = temp2->next;    // link of n-1 node to be assigned to the link of new node
	temp2->next = temp;	     // new node address to be assigned as the link of the n-1 node	
	
	
}

void print()
{
	Node* temp1;
	temp1 = Head;
	while(temp1 != NULL)
	{
		printf("%d->",temp1->data);
		temp1 = temp1->next;
	}
	printf("\n");
}

int is_empty()
{
	if(Head ==NULL)
		return 1;
	else
		return 0;
}

int main()
{
							//making head as a local variable in main, not a global variable
	int n,i, data, pos;
	printf("No of nodes to be created\n");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		printf("enter the data for the %dth node\n",i+1);
		scanf("%d", &data); 
		printf("enter the position for the %dth node\n",i+1);
		scanf("%d", &pos);		
		list(data, pos);                                     //passing the address of head(call by reference)
		print();
	}

return 0;
}

