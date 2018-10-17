#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



void * Sum(void *arg)
{
	int sum=0,i;
	int *start = (int*)arg;
	for(i=0;i<100;i++){
	sum = start[i] + sum;
	}
	return ((void*)sum);
}

int main ()
{
	int status[10],i,sum=0,j=100;
	pthread_t thread[10];	

	int arr[1000];
	int *p=arr;

	for(i=0;i<1000;i++){
	  arr[i]=rand()%9+1;
	}

	for(i=0;i<10;i++){
	pthread_create(&thread[i],NULL,Sum,(void**)(p));	
	p=&arr[j];
	j=j+100;
	pthread_join(thread[i],(void**) & status[i]);
	}
	
	for(i=0;i<10;i++){
	sum=sum+status[i];
	}
	
	printf("\nSum of 1000 numbers: %d\n", sum);

	return 0;
}
