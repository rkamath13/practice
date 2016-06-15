#include<stdio.h>

int *foo()
{
    int *start = 0x56739933;
    int *end = start + 5;
    return (start + end) / 2;
}

int main()
{
	int* h;
	h = foo();
return 0;
}
