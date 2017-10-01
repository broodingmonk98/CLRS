//see summary section 4.2
//we shall only be considered square matrices of perfect square length
//for brevity, and since we are more focused on the programming concepts.
//input format: log_2 (side of matrix) followed by n*n and n*n integers
//output format: product of the two matrices
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int size=0;
int* matrixMul(int *arr1,int *arr2,int n);
int  add(int *arr1,int *arr2,int *arr3,int n);

int main()
{
	clock_t a,b;
	double cpu_execution_time;
	//beginning of input part
	int *arr1,*arr2,*arr3;
	int power,square;
	printf("Enter the log_2 (len of side of square  matrices) (only integer) : ");
	scanf("%d",&power);
	size = 1<<power;
	arr1 = malloc(sizeof(int)*size*size);
	arr2 = malloc(sizeof(int)*size*size);
	square = size*size;

	for(int i=0 ; i<square;scanf("%d",arr1+i),i++);
	for(int i=0 ; i<square;scanf("%d",arr2+i),i++);
	printf("\nDONE\n");

	//compute
	a= clock();
	arr3 = matrixMul(arr1,arr2,size);
	b= clock();
	cpu_execution_time = (double)(b-a)/CLOCKS_PER_SEC;

	//output
	printf("\nTime taken : %lf\n\n",cpu_execution_time);
	for(int i=0;i<size;i++,printf("\n"))
		for(int j=0,k=i*size;j<size;j++)
			printf("%3d  ",arr3[k+j]);
	
	//cleanup
	free(arr1); free(arr2); free(arr3);

}

int* matrixMul(int *A,int *B,int n)
{
	if(n==1)
	{
		int *C = malloc(sizeof(int));
		C[0] = A[0] * B[0];
		return C;
	}
	int n1 = n/2;
	int *C = malloc(sizeof(int)*n*n);
	int *A11=A, *A12=A+n1, *A21=A+n1*size, *A22=A+n1*size + n1; 
	int *B11=B, *B12=B+n1, *B21=B+n1*size, *B22=B+n1*size + n1; 
	add(matrixMul(A11,B11,n1),matrixMul(A12,B21,n1),C,n1);
	add(matrixMul(A11,B12,n1),matrixMul(A12,B22,n1),C+n1,n1);
	add(matrixMul(A21,B11,n1),matrixMul(A22,B21,n1),C+n*n1,n1);
	add(matrixMul(A21,B12,n1),matrixMul(A22,B22,n1),C+n*n1+n1,n1);
	return C;
	
}
int add(int *arr1,int *arr2,int *arr3,int n)	
//adds two square subarrays starting at arr1 and arr2 respectively into third array arr3
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			arr3[i*n*2+j] = arr1[i*n+ j] + arr2[i*n+ j]; 
			//*2 bcoz arr3 has 2n width
	free(arr1);	free(arr2);
	return 0;
}

