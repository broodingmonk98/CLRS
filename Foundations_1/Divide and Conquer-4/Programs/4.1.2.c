//input format : n followed by n integers
//output : starting and ending indices of the maximum subarray, along with its value.
#include <stdio.h>
#include <stdlib.h>
int l,r; //to store start and end indices of maxSubarray.
int findMax(int *arr, int n);	//Returns the max subarray's sum.

int main()
{
	//input part:
	int n;
	scanf("%d",&n);
	int *arr= malloc(sizeof(int)*n);
	for(int i=0; i<n; scanf("%d",arr+i++));

	//calculation part:
	int max = findMax(arr,n);

	//output part:
	printf("\nMax Value is : %d\nStarting at %d and ending at %d",max,l,r);

	free(arr);

}

int findMax(int *arr, int n)
{
	int max=0;
	for(int i = 0;i < n;i ++)
		for(int j = i+1;j < n;j ++)
			if(arr[j]-arr[i] > max) { l=i; r=j;max=arr[j]-arr[i]; }

	return max;
}
