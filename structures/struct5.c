#include<stdio.h>
#include<stdlib.h>


struct node_without{
	int x;
	char y;
	char* t;
}without;

struct node_with{
	int x;
	char y;
	char* t;
}__attribute__((packed,aligned(8)))with;

int func_with(struct node_with with)
{
	return with.x;
}

int func_without(struct node_without without)
{
	return without.x;
} 

int main()
{

	without.x = 5;
	with.x = 10;
	without.y = 'a';
	with.y = 'b';

	
	printf("size with attribute %d\n", sizeof(struct node_with));
	printf("size without attribute %d\n", sizeof(struct node_without));

	int case1 = func_with(with);
	int case2 = func_without(without);

	printf("with integer %d\n", case1);
	printf("without integer %d\n", case2);


return 0;
}

