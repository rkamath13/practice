#include<stdio.h>
#ifndef LINK_LIST_H
#define LINK_LIST_H

struct node{
	int data;
	struct node* next;
};

struct node* MakeNode(int x);
struct node* Insert(struct node* root, int x);
void PrintList(struct node* root);
struct node* ReturnMid(struct node* root);

#endif

