#include<stdio.h>
#include<stdlib.h>

int* add(int a[], int b[],int lena, int lenb)
{
	int* p;
	int i = 0; 
	int j =0;
	while(i<lena &&j< lenb)
	{
		*p	


int main()
{
	int a[9] = {1,5,3,6,8,9,4,0,9};
	int b[7] = {6,8,1,6,9,5,7};

	int i = 0;
	printf("first array\n");
	for(i = 0;i<(sizeof(a)/sizeof(a[0])); i++)
		printf("%d\t", a[i]);
	printf("\n");
	printf("second array\n");
	for(i=0;i<(sizeof(b)/sizeof(b[0]));i++)
		printf("%d\t", b[i]);
	printf("\n");
	
	int* ptr = (int *)malloc(sizeof(a[17]);
	ptr = add(a,b,9,7);
return 0;
}
