#include<stdio.h>

int main()
{
	char* p;
	char c;
	p = &c;
	
	printf("size of char pointer %d\n", sizeof(p));
	printf("size of char pointer %d\n", sizeof(char *));
return 0;
}
