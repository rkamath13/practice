#include<stdio.h>
#include<stdlib.h>
#include "link_list.h"

#define NODES 8

//Iterative solution
void Solution1(struct node* root, int k)
{
	if(k>NODES)
	{
		printf("Invalid K value\n");
		return;
	}
	
	else
	{
		struct node* runner = root;
		int count = k;
		while(count)
		{
			runner = runner->next;
			count--;
		}
		
		while(runner)
		{
			root = root->next;
			runner = runner->next;
		}
		printf("%dth to the last element is %d\n",k, root->data);
	}
} 

//Recursive Solution
int Solution2(struct node* root, int k)
{
	if(root == NULL)
		return 0;
	int index = Solution2(root->next, k)+1;
	if(index == k)
		printf("%dth to the last element is %d\n",k, root->data);
	return index;
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
	printf("Enter k\n");
	scanf("%d", &k);
	PrintList(root);
	Solution1(root, k);
	Solution2(root, k);
return 0;
}
