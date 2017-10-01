//Solving max subarray problem in constant time.
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	int *arr = malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);
	int minElement=0, l=0, r=0,max=0;
	for(int i=0;i<n;(minElement = arr[i]<arr[minElement]?i:minElement),i++)
		if(max < arr[i]-arr[minElement]) 
		{
			max = arr[i]-arr[minElement];
			l = minElement;
			r = i;
		}
	//output
	printf("\nMax Value is : %d\nStarting at %d and ending at %d",max,l,r);
	free(arr);
}
