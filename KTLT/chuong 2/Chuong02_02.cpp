#include<stdio.h>
void nhap(int a[],int &n,int &x)
{
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	printf("Cac phan tu can nhap: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Phan tu can tim la: ");
	scanf("%d",&x);
}
int search(int a[],int n,int x)
{
	int mid=n/2;
	if(a[mid]==x)
	{
		return mid;
	}
	else if(a[mid]>x)
	{
		for(int i=mid+1;i<n;i++)
		{
			if(a[i]==x)
			{
				return i;
			}
			
		}
		return -1;
	}
		else if(a[mid]<x)
	{
		for(int i=mid-1;i>=0;i--)
		{
			if(a[i]==x)
			{
				return i;
			}
			return -1;
		}
	}
	
}
void xuat(int ktra)
{
	if(ktra!=-1)
	{
		printf("phan tu x nam o vi tri %d",ktra+1);
	}
	else 
	{
		printf("khong co phan tu x trong mang");
	}
}

int main()
{
	int a[100];
	int n,x;
	nhap(a,n,x);
	int ktra=search(a,n,x);
	xuat(ktra);
	return 0;
}


