//using n^3 keys
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc,char *argv[])
{
	time_t t;
	srand((unsigned)time(&t));
	int n = argc==1?100:atoi(argv[1]);
	int *arr= malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		arr[i] = i;
	//swapping step:
	for(int i=0;i<n;i++)
	{
		int idx =  (rand()%(n-i)) + i;
		int temp = arr[i]; arr[i]=arr[idx]; arr[idx]=temp; 
	}
	for(int i=0;i<n;i++)
		printf("%d\n",arr[i]);
}

