#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n;
	printf("Enter the number\n");
	scanf("%d", &n);	
	int prime[n+1];
	prime[0]=0;
	prime[1]=0;
	int i,j;
	
	for(i=2; i<=n;i++)
		prime[i]=1;

	for(i=2;i<=sqrt(n);i++)
	{
		if(prime[i]==1)
		{
			for(j=i;i*j<=n;j++)
				prime[i*j]=0;
		}
	}
	
	for(i=0;i<=n;i++)
	{
		if(prime[i]==1)
			printf("%d\t",i);
	}
	printf("\n"); 
return 0;
}
