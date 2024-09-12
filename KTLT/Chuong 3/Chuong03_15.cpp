#include<stdio.h>

void nhap(int A[],int &n,int &x)
{
	scanf("%d%d",&n,&x);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
}
int tinh(int A[],int n,int x)
{
	int Sum=A[0];
	int xi=1;
	for(int i=1;i<n;i++)
	{
		xi*=x;
		Sum=Sum+A[i]*xi;
	}
	return Sum;
}
int main()
{
	int A[100];
	int n,x;
	nhap(A,n,x);
	int kq=tinh(A,n,x);
	printf("%d",kq);
	return 0;
}
