#include<stdio.h>


int add (int a, int b)
{
	int z;
	z = a+b;
	return z;
}

int sub (int a, int b)
{
	int z;
	z = a-b;
	return z;
}

int mul (int a, int b)
{
	int z;
	z = a*b;
	return z;
}

int main()
{
	int h, i;
	int (*func_ptr[])(int, int) = {add, sub, mul};
	
	scanf("%d", &i);
	if(i>2)
		printf("error\n");

	
	h = func_ptr[i](5,3);
	printf("%d\n", h);

return 0;
}
