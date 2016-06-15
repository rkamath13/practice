#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void ReverseWord(char str[], int len)
{
	char* buffer = (char *)malloc(len*sizeof(char)+1); 
	printf("%d\n", len);
	int dst = 0;
	int end,start;
	int i = len-1;
	
	while(i>=0)
	{
		if(str[i] == ' ')
		{
			buffer[dst++] = str[i--];
		
		}
		else
		{
			end = i;
			while(str[i] != ' ' && i>=0)
				i--;
			start = i+1;
	
			while(start<=end)
			{
				buffer[dst] = str[start];
				dst++;
				start++;
			}
		}
	}
	buffer[len] = '\0';
	printf("%s\n", buffer);
}

void reverse(char* word, int start, int end)
{
	char temp;
	while(end>start)
	{
		temp = word[start];
		word[start] = word[end];
		word[end] = temp;
		start++;
		end--;
	}
		
}

void ReverseWord2(char str[], int len)
{
	char* strptr = (char *)malloc(len*(sizeof(char))+1);
	int i = 0;
	int start = 0;
	int end = len-1;
	reverse(strptr, start, end);
	

	while(i<len)
	{
		start = i;
		while(strptr[i] != ' ' || strptr[i] != '\0')
			i++;
		end = i-1;
		
		reverse(strptr, start, end);
		
		if(strptr[i] == ' ')
			i++;
	}
	
	//printf("%s\n", strptr);
}
	

	
int main()
{
	char str[100];
	printf("Enter the string\n");
	gets(str);
	int len=0,i=0;
	while(str[i++] != '\0')
		len++;
	
	ReverseWord2(str,len);

return 0;
}
