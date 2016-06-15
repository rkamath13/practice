#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TABLE_SIZE 13
#define PRIME 13

int hash_array[TABLE_SIZE] = {0};

void hash_search(char* text, char* pattern, int n, int m)
{
	int i;
	char* temp_text = (char*)malloc(n*(sizeof(char)));
	temp_text = text;
	char* temp = (char*)malloc(m*(sizeof(char)));
	temp = pattern;
	
	for(temp_text;temp_text<=text+n-m;temp_text++)
	{
		int hash_value = 0;
		hash_value = (*(temp_text) + *(temp_text+1)*PRIME + *(temp_text+2)*PRIME*PRIME)%TABLE_SIZE;
		hash_array[hash_value] = 1;
	//printf("%c%c%c\t", *(temp_text), *(temp_text+1), *(temp_text+2));
	//printf("hash value = %d\n", hash_value);
	}
	
	
	int pattern_hash_value;
		//printf("%c%c%c\n",*(temp), *(temp+1), *(temp+2));
	pattern_hash_value = (*(temp) + *(temp+1)*PRIME + *(temp+2)*PRIME*PRIME)%TABLE_SIZE;

	//printf("hash of pattern is %d\n",pattern_hash_value);
	if(hash_array[pattern_hash_value] == 1)
		printf("pattern found\n");
	
	else
		printf("pattern not found\n");

}

int main()
{
	//Character array to store text and pattern
	char *text = (char*)malloc(50*sizeof(char));
	char *pattern = (char*)malloc(10*sizeof(char));
	
	//duplicate the char ptr to check the length
	char* temp_text = text;
	char* temp = pattern;
	
	printf("ENTER the text\n");
	scanf("%s", text);
	printf("ENTER the pattern\n");
	scanf("%s", pattern);
	
	//i and j are the length of the text and pattern
	int i=0,j=0;
	while(*temp_text != '\0')
	{
		temp_text++;
		i++;
	}
	
	while(*temp != '\0')
	{
		temp++;
		j++;
	}
	
	//call the naive search pattern function
	hash_search(text, pattern, i, j);
return 0;
}

