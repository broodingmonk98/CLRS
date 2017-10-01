//This program multiples two matrices in theta(n^3) time
//See summary section 4.2 for details
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *ptr;	//To store the output matrix
int multiply(int *arr,int n,int m,int *arr2,int p,int q);

int main()
{
	//inputting the matrices
	clock_t a,b;
	double cpu_execution_time;

	int n,m;
	scanf("%d %d",&n,&m);
	int (*arr1)[m] = malloc(sizeof(int)*n*m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",arr1[i]+j);
	int p,q;
	scanf("%d %d",&p,&q);
	int (*arr2)[q] = malloc(sizeof(int)*p*q);
	for(int i=0;i<p;i++)
		for(int j=0;j<q;j++)
			scanf("%d",arr2[i]+j);
	printf("\nEnd of input\n");

	//Compute
	a = clock();
	if(multiply((int*)arr1,n,m,(int*)arr2,p,q)==-1){
		printf("Matrices are incompatible");
		return -1;
	}
	b = clock();
	cpu_execution_time = (double)(b-a)/CLOCKS_PER_SEC;
	printf("\nTime Take : %lf",cpu_execution_time);

	//Display
	for(int i=0;i<n*q;printf("%3d  ",ptr[i++]))
		if(i%q == 0) printf("\n");

	//Clearup
	free(arr1); free(arr2);
	free(ptr);
}

int multiply(int *ar1,int n,int m,int *ar2,int p,int q)
{
	if(m!=p)
		return -1;
	int (*arr)[q] = malloc(sizeof(int)*n*q);
	int (*arr1)[m]=(int (*)[m])ar1;
	int (*arr2)[q]=(int (*)[q])ar2;
	for(int i=0;i<n*q;*(*arr+i++)=0);
	for(int i=0;i<n;i++)
		for(int j =0;j<q;j++)
			for(int k=0;k<m;k++)
				arr[i][j]+=arr1[i][k]*arr2[k][j];
	ptr = (int*)arr;	
	return 0;
}


