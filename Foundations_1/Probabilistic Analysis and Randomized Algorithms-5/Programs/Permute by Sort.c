//using n^3 keys
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int sort(int*,int*,int);
int main(int argc,char *argv[])
{
	time_t t;
	srand((unsigned)time(&t));
	int n = argc==1?100:atoi(argv[1]);
	int *arr= malloc(sizeof(int)*n);
	int *keys= malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		arr[i] = i,keys[i] = rand()%(n*n*n);
	sort(arr,keys,n);
	for(int i=0;i<n;i++)
		printf("%d\n",arr[i]);
}

int sort(int *arr,int *keys,int n)
{
	if(n<=1) return 0;
	int pivot = keys[n-1];
	int temp;
	int j=0;
	for(int i=0;i<n;i++)
		if(keys[i]<=pivot)
		{ 
			temp=arr[i]; arr[i]=arr[j]; arr[j]=temp;
			temp=keys[i]; keys[i]=keys[j]; keys[j]=temp;
			j++;
		}
	sort(arr,keys,j-1);
	sort(arr+j,keys+j,n-j);

	return 0;
}


