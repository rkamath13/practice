#include<stdio.h>
#include<stdlib.h>

	



void complement(char** bin)
{
	printf("inside complement func\n");
	char* ptr = *(bin);
	while(*ptr!='\0')
		printf("%c",*ptr++);
	printf("\n");
	char* ones = *(bin);
	while(*ones != '\0')
	{
		if(*ones == '0') *ones = '1';
		else *ones = '0';
		ones++;
	}
	int i = 0, l = 0;
	char* p = *(bin);
	printf("after 1's complement\n");
	while(*p!='\0')
	{
		printf("%c",*p++);
		l++;
	}
	printf("\n");

	for(--p;;p--)
	{
		if(*p == '1')
			*p = '0';
		else
		{
			*p = '1';
			break;	
		}
	}
}

int main()
{
	int i=0;
	char bin[10];
	printf("Enter the binary number\n");
	scanf("%s", bin);
	while(bin[i]!='\0')
		i++;	
	printf("length of binary is %d\n", i);
	char* ptr = (char*)malloc(sizeof(i*(sizeof(char)+1)));
	ptr = bin;
	*(ptr+i) = '\0';

	complement(&ptr);
	printf("two's complement :\n");
	while(*ptr!='\0')
		printf("%c",*ptr++);
	printf("\n");
return 0;
}
