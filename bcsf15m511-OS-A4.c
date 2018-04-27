#include<stdio.h>

#include<pthread.h>

#define SIZE 1000

#define NUMOFTHREADS 10

int arr [SIZE]={0};

int sum[10] = {0,0,0,0,0,0,0,0,0,0};

int countofthread =0;

void* sumnum (void*args)
{
	int tnum = countofthread++;
	
	for(int i = tnum*(SIZE/10); i < (tnum+1)*(SIZE/10) ; i++)
	{
		sum[tnum]= sum[tnum] + arr[i];
	}
}


int main ()
{

	int sumTotal = 0;

	pthread_t threadsArray[NUMOFTHREADS];

	// populating the array with elements 
	for(int i = 0; i < SIZE ; i++)
	{
		arr[i]=1;
	}

	//creating 10 threads all excuting the sumnum function 
	for(int i = 0; i < NUMOFTHREADS ; i++)	
		pthread_create(&threadsArray[i],NULL,sumnum,(void*)NULL);

	// joing the threads so that they wait for one another 
	for(int i = 0; i < NUMOFTHREADS ; i++)	
		pthread_join(threadsArray[i],NULL);	

	// adding the result stored in the sum array returned by each thread
	for(int i = 0; i < 10 ; i++)
	{
		sumTotal+=sum[i];
	}	
	
	// printing out the sum 
	printf("the sum is = %d  \n" ,sumTotal);

	return 0;
}
