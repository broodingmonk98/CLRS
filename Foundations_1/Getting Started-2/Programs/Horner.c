#include <stdio.h>
#include <stdlib.h>

int Horner(int *arr,int n,int x)
{
	int y=0;
	for(int i=0;i<n;i++)
		y = arr[i] + y*x;
	return y;
}

int main()
{
	int n;
	scanf("%d",&n);
	int *arr = malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);
	int x;
	scanf("%d",&x);
	printf("%d",Horner(arr,n,x));
	free(arr);
}
