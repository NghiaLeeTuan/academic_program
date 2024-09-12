#include<stdio.h>
void nhap(int a[],int &n)
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}

int search(int a[],int n)
{
	int x;
	printf("nhap phan tu can tim: ");
	scanf("%d",&x);
	for(int i=0;i<n;i++)
	{
		if (a[i]==x)
		return i+1;
	}
	return -1;
}
void xuat1(int x)
{
	if(x!=-1)
	{
	printf("so can tim nam o vi tri thu %d\n",x);
	}
	else
	{	
	printf(" khong co phan tu trong mang\n");
	}
}
void add(int a[],int n)
{
	int b;
	printf("chon vi tri can them: ");	
	scanf("%d",&b);
	for(int i=n;i>b-1;i--)
	{
		a[i]=a[i-1];
	}
	printf("Phan tu them: ");
	scanf("%d",&a[b-1]);
}
void xuat2(int a[],int n)
{
	printf("mang sau khi them: ");
	for(int i=0; i<=n;i++)
	{
		printf("%d ",a[i]);
	}
}
void del(int a[],int n)
{
	int b;
	printf("\nnhap vi tri can xoa: ");
	scanf("%d",&b);
	for(int i=b-1;i<=n;i++)
	{
		a[i]=a[i+1];
	}
}
void xuat3(int c[],int n)
{
	printf("mang sau khi xoa: ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",c[i]);
	}
}
void opt(int a[],int n)
{
	int b;
	printf("\nNhap vi tri can sua: ");
	scanf("%d",&b);
	printf("Noi dung chinh sua: ");
	scanf("%d",&a[b-1]);
}
void xuat4(int a[],int n)
{
	printf("Mang sau chinh sua: ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
int main()
{
	int a[100];
	int n;
	nhap(a,n);
	//tim kiem
	int timkiem=search(a,n);
	xuat1(timkiem);
	//them
	add(a,n);
	xuat2(a,n);
	//xoa
	del(a,n);
	xuat3(a,n);
	//sua
	opt(a,n);
	xuat4(a,n);
	return 0;
}
