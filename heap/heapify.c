#include<stdio.h>
#include<stdlib.h>

printHeap(int* ptr)
{
	int i;
	for(i=0;i<10;i++)
		printf("%d\t", ptr[i]);
	printf("\n");
}

Heapify(int* ptr, int i)
{
	int left, right, max;
	left = 2*i + 1;
	right = 2*i + 2;
	
	if(left<=9 && (ptr[left] >= ptr[i]))
		max = left;
	else
		max = i;
	if(right<=9 && (ptr[right] >= ptr[max]))
		max = right;
	if(max != i)
	{
		int temp = ptr[i];
		ptr[i] = ptr[max];
		ptr[max] = temp;
	printHeap(ptr);
	Heapify(ptr, max);
	}
}
		

int main()
{
	int A[10], i;
	printf("Enter the elements\n");
	for(i=0;i<10;i++)
	{
		printf("%d element ", i);
		scanf("%d", &A[i]);
	}
	
	int* ptr = (int*)malloc(10*sizeof(int));
	ptr = A;
	
	Heapify(ptr, 5);

return 0;
}
	
	
