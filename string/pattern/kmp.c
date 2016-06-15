#include<stdio.h>
#include<stdlib.h>

int preprocess_arr[100];

void preprocess(char* pattern, int M)
{
	preprocess_arr[M];
	int i=1;
	int j=0;
	preprocess_arr[0] = 0;
	
	while(i<M)
	{
		if(pattern[i] == pattern[j])
		{
			preprocess_arr[i] = j+1;
			i++;
			j++;
		}
		
		else
		{
			if(j == 0)
			{
				preprocess_arr[i] = 0;
				i++;
			}
	
			else //j!=0
			{
				j = preprocess_arr[j-1];
			}
		}
	}

}

void kmp_search(char* text, char* pattern,int M,int N)
{
	//printf("Inside search func\n");
	int i = 0;
	int j = 0;
	preprocess(pattern, N);
	while(i<M)
	{
		if(text[i] == pattern[j])
		{
			//printf("%c %c\n", text[i],pattern[j]);
		
			if(j == N-1)
			{
				printf("Found pattern at index %d\n", i-N+1);
				j = preprocess_arr[j-1];
			}
			i++;
			j++;
		}

		else
		{
			if(j==0)
				i++;
			else
				j = preprocess_arr[j-1];
		}
	}
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
	kmp_search(text, pattern, i,j);
return 0;
}
