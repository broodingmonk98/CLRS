//see summary section 4.1
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
