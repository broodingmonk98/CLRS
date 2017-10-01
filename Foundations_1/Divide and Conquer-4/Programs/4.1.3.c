//input format : n followed by n integers
//output : starting and ending indices of the maximum subarray, along with its value.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int l,r; //to store start and end indices of maxSubarray.
int findMax(int *arr, int n);	//Returns the max subarray's sum.
int findMax2(int*,int);
int findMax3(int*,int);
int main()
{
	//for timing the execution to compare functions:
	clock_t a,b;
	double cpu_time_used;

	//input part:
	int n;
	scanf("%d",&n);
	int *arr= malloc(sizeof(int)*n);
	for(int i=0; i<n; scanf("%d",arr+i++));

	//calculation part 1:
	a = clock();
	int max = findMax(arr,n);
	b = clock();
	cpu_time_used = ((double)(b-a))/CLOCKS_PER_SEC;
	printf("Time Take for divide and conquer : %lf \n",cpu_time_used);
	//output part:
	printf("\nMax Value is : %d\nStarting at %d and ending at %d\n",max,l,r);

	//calculation part 2:
	if(n>100000) printf("Infinity"); //Since its O(n^2)
	else{
	a = clock();
	max = findMax2(arr,n);
	b = clock();
	cpu_time_used = ((double)(b-a))/CLOCKS_PER_SEC;
	printf("Time Take for brute force	 : %lf \n",cpu_time_used);
	//output part:
	printf("\nMax Value is : %d\nStarting at %d and ending at %d\n",max,l,r);
	}
	
	//calculation part 3:
	//crossover point is at n ~ 50
	a = clock();
	max = findMax3(arr,n);
	b = clock();
	cpu_time_used = ((double)(b-a))/CLOCKS_PER_SEC;
	printf("Time Take for combination	: %lf \n",cpu_time_used);
	//output part:
	printf("\nMax Value is : %d\nStarting at %d and ending at %d\n",max,l,r);


	free(arr);

}

int findMax(int *arr, int n)
{
	if(n <= 1) return 0;	//base case
	int mid = n/2;

	//Recursive step to find max in left and right subarrays.
	int leftMax = findMax(arr,n/2), rightMax = findMax(arr+mid+1,n-mid-1);
	int midMax = 0,lmax=mid,rmax=mid;
	//To store indices of subarray through mid. l and r sum are - infinity
	for(int i = mid;i>=0;i--)
		if(arr[i]<arr[lmax]) lmax = i;
	for(int i = mid+1;i<n ;i++)
		if(arr[i]>arr[rmax]) rmax = i;
	midMax = -arr[lmax] + arr[rmax];
	if(midMax > leftMax && midMax> rightMax) { l=lmax; r=rmax; return midMax;}
	else if(leftMax>rightMax) { return leftMax; }
	else  { return rightMax; }
}

int findMax2(int *arr,int n)
{
	int max=0;
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
			if(arr[j]-arr[i]>max) 
			{ l=i; r=j; max=arr[r]-arr[l];	}
	
	return max;
}
int findMax3(int *arr,int n)
{
	if(n <= 50) return findMax2(arr,n);	//base case
	int mid = n/2;

	//Recursive step to find max in left and right subarrays.
	int leftMax = findMax(arr,n/2), rightMax = findMax(arr+mid+1,n-mid-1);
	int midMax = 0,lmax=mid,rmax=mid;
	//To store indices of subarray through mid. l and r sum are - infinity
	for(int i = mid;i>=0;i--)
		if(arr[i]<arr[lmax]) lmax = i;
	for(int i = mid+1;i<n ;i++)
		if(arr[i]>arr[rmax]) rmax = i;
	midMax = -arr[lmax] + arr[rmax];
	if(midMax > leftMax && midMax> rightMax) { l=lmax; r=rmax; return midMax;}
	else if(leftMax>rightMax) { return leftMax; }
	else  { return rightMax; }
}
