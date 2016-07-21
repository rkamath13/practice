#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define MAX_LOOPS 5000000

long long int sum = 0;
int lock = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 

void* count(void* arg)
{
	int offset = *(int *)arg;
	int i;
	for(i=0;i<MAX_LOOPS;i++)
	{
		
		pthread_mutex_lock(&mutex);
			sum = sum+offset;
		pthread_mutex_unlock(&mutex);
	
	}	
	pthread_exit(NULL);
}

int main()
{
	pthread_t tid1,tid2;
	int offset1 = 1;
	int offset2 = -1;
	
	pthread_create(&tid1, NULL, count, &offset1);
	pthread_create(&tid2, NULL, count, &offset2);
	
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	printf("sum is %lld\n", sum);
return 0;
}
