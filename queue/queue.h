#ifndef QUEUE_H
#define QUEUE_H

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* MakeNode(int data);
void EnQueue(struct node* rear, struct node* front, int data);
void DeQueue(struct node* front);
int Front(struct node* rear);
int IsEmpty(struct node* rear, struct node* front);
void Print(struct node* front);

#endif
 
