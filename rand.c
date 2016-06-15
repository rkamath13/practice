#include<stdlib.h>
#include<stdio.h>
#include<time.h>



int rand2(void)
{
	
	int k = rand()%5;
	//if(k == 4)
	//	return rand2();
	//else 
		return k%2;
}


int rand7(void)
{
	int ans;
	ans = rand2()*4 + rand2()*2 + rand2();
	if(ans == 7)
		return rand7();
	else
		return ans;
}

int rand15(void)
{
	int ans;
	ans = rand2()*8 + rand2()*4 + rand2()*2 + rand2();
	if(ans == 15)
		return rand15();
	else
		return ans;
}
	
	
	
int main()
{
	srand(time(NULL));
	int i;
	for(i=0;i<5;i++)
	{
		int k = rand15();
		printf("%d\t",k);
	}
return 0;
}
		
	
 
