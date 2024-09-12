#include<stdio.h>

void nhap(int A[], int &n)
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
}



void xuly(int A[],int n)
{
	int B[100];
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(A[i]<A[i+1] && A [i]>A[i-1])
		{
			printf("%d ",A[i]);
		}
		if(A[i]<A[i+1] && A[i]<A[i-1])
		{
			printf("%d ",A[i]);
		}
		if(A[i]>A[i+1] && A[i]>A[i-1])
		{
			printf("%d ",A[i]);
			printf("\n");
		}
	}
}

int main()
{
	int A[100],n;
	nhap(A,n);
	xuly(A,n);
	return 0;
}
