#include<stdio.h>
#include<stdlib.h>

int main()
{
	float x;
	scanf("%f", &x);
	
	//cast it as int
	int cast = *(int *)&x;
	
	//unset tghe MSB 
	cast = cast & 0x7FFFFFFF;
	
	float z = *(float *)&cast;
	printf("%f\n", z);
return 0;
}
