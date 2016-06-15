#include<stdio.h>
#include<stdlib.h>

int toint(char a[], int diff)
{
	int c, n=0;
	char k[diff];
	//printf("%d\n", diff);
	for(c=0;c<diff;c++)
	{
		k[c] = a[c];
		//printf("\n%c\n", k[c]);
	}
	for (c = 0;c<diff; c++)
  		  n = n * 10 + k[c] - '0';
  
return n;
}

int verify(char s[])
{
	int k=0,i=0,j=0,count=0,m,z;
	int A[4];
	char p[3];	
	while(s[i]!='\0')
	{
		if(s[i]== '.')
		{
			A[count] = i;
			//printf("%d\n", A[count]);			
			count++;
			//printf("count = %d\n", count);
			i++;
		}
		else
			i++;
		//printf("count = %d\n", count);
		if(count>3)
			return 1;
	}
	if(count<3)
		return 1;
	int left = 0;
	A[count] = i;		
	
	for(j=0;j<count+1;j++)
	{
		int right = A[j];
		for(k=left,m=0;k<right,m<right-left; k++,m++)
			p[m] = s[k];
		 
		z = toint(p, right-left);
		if(z>255)
			return 1;
		left = A[j]+1;
		
	}
	

return 0;	
}			


int main()
{

	char s[100];
	printf("enter the IP address\n");	
	scanf("%s", s);
	int i=0, k=0, m=0;
	
        m = verify(s);
	//printf("%d\n", m);
	if(m == 1)
		printf("invalid IP address\n");
	else
		printf("Valid IP address\n");
	
return 0;
}
