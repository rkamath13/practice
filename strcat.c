#include<stdio.h>
#include<stdlib.h>

void cat(char a[], char b[])
{
	int i=0,j=0,count=0,count1=0;
	char c[100];
	while(a[i]!='\0')
	{
		count++;
		i++;
	}
	while(b[j]!='\0')
	{	
		a[i] = b[j];
		i++;
		j++;
	}
	a[i]='\0';
	printf("%s\n", a);
	
}
			

int main()
{
	char a[100], b[100];
	printf("enter the first string\n");
	gets(a);
 	
	printf("enter the second string\n");
	gets(b);

	char *c;
	cat(a,b);

	
}

	


