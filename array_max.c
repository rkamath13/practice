#include<stdio.h>
#include<stdlib.h>


void MaximizeArray(int A[], int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(A[i]==A[i+1])
		{
			A[i] = 0;
		}
	}
	
	int sum = 0;
	for(i=0;i<len;i++)
		sum = sum+A[i];

	printf("The Maximum of array without duplicates is %d\n", sum);
}

int main()
{
	int A[10];
	int i;
	
	printf("enter the array elements\n");
	for(i=0;i<10;i++)
	{
		printf("Enter the %d element ", i);
		scanf("%d", &A[i]);
		printf("\n");
	}
	
	MaximizeArray(A,10);

return 0;
}
