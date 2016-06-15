#include<stdio.h>
#include<stdlib.h>
#include "bst.h"
#include "stack.h"

int main()
{
struct bstnode* root = NULL;
root = insert(root,10);
root = insert(root,5);
root = insert(root,12);
root = insert(root,29);
root = insert(root,3);
root = insert(root,13);
root = insert(root,7);
root = insert(root,11);
//Search(root);

FindMin(root);
FindMax(root);
PreOrder(root);
printf("\n");
InOrder(root);
printf("\n");
PostOrder(root);
printf("\n");

return 0;
}

