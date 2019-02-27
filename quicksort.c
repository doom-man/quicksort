#include<stdio.h>
#include <time.h>
#include <stdlib.h>

#define LIMIT 10
#define MAXSIZE 100

void InsertSort(int * A , int N);

int median3(int * A , int left , int right);

void swap(int * a , int * b);

void QuickSort(int * A , int left , int right);


int main(void)
{


	int a[MAXSIZE];
	srand((int)time(NULL));
	for(int i = 0; i < MAXSIZE; i++)
	{
		a[i]= rand()%100;
	}
	printf("\n");
	for(int i = 0 ; i<MAXSIZE;i++)
	{
		if(i % 5 == 0)
			printf("\n");
			printf("%d ",a[i]);

	}

	 printf("\n");
//InsertSort(a , 10);
	QuickSort(a, 0 , MAXSIZE-1);
	for(int i = 0 ; i<MAXSIZE;i++)
	{
		if(i%5 == 0)
			printf("\n");
		printf("%d ",a[i]);

	 }
	 printf("\n");
	return 0;
}

void swap(int * a , int * b)
{
	int temp;
	temp = *a ;
	*a = *b;
	*b = temp;
}
int median3(int * A , int left , int right)
{
	int center = (left + right)/2;
	if(A[left] > A[right])
		swap(&A[left] , &A[right]);
	if(A[center] < A[left])
		swap(&A[left],&A[center]);
	if(A[center] > A[right])
		swap(&A[center] , &A[right]);
	swap(&A[center],&A[right-1]);
	return A[right-1];

}

void QuickSort(int * A , int left , int right)
{

	int  i , j;
	int pivot;
	if(left + LIMIT < right)
	{
		pivot  = median3(A , left , right);
		i = left ,j = right - 1;
		for(;;)
		{
			while(A[++i] < pivot){}
			while(A[--j] > pivot){}
			if(i < j)
			{
			swap(&A[i],&A[j]);
			}
			else
				break;

		}
		swap(&A[right-1],&A[i]);
		QuickSort(A,left,i-1);
		QuickSort(A,i+1,right);
	}
	else
		InsertSort(A+left , right - left +1);

}


void InsertSort(int * A , int N)
{
	int j, p;
	int tmp;
	for (p = 1 ; p < N; p++)
	{
		tmp = A[p];
		for(j = p-1 ; j >= 0 && A[j] > tmp ; j--)
		{
			A[j+1] = A[j];
		}
		A[j+1] = tmp;
	}
}
