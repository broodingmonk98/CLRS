#include <stdio.h>
#include <stdlib.h>

void findMin(int *,int *,int,int,int);
int main()
{
	int n,m;
	scanf("%d %d",&m,&n);
	int *arr = malloc(sizeof(int)*n*m);
	for(int i=0;i<m*n;scanf("%d",arr+i),i++);
		//printf("Here%p\n",arr+i);
	int *min = malloc(sizeof(int)*m);

	findMin(arr,min,m,n,1);
	for(int i=0;i<m;i++)
		printf("\n%d",arr[i*n + min[i]]);
	free(arr);
	free(min);

	return 0;
}	
void findMin(int* arr,int* min, int m,int n,int N)
{
	//for odd rows
	if(1<<N < m)
		findMin(arr,min,m,n,N+1);
	for(int i=(1<<(N-1)) - 1;i<m; i+= 1<<N)
	{
		int argMin = i == (1<<(N-1))-1 ? 0:min[i - (1<<N)];
		for(int j=argMin,rng = i+(1<<N) > m?n-1:min[i+(1<<(N-1))];j<= rng; j++)
			if(arr[i*n+j] < arr[i*n+argMin])
				argMin = j;
		min[i] = argMin;
		printf("\n%d : %d",i,arr[i*n+argMin]);
	}
	
}
