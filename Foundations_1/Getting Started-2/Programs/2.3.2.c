
//This program implements merge sort
//It takes input n followed by n integers, and outputs the n integers in sorted order.
#include <stdio.h>
#include <stdlib.h>
int *dummy;
int merge_sort(int *arr,int n)
{
	if(n==1) return 0;
	merge_sort(arr,n/2);
	merge_sort(arr+n/2,n-n/2);
	int l=0,r=n/2,i=0;
	int mid=n/2;
	for(;l<mid&&r<n;i++)
		dummy[i]= arr[l]>arr[r]?arr[r++]:arr[l++];
	while(l<mid) dummy[i++]=arr[l++];
	while(r<n)   dummy[i++]=arr[r++];
	for(int j=0;j<n;j++)
		arr[j]=dummy[j];
	return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	int *arr = malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);
	dummy = malloc(n*sizeof(int));
	merge_sort(arr,n);

	for(int i=0;i<n;i++)
		printf("%d\n",arr[i]);
	free(arr);
	free(dummy);
}
