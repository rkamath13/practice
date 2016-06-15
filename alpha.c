#include <stdio.h>
#include <string.h>

char *map[10] = {"!", ",", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void generatePermute(char *num, int pos, int length)
{
	static char permute[7];
	int i;
	if(pos==length)
	{
		permute[length] = '\0';
		printf("%s\n", permute);
		return;
	}
	for(i = 0 ; i < strlen(map[num[pos]-'0']) ; ++i)
	{
		permute[pos] = map[num[pos]-'0'][i];
		generatePermute(num, pos+1, length);
	}
}
int main()
{
	generatePermute("6236537", 0, 7);
}
