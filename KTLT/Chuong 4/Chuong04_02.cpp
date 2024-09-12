#include<stdio.h>

void nhap(int a[],int &n)
{
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void xuat(int b)
{printf("%d",b);}

int sum(int a[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{sum+=a[i];}
	return sum;
}

int main()
{
	int a[100];
	int n;
	nhap(a,n);
	int b=sum(a,n);
	xuat(b);
	return 0;
}
