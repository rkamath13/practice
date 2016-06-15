#include<stdio.h>

#define PRINT(x) (#x)

int main()
{
	printf("%s\n", PRINT(hello));
	return 0;
}


