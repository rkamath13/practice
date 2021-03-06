#include<stdio.h>
#include<stdlib.h>
#include "bst.h"
#include "stack.h"


//----------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
//--------------------------------------------------------------------------//

struct bstnode* makenode(int x)
{

	struct bstnode* temp = (struct bstnode*)malloc(sizeof(struct bstnode));
	temp->data = x;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

//-------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//


struct bstnode* insert(struct bstnode* rootptr, int data)
{
	if(rootptr == NULL)
	{
		rootptr = makenode(data);
		return rootptr;
	}
	else if(rootptr->data >= data)
		rootptr->left = insert(rootptr->left, data);

	else if (rootptr->data < data) 
		rootptr->right = insert(rootptr->right, data);
		
	return rootptr;
}

//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//-----------------------------------------------------------------------//


int findnode(struct bstnode* rootptr, int data)
{
	if(rootptr == NULL)
		return 0;
	else if(rootptr->data == data)
		return 1;
	else if(data > rootptr->data)
		return findnode(rootptr->right, data);
	else
		return findnode(rootptr->left, data);

}

//-------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//

void Search(struct bstnode* rootptr)
{

	int d, ret;
	printf("Enter the number you want to find\n");
	scanf("%d", &d);

	ret = findnode(rootptr, d);
	if(ret == 1)
		printf("node found\n");
	else
		printf("node not present\n");
}

//---------------------------------------------------------------------------//
//-------------------------------------------------------------------------//
//------------------------------------------------------------------------//

void FindMin(struct bstnode* rootptr)
{
	if(rootptr == NULL)
	{
		printf("Tree is empty\n");
		
	}
	
	while(rootptr->left)
		rootptr = rootptr->left;
	printf("Minimum Value of this BST is : %d\n", rootptr->data);
}

//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//
//-------------------------------------------------------------------------//

void FindMax(struct bstnode* rootptr)
{
	if(rootptr == NULL)
	{
		printf("Tree is empty\n");
	
	}
	
	while(rootptr->right)
		rootptr = rootptr->right;
	printf("Maximum Value of this BST is : %d\n", rootptr->data);
}

//--------------------------------------------------------------------------//
//-------------------------------------------------------------------------//
//-------------------------------------------------------------------------//

void PreOrder(struct bstnode* rootptr)
{
	if(rootptr == NULL)
		return;
	
	printf("%d\t", rootptr->data);
	PreOrder(rootptr->left);
	PreOrder(rootptr->right);

}

//--------------------------------------------------------------------------//
//-------------------------------------------------------------------------//
//-------------------------------------------------------------------------//

void InOrder(struct bstnode* rootptr)
{
	if(rootptr == NULL)
		return;
	
	InOrder(rootptr->left);
	printf("%d\t", rootptr->data);
	InOrder(rootptr->right);

}

//--------------------------------------------------------------------------//
//-------------------------------------------------------------------------//
//-------------------------------------------------------------------------//

void PostOrder(struct bstnode* rootptr)
{
	if(rootptr == NULL)
		return;
	
	PostOrder(rootptr->left);
	PostOrder(rootptr->right);
	printf("%d\t", rootptr->data);

}

//--------------------------------------------------------------------------//
//-------------------------------------------------------------------------//
//-------------------------------------------------------------------------//

int Height(struct bstnode* rootptr)
{
	if(rootptr == NULL)
		return 0;
	else
	{
		int lheight = Height(rootptr->left);
		int rheight = Height(rootptr->right);
	
		if(lheight > rheight)
			return lheight+1;
		else
			return rheight+1;
	}
}

//--------------------------------------------------------------------------//
//-------------------------------------------------------------------------//
//-------------------------------------------------------------------------//		

void LevelOrder(struct bstnode* rootptr)
{
	int height = Height(rootptr);
	int i;
	for(i=0;i<=height;i++)
		PrintLevel(rootptr, i);
}

//--------------------------------------------------------------------------//
//-------------------------------------------------------------------------//
//-------------------------------------------------------------------------//

void PrintLevel(struct bstnode* rootptr, int level)
{
	if(rootptr == NULL)
		return;
	else if (level == 1)
		printf("%d\t", rootptr->data);
	else
	{
		PrintLevel(rootptr->left, level-1);
		PrintLevel(rootptr->right, level-1);
	}
}

//--------------------------------------------------------------------------//
//-------------------------------------------------------------------------//
//-------------------------------------------------------------------------//

int Size(struct bstnode* rootptr)
{
	if(rootptr == NULL)
		return 0;
	else
		return (Size(rootptr->left) + Size(rootptr->right) + 1);
}
