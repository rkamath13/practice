#include<stdio.h>
#include<stdlib.h>
#include "link_list.h"

#define NODES 8

void Solution(struct node* );


void Solution(struct node* mid)
{
	struct node* temp = mid->next;
	mid->data = temp->data;
	mid->next = temp->next;
	free(temp);
}

int main()
{
	struct node* root = NULL;
	int i,node_data,k;
	for(i=0;i<NODES;i++)
	{
		printf("Enter the node data\n");
		scanf("%d", &node_data);
		root = Insert(root, node_data);
	}
	
	PrintList(root);

	struct node* mid = ReturnMid(root);
	printf("The middle node is %d\n", mid->data);
	Solution(mid);
	
	PrintList(root);
return 0;
}
