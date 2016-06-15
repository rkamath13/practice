#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *a;
	a = (int *)malloc(sizeof(40));
	free(a);
return 0;
}
