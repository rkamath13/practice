#include <stdio.h>
#include <stdlib.h>

void test_stack_growth_direction(recursion_depth) 
{
	int local_int1;
	printf("%p\n", &local_int1);
  	if (recursion_depth < 10) 
	{
    		test_stack_growth_direction(recursion_depth + 1);
  	}
}

void func(int* ptr)
{
	int local_int;
	int a[100];
	if(a < &a[1])
		printf("Address grows upwards in a stack\n");
	else
		printf("Address grows downwards\n");

	if(ptr < &local_int)
		printf("stack grows upwards");
	else
		printf("stack grows downwards\n");
	
}

void heap_dir(int* ptr1)
{
	int* heapptr2 = (int *)malloc(sizeof(int));
	if(!heapptr2)
		printf("Error: Cannot allocate heap memory\n");
	if(heapptr2>ptr1)
		printf("Heap grows upwards\n");
	else
		printf("Heap grows downwards\n");
}

int main () 
{
	//test_stack_growth_direction(0);
	int a;
	int* b = &a;
	func(b);
	int *heapptr1 = (int *)malloc(sizeof(int));
	heap_dir(heapptr1);
return 0;
}
