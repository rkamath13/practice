#include<stdio.h>
#include<stdlib.h>

Derivative(int* ptr,int n)
{
	int i;
	for(i=0;i<=n;i++)
	{
		ptr[i] = ptr[i+1]*(i+1);
		//printf("%d\t", ptr[i]);
	}
		
	for(i=n-1;i>=0;i--)
		printf("%dx^%d +", ptr[i],i);
}
	
int main()
{
	int n;
	printf("Enter the order of the polynomial\n");
	scanf("%d", &n);
	int poly[n+1];
	int i;
	for(i=0;i<=n;i++)
	{
		printf("coeffcient of order %d ", i);
		scanf("%d", &poly[i]);
	}
	
	printf("Original polynomial :");
	for(i=n;i>=0;i--)
		printf("%dx^%d +", poly[i],i);
	printf("\n");
	int *ptr = (int*)malloc(n*sizeof(int));
	ptr = poly;
	Derivative(ptr, n);
}
