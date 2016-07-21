//This is solved without using any threads for basic understanding of the problem statement, check the file arteris_thread.c for the solution with threading.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned char uint8;  //Using a new variable uint8 which is an unsigned byte type for byte operations
uint8* x;		      //uint8 pointer pointing to an address
uint8 random_gen[64];

int ErrorCheck()
{
	size_t i;
	//Error checking condition after incrementing the byte address values
	for(i=0;i < 64;i++)
	{
		//printf("Byte %d = %d\n", i, *(x+i));
		if(*(x+i) != random_gen[i])
		{
			printf("Byte %d fails\n", i);
			return -1;
		}
	}
			return 1;
}

int main()
{
	//Using time and srand for randomization
	time_t t;
	srand((unsigned) time(&t));
	
	//allocating 64 bytes of memory in heap for a random address(x denotes starting of the cacheline)
	x = (uint8*)malloc(64*sizeof(uint8));
	if(!x)
		printf("Error:Memory not allocated\n");
	
	//counters declared for accessing memory locations	
	size_t i,j;
		
	uint8* temp = x; //using a new pointer which has the same value as x for processing
	for(i=0;i<64;i++)
	{
		*(temp+i) = (uint8)0; //Initializing all the byte addresses with 0
		//printf("%u\t", *(temp+i));
		random_gen[i] = rand()%255; //Finding a Random number for each byte using rand()
		//printf("Random for byte %d is %d\n", i, random_gen[i]); 
	}
	
	//incrementing the byte address values upto the random value generated for the respective bytes
	for(i=0;i < 64 ;i++)
	{
		for(j=0;*(temp+i)<random_gen[i];j++)
		{
		//	printf("%d\n",byte[i]);
			temp[i]++;
		}
		//printf("Byte %d after random add is %d\n", i, byte[i]);
	}
	
	int Error_checker = ErrorCheck();
	if(Error_checker == -1)
		printf("Error in the memory\n");
	else
		printf("No Error all cases passed\n");
return 0;
}
