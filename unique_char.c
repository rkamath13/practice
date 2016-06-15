#include<stdio.h>
#include<stdlib.h>

int CheckUnique(char str[])
{
	char Array[26] = {0};
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(Array[str[i]] == 1)
			return 0;
		else
			Array[str[i]] = 1;
	}
	return 1;
}

int CheckUnique2(char str[])
{
	int check = 0;
	int val=0,i;
	for(i=0;str[i]!='\0';i++)
	{
		val = str[i] - 'a';
		if((check & (1<<val)) > 0)
			return 0;
		else
			check = check | (1<<val);
	}	
	return 1;
}
int main()
{
	char str[100];	
	printf("Enter the string\n");
	scanf("%s",str);
	int result = CheckUnique2(str);
	if(result == 0)
		printf("not unique\n");
	else
		printf("all unique\n");
return 0;
} 
