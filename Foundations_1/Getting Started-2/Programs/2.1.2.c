//input n (size of array) followed by n integers
//output the n integers in non increasing order.
#include <stdio.h>
#include <stdlib.h>

int insertion_sort(int *arr,int n)
{
	for(int i=1,temp,j;temp=arr[i],i<n;arr[j+1]=temp,i++)
		for(j=i-1;temp>arr[j];j--)
				arr[j+1]=arr[j];
	return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	int *arr = malloc((n+1)*sizeof(int));
	arr[0]=0x7fffffff;
	for(int i=1;i<=n;i++)
		scanf("%d",arr+i);
	insertion_sort(arr+1,n);
	arr++;

	for(int i=0;i<n;i++)
		printf("%d\n",arr[i]);
	free(arr);
}
