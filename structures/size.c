#include<stdio.h>
#include<stdlib.h>

struct a{
	int a: 2;
	int b: 16;
	int c: 12;
	int d: 3;
}__attribute__((packed));


#pragma pack(1)
struct b{
	char* h;
	long double k;
	int g;
};
#pragma pack(0)

int main()
{
	printf("size of structure %d\n", sizeof(struct a));
	printf("size of structure b %d\n", sizeof(struct b));
 
return 0;
}
