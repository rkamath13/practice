#include<stdio.h>
#include<stdlib.h>

#ifndef STACK_H
#define STACK_H


typedef struct node{
	int data;
	struct node *next;
}Node;

void push(int );
void pop(void );
int top(void );
int is_empty(void );
void print();

#endif
