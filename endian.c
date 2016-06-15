#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 1;
	char *c = (char*)&a;
	if(*c)
		printf("little endian\n");
	else
		printf("big endian\n");
return 0;
}
