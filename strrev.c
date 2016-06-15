#include<stdio.h>
#include<stdlib.h>

void rev(char a[])
{
	int i=0,j=0,k;
	char temp;
	while(a[i]!='\0')
		i++;
	k = i-1;
	for(j=0; j<i/2; j++)
	{
		temp = a[k];
		a[k] = a[j];
		a[j] = temp;
		k--;	
	}
		
printf("%s\n",a); 
		
		
}

int main()
{
	char a[100];
	printf("enter the string\n");
	gets(a);
 	rev(a);

return 0;	
}

	
