#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	if (n ==0)
		printf("neither positiive nor negtive\n");

	else if((n>>31)&1)
		printf("%d is negative\n", n);
	else 	
		printf("%d is positive\n", n);
return 0;
}
