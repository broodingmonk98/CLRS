//Modified merge sort, calling insertion sort for smaller arrays.
#include <stdio.h>
#include <stdlib.h>
int *dummy;

int insertion_sort(int *arr,int n)
{
	for(int i=1,temp,j;temp=arr[i],i<n;arr[j+1]=temp,i++)
		for(j=i-1; j>=0 && temp<arr[j];j--)
				arr[j+1]=arr[j];
	return 0;
}

int merge_sort(int *arr,int n)
{
	if(n<30){ insertion_sort(arr,n);  return 0;}
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
