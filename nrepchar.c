#include<stdio.h>
#include<stdlib.h>



char nonrepchar(char* s)
{
	char* p = s;
	int i=0,k;
	int arr[26] = {0};
	char ans;
	
	int l =0;
	while(*s !='\0')
	{
		arr[(int)(*s - 97)]+=1;
		s++;
	}
	
	for(k=0; k<26; k++)
	{
		//printf("a[%d] = %d", k, arr[k]);
		if(arr[(int)(*p-97)] == 1)
		{
			
			ans = *p;
			break;
		}
		else
			return '\0';	
	p++;
	}
return ans;
	
}
		



int main()
{
	int i = 0;
	char s[50];
	char* st;
	printf("enter the string\n");
	scanf("%s", s);
	while(s[i] != '\0')
		i++;
	st = (char*)malloc(sizeof(i*sizeof(char)+1));
	*(s+i) = '\0';
	st = s;
	char ans = nonrepchar(st);
	if(ans != '\0')	
		printf("%c\n", ans);
	else
		printf("no repeated character\n");
return 0;
} 
