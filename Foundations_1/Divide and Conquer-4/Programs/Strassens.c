//see summary section 4.2
//we shall only be considered square matrices of perfect square length
//for brevity, and since we are more focused on the programming concepts.
//input format: log_2 (side of matrix) followed by n*n and n*n integers
//output format: product of the two matrices
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int size=0;
int* matrixMul(int *arr1,int *arr2,int n,int a,int b);
int* addAndAssign(int *orginal,int *orginal2,int n,int sign,int width);
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
	arr3 = matrixMul(arr1,arr2,size,0,0);
	b= clock();
	cpu_execution_time = (double)(b-a)/CLOCKS_PER_SEC;

	//output
	printf("\nTime take : %lf\n\n",cpu_execution_time);
	for(int i=0;i<size;i++,printf("\n"))
		for(int j=0,k=i*size;j<size;j++)
			printf("%3d  ",arr3[k+j]);
	
	//cleanup
	free(arr1); free(arr2); free(arr3);

}

int* matrixMul(int *A,int *B,int n,int a,int b)
//a and be are there to check whether we have n*n or n*size array.
{
	if(n==1)
	{
		int *C = malloc(sizeof(int));
		C[0] = A[0] * B[0];
		return C;
	}
	int *C = malloc(sizeof(int)*n*n);	int n1= n/2;
	//Partioning the original matrices;
	int temp= size;
	if(a) { size = n<<(a-1); }
	int *A11=A, *A12=A+n1, *A21=A+n1*size, *A22=A+n1*size + n1; 
	if(b == 0) {	size = temp;    } else {size = n<<(b-1); }
	int *B11=B, *B12=B+n1, *B21=B+n1*size, *B22=B+n1*size + n1; 
	size = temp;
	//Defining New matrices as in CLRS
	int *S1 = addAndAssign(B12,B22,n1,1,b); //B12 - B22
	int *S2 = addAndAssign(A11,A12,n1,0,a); //A11 + A12
	int *S3 = addAndAssign(A21,A22,n1,0,a); //A21 + A22
	int *S4 = addAndAssign(B21,B11,n1,1,b); //B21 - B11
	int *S5 = addAndAssign(A11,A22,n1,0,a); //A11 + A22
	int *S6 = addAndAssign(B11,B22,n1,0,b); //B11 + B22
	int *S7 = addAndAssign(A12,A22,n1,1,a); //A12 - A22
	int *S8 = addAndAssign(B21,B22,n1,0,b); //B21 + B22
	int *S9 = addAndAssign(A11,A21,n1,1,a); //A11 + A21
	int *S10= addAndAssign(B11,B12,n1,0,b); //B11 + B12

	

	//Carrying out 7 submultiplications/recursive calls
	int *P1 = matrixMul(A11,S1 ,n1,a==0?a:a+1,1),
	    *P2 = matrixMul(S2 ,B22,n1,1,b==0?b:b+1),
	    *P3 = matrixMul(S3 ,B11,n1,1,b==0?b:b+1),
	    *P4 = matrixMul(A22,S4 ,n1,a==0?a:a+1,1),
	    *P5 = matrixMul(S5 ,S6 ,n1,1,1),
	    *P6 = matrixMul(S7 ,S8 ,n1,1,1),
	    *P7 = matrixMul(S9 ,S10,n1,1,1);
	int *tempC;
	//Reconstructing C11
	tempC=C;
	for(int i=0;i<n1;i++)
		for(int j=0;j<n1;j++)
			tempC[i*n+j] = P5[i*n1+j]+P4[i*n1+j]-P2[i*n1+j]+P6[i*n1+j];

	//Reconstructing C12
	tempC=C+n1;
	for(int i=0;i<n1;i++)
		for(int j=0;j<n1;j++)
			tempC[i*n+j] = P1[i*n1+j]+P2[i*n1+j];

	//Reconstructing C21
	tempC=C+n1*n;
	for(int i=0;i<n1;i++)
		for(int j=0;j<n1;j++)
			tempC[i*n+j] = P3[i*n1+j]+P4[i*n1+j];

	//Reconstructing C22
	tempC=C+n1*n + n1;
	for(int i=0;i<n1;i++)
		for(int j=0;j<n1;j++)
			tempC[i*n+j] = P5[i*n1+j]+P1[i*n1+j]-P3[i*n1+j]-P7[i*n1+j];

	//Cleaning Up
	free(S1);free(S2);free(S3);free(S4);free(S5);
	free(S6);free(S7);free(S8);free(S9);free(S10);
	free(P1);free(P2);free(P3);free(P4);free(P5);free(P6);free(P7); 

	return C;
}

int* addAndAssign(int *org1,int *org2,int n,int sign,int width){ 
//to define the 10 matrices (S1 - S10) given in CLRS for Stranssens matrix *
	int *ptr = malloc(sizeof(int)*n*n);
	int sg = sign?-1:1;  //zero for addition
	int temp = size;
	if(width) { size = n*2<<(width-1); }
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			ptr[i*n + j] = org1[i*size + j] + sg*org2[i*size + j];
	size = temp;
	return ptr;


}

