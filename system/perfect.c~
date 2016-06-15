#include <pthread.h>
#include <stdio.h>
#include <math.h>

typedef struct range			//struct for range of factors for each thread
{
	long long unsigned int from;	
	long long unsigned int to;
}range;

long long unsigned int summation,no,root;
pthread_mutex_t sumlock;
void *calculate(void *);

void main(int argc, char *argv[])
{
	range r[100];
	pthread_t t[100];				//to create threads
	long long int i,p,frame;
	
	no=atoi(argv[1]);				//get the parameters from command line
	p=atoi(argv[2]);
	root=sqrt(no);

	frame=root/p;					//set the frame size for each thread sq root/number of threads	
	summation=0;

	printf("The Given No. is %llu\n",no);
	printf("The root is %llu\n",root);
	printf("No. of Threads are  %llu\n",p);		//print pre-calculated values
	printf("Frame Size is %llu\n",frame);

	for(i=0;i<p;i++)
	{
		r[i].from=i*frame+1;			//set "from" limit for each frame

		if(i==p-1)
			r[i].to=root;			//for last frame "to = root"
		else
			r[i].to=(i+1)*frame;		//set "to" limit for each frame

		printf("Thread %lld executing for factors from %llu to %llu\n",i+1,r[i].from,r[i].to);
		pthread_create(&t[i],NULL,calculate,&r[i]);	//start thread									
	}	
	for(i=0;i<p;i++)
		pthread_join(t[i],NULL);
	
	printf("Summation is %llu \n",summation); 
	
	if(summation==no)
		printf("This is a Perfect Number\n");		//give result
	else
		printf("This is not a Perfect Number\n");
}


void *calculate(void *x)
{
	range *ra= (range*)x;		//get the parameter typecasted from void * type
	long long unsigned int i,j,f2;
	i=ra->from;			//get range in local variables
	j=ra->to;

	while(i<=j)			//loop for from->to
	{
		if(no%i==0)		//if i is a factor
		{
			f2=no/i;			//get the other factor
			pthread_mutex_lock(&sumlock);	//get lock on sum lock before updating summation
			printf("Sum+ = %lld \n",i);	//add factor i to  summation and show on console
			summation+=i;
			if(f2!=root&&i!=1)		//to avoid other factor to be N and avoid
			{				//root to repeat twice for a perfect square
				printf("Sum+ = %llu \n",f2);
				summation+=f2;
			}
			pthread_mutex_unlock(&sumlock);
		}
		i++;
	}
}
