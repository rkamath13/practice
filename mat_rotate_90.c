#include<stdio.h>
#include<stdlib.h>

int matrix[10][10];

void rotate_extra_space(int N)
{
	int dest_matrix[N][N];
	int i,j;
	
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			dest_matrix[j][N-i-1] = matrix[i][j];

	printf("original matrix\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%d\t", matrix[i][j]);
		printf("\n");
	}
	printf("roatated matrix\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%d\t", dest_matrix[i][j]);
		printf("\n");
	}
			
}
		
int main()
{
	int N;
	printf("Enter the dimension of square matrix\n");
	scanf("%d", &N);
	matrix[N][N];
	int i,j;
	
	printf("Enter the matrix\n");
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			printf("Element %d%d ",i,j);
			scanf("%d", &matrix[i][j]);
		}

	rotate_extra_space(N);

return 0;
}
