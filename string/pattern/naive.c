#include<stdio.h>
#include<stdlib.h>

void search(char* text, char* pattern, int m, int n)
{
	//i is the counter to match the pattern, count to count the no of occurances and j is to get the index number where the pattern matches
	int i,count = 0, j=0;
	
	//O(mn) approach using two for loops
	for(text;*text!='\0';text++)
	{
		//initialize 1 for a new search
		i = 1;
		//assign duplicate pointers for text and pattern
		char* temp = (char*)malloc(n*sizeof(char));
		temp = pattern;
		char* text_temp = (char*)malloc(m*sizeof(char)); 
		text_temp = text;
	
		for(temp;*temp!='\0';temp++)
		{
			//check if the character of text and pattern match	
			if(*temp == *text_temp)
			{
			// if the count of charchter match equals length of pattern, there is a match of pattern in the text
				if(i == n)
				{
					count++;
					printf("pattern match at index %d\n", j);
				}
				i++;
				text_temp++;
			}
			else
				break;
		}
		j++;
	}
	printf("Pattern match count: %d\n", count);
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
	search(text, pattern, i, j);
return 0;
}
