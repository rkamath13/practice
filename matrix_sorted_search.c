#include<stdio.h>
#include<stdlib.h>

int matrix[10][10];

void Search_Element(int row, int coloumn, int element)
{
	int i = 0;
	int j = coloumn-1;
	int count = 0;	
	int found = 0;
	

	while(i<row &&  j>=0)
	{
		if(matrix[i][j] == element)
		{
			printf("found the element\n");
			found = 1;
			break;
		}
		else if(matrix[i][j] < element)
			i++;
		else
			j--;
	}
	if(found != 1)
		printf("element not found\n");
	
}

int main()
{
	int m,n;
	printf("Enter the dimension (mxn) of the matrix\n");
	scanf("%d", &m);
	scanf("%d", &n);
	
	printf("Enter the Matrix Elements\n");
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			printf("%d%d element: ", i,j);
			scanf("%d", &matrix[i][j]);
			printf("\n");
		}
	int element;
	while(1){
		printf("Find the element to be searched\n");
		scanf("%d", &element);
		Search_Element(m, n, element);
		printf("\n");
	}
return 0;
}
