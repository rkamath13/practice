#include<stdio.h>
#include<stdlib.h>
#include "link_list.h"

#define NODES 5
#define TABLESIZE 100

//O(n) solution with O(n) space
void Duplicate1(struct node* temp)
{
	int hashtable[TABLESIZE] = {0};
	struct node* new = temp->next;
	hashtable[temp->data] = 1;	
	while(new)
	{
		if(hashtable[new->data] == 1)
		{
			struct node* del = new; 
			temp->next = new->next;
			free(del);
		}
		else
		{
			hashtable[new->data] = 1;
			temp = new;
		}
	new = new->next;
	}
}

//O(n^2) solution
void Duplicate2(struct node* root)
{
	while(root)
	{
		struct node* temp = root;
		while(temp->next)
		{
			if(root->data == temp->next->data)
			{
				struct node* del = temp->next;
				temp->next = temp->next->next;
				free(del);
			}
			else
				temp = temp->next;
		}
		root = root->next;
	}
}

int main()
{
	struct node* root = NULL;
	int i,node_data;
	for(i=0;i<NODES;i++)
	{
		printf("Enter the node data\n");
		scanf("%d", &node_data);
		root = Insert(root, node_data);
	}

	PrintList(root);
	Duplicate1(root);
	PrintList(root);
	Duplicate2(root);
	PrintList(root);
return 0;
}
