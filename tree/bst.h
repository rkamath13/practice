#ifndef BST_H
#define BST_H

#include<stdio.h>
#include<stdlib.h>

struct bstnode{
	int data;
	struct bstnode* left;
	struct bstnode* right;
};

struct bstnode* makenode(int x);
struct bstnode* insert(struct bstnode* rootptr, int data);
int findnode(struct bstnode* rootptr, int data);
void Search(struct bstnode* rootptr);
void FindMin(struct bstnode* rootptr);
void FindMax(struct bstnode* rootptr);
void PreOrder(struct bstnode* rootptr);
void InOrder(struct bstnode* rootptr);
void PostOrder(struct bstnode* rootptr);
int Height(struct bstnode* rootptr);
void PrintLevel(struct bstnode* rootptr, int level);
void LevelOrder(struct bstnode* rootptr);
int Size(struct bstnode* rootptr);


#endif
