#include<stdio.h>
#include<stdlib.h>

int numb(int num, int fact)
{
	int count = 0,i;
	for(i=0;i<=num;i++)
	{
		int k = i;
		while(k)
		{
			if(k%10==fact)
			{
				count++;
				break;
			}
			k = k/10;
		}
	}
	return num-count;
}
			
			

int main()
{
	int num, fact;
	printf("enter the number\n");
	scanf("%d",&num);
	printf("enter the factor\n");
	scanf("%d",&fact);
 	
	int count;
	count = numb(num, fact);
	printf("the count is %d\n", count);
return 0;
}	
