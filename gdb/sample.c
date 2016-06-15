#include<stdlib.h>
#include<stdio.h>

void add(int a, int b)
{
	int c;
	c=a+b;
	printf("The value of addition is %d", c);
}

int main()
{
	int a = 4;
	int b = 7;
	add(a,b);
return 0;
}
