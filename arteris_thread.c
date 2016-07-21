#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <xxxxx.h> //This header file will include the functions get_thread_id() and get_address()
#define CACHELINE_SIZE 64
#define THREAD_NO 4

typedef unsigned char uint8;  //Using a new variable uint8 which is an unsigned byte type for byte operations

//global variables
unsigned long long int addr; 		//to store the address from the function
uint8 *addr_ptr;	     		//to cast the address in form of a pointer 	    
uint8 random_gen[CACHELINE_SIZE];	//Array of Random numbers for 64 bytes each
volatile int thread_lock[THREAD_NO] = {0}; 
//Thread lock used for synchronization, the value can be changed by the threads anytime hence volatile qualifier is used


//Error checking function returns 1 on no error and -1 on an error. It checks if the particular byte value from byte 0 to byte 63 matches the random number generated for that particular byte address offset

int ErrorCheck()
{
	size_t i;
	//Error checking condition after incrementing the byte address values to their respective random values
	for(i=0;i <CACHELINE_SIZE;i++)
	{
		if(*(addr_ptr+i) != random_gen[i])
		{
			printf("Byte %d fails\n", i);
			return -1;
		}
	}
			return 1;
}

//**** ASSUMPTION: I am assuming that this is a thread function and all 4 threads will execute this fuction in parallel when they are spawned from the main function, Hence I have written only one thread function as 4 threads will have 4 different stack memories to execute the same function**!!

//The thread function will take the thread id and Byte offset counter i as paramenters. It will lock the critical section which is the for loop used to increment the byte addresses till the random number generated for that particular byte offset stored in an array random_gen[], after the critical section is processed, it unlocks by assigning the variacle thread_lock for that particular tid as 0.
//** As this is a byte related processing, the max value will be 255 and synchronization wont be necessary as incrementing the byte address value is always less than 256.

	
void thread_function(int tid, i)
{
	thread_lock[tid] = 1;
	size_t j;
	//Start - critical section
	for(j=0;*(addr_ptr+i)<random_gen[i];j++)
		{
			addr_ptr[i]++;
		}
	//End - critical section
	thread_lock[tid] = 0;
}

int main()
{
	//Using time and srand for randomization
	time_t t;
	srand((unsigned) time(&t));
	int thread_id[4];                     //array for storing the threadID
	
	addr = get_address();
	addr_ptr = (long long int)addr;       //casting the address to a pointer
	uint8* temp = addr_ptr;               //using a new pointer which has the same value as addr_ptr for processing

	//counters declared for accessing memory locations	
	size_t i,j;
	
	//Getting the threadID's for 4 threads using the get_thread_id() function
	for(i=0;i<THREAD_NO;i++)
		thread_id[i] = get_thread_id();
	
	for(i=0;i<CACHELINE_SIZE;i++)
	{
		*(temp+i) = (uint8)0; //Initializing all the byte addresses with 0
		random_gen[i] = rand()%255; //generating a Random number for each byte using rand()
	}
	
	//Logic for incrementing the byte address values using 4 threads.
//The tid variable will go from 0 to 4 hence the modulo 4 operator, It will check if the thread_lock is unlocked and then spawn a thread using the thread function whose arguments will be the threadID and the offset counter for the byte addresses(byte 0, byte 1, byte 2.....byte 63)	
	
	for(i=0;i <CACHELINE_SIZE ;i++)
	{
		int tid = i%4;
		
		while(thread_lock[tid]!=0);
	
		thread_function(thread_id[tid], i);
		
	}
	
//Error checking function
	int Error_checker = ErrorCheck();
	if(Error_checker == -1)
		printf("Error in the memory\n");
	else
		printf("No Error all cases passed\n");
return 0;
}
