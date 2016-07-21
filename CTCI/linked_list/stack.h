#include<stdio.h>
#include "link_list.h"

#ifndef STACK_H
#define STACK_H

struct node* Push(struct node* root, int x);
struct node* Pop(struct node* root);
int IsEmpty(struct node* root);
int Top(struct node* root);
void PrintStack(struct node* root);

#endif
