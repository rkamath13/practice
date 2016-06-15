#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
	char s[100], d[100];
	printf("Enter the string\n");
	scanf("%s", s);
	
	int i,j,a,k;
	while(s[i]!='\0')
		i++;
	printf("Enter the length for rotation\n");
	scanf("%d", &a);
	
	strcat(s,s);
	//printf("%s\n", s);
	for(j=a,k=0;j<a+i,k<i;j++,k++)
		d[k]=s[j];
	d[i]='\0';
	
	printf("%s\n", d);
	
	
	
	
return 0;
}
