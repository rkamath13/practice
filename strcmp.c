#include<stdio.h>
#include<stdlib.h>

int cmp(char a[], char b[])
{
	int i=0;
	while(a[i]!='\0')
	{
		if(a[i] == b[i])
			i++;
			
		else
			return 0;
	}
	
		return i;
}

int main()
{
	char a[100], b[100];
	printf("enter the first string\n");
	gets(a);
 	
	printf("enter the second string\n");
	gets(b);

	int c;
	c = cmp(a,b);
	if(c!=0)
		printf("strings match\n");
	else
		printf("strings dont match\n");

return 0;	
}

	
