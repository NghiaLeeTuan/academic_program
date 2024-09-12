#include<stdio.h>

void nhap(int a[],int &n)
{
	printf("NHAP SO PHAN TU: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}

int tim(int a[],int n)
{
	int max=0;
	int c=1;
	int e;
	int temp;
	//sap xep mang giam dan
	for(int i=0;i<n;i++)
	{
		if(a[i]<=a[i+1])
		{temp=a[i];
		a[i]=a[i+1];
		a[i+1]=temp;}
		for(int j=i;j>=0;j--)
			if(a[j-1]<a[j])
			{temp=a[j-1];
			a[j-1]=a[j];
			a[j]=temp;}	
	}
	
	for(int i=0;i<n;i++)
	{
		//dem gia tri trung a[i]
		for(int j=i+1;j<n;j++)
		{if(a[i]==a[j])	c++;}
		if(c>max)
		{
			e=a[i];
			max=c;
		}
		//khoi tao bien dem
		c=1;
	}
	return e;
}

void xuat(int x)
{
	printf("%d",x);
}
int main()
{
	int n;
	int a[100];
	nhap(a,n);
	int kq=tim(a,n);
	xuat(kq);
	return 0;
}
