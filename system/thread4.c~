#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

long double sum = 0;
//pthread_mutex_t sumlock;
struct r{
	long long from;
	long long to;
	unsigned long long sum;
};

void* total(void* limit)
{
	struct r* ptr =(struct r*)limit; 
	long long start = ptr->from;
	long long end = ptr->to;
	long long i;
	for(i=start;i<=end;i++)
	{
		//pthread_mutex_lock(&sumlock);
		ptr->sum = ptr->sum+i;
		//pthread_mutex_unlock(&sumlock);
	}
	
	pthread_exit(0);
}


int main(int argc, char* argv[])
{
	if(argc<3)
	{
		printf("less number of arguments\n");
		return -1;
	}
	
	long long N = atoll(argv[1]);
	long t = atoi(argv[2]);
	long long range = N/t;
	
	struct r diff[t];
	long long i;
	long long start = 0;
	long long end;
	pthread_t tid[t];
	
	for(i=0;i<t;i++)
	{
		diff[i].from = start;
		end = start + range;
		if (i==t-1)
			diff[i].to = N;
		else 
			diff[i].to = end;
		start = end+1;
		diff[i].sum = 0;
	
		printf("from %lld\n", diff[i].from);
		printf("to %lld\n", diff[i].to);

		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_create(&tid[i], &attr, total, &diff[i]);
	}
	
	printf("main function executing other code.........\n");
	printf("%d\n", sizeof(unsigned long long));
	sleep(1);
	for(i=0;i<t;i++)
	{	
		pthread_join(tid[i], NULL);
		sum = sum + diff[i].sum;
	}
	printf("sum id %.0Lf\n", sum);

return 0;
}
