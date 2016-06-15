#include<stdio.h>
#include<stdlib.h>

void removespace(char** ptr)
{
	char* temp = *ptr;
	char* new = temp;
	int i = 0;
	while(*new != '\0')
	{
		
		if(*new != ' ')
		{
	
				*(temp+i)=*(new);
				i++;		
		}
		new++;
	}
	*(temp+i) = '\0';
	
}
			


int main()
{
	char s[50];
	int i = 0;
	printf("enter the string\n");
	gets(s);
	while(s[i] != '\0')
		i++;
	char* ptr = (char *)malloc(sizeof(i*sizeof(char)+1));
	ptr = s;
	*(ptr+i) = '\0';
	
	printf("original string : %s\n", s);
	removespace(&ptr);
	printf("after removing space : %s\n", s);
return 0;
}
	
