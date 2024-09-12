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

int min(int a[],int n)
{
	int min=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<min)
		min=a[i];
	}
	return min;
}
void xuat(int x)
{
	printf("%d",x);
}

int main()
{
	int a[100];
	int n;
	nhap(a,n);
	int b=min(a,n);
	xuat(b);
	return 0;
}
