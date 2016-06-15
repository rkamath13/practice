#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

long long sum = 0;

void* total(void* limit)
{
	long long N = *((long long*)limit);
	long long i;
	for(i=0;i<N;i++)
		sum = sum+i;
	
	pthread_exit(0);
}


int main(int argc, char* argv[])
{
	if(argc<2)
	{
		printf("less number of arguments\n");
		return -1;
	}
	
	long long N = atoll(argv[1]);
	
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	
	pthread_create(&tid, &attr, total, &N);
	
	printf("main function executing other code.........\n");
	sleep(1);
		
	pthread_join(tid, NULL);
	printf("sum id %lld\n", sum);
return 0;
}
