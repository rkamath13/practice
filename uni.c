#include<stdio.h>
#include<stdlib.h>

union item{
	int a;
	char b;
	float c;
};

struct it{
	int a1;
	char b1;
	float c1;
};

union item item1;
struct it item2;

int main()
{
	printf("size of union is %d\n", sizeof(item1));
	printf("size of structure is %d\n", sizeof(item2));

	printf("size of char in struct is %d\n", sizeof(item2.b1));
	printf("size of char in union is %d\n", sizeof(item1.b)); 

return 0;
}
