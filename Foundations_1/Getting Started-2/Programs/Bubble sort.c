//This program implements bubble sort given in problem 2, chapter 2.
//It takes input n followed by n integers, and outputs the n integers in sorted order.
#include <stdio.h>
#include <stdlib.h>

int insertion_sort(int *arr,int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n-i-1;j++)
			if(arr[j]>arr[j+1])
			{int temp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = temp;}
	return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	int *arr = malloc((n+1)*sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);
	insertion_sort(arr+1,n);

	for(int i=0;i<n;i++)
		printf("%d\n",arr[i]);
	free(arr);
}
