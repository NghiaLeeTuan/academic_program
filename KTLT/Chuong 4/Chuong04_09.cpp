#include<stdio.h>
#include<math.h>

void nhap(int a[],int &n){
	printf("NHAP SO PHAN TU: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}

int UCLN(int a[],int n)
{
	int b;
	for(int i=0;i<n;i++)
	{
		while(a[i]!=a[i+1])
		{
			if(a[i]>a[i+1])
			{
				a[i]=a[i]-a[i+1];
			}
			else if((a[i]<a[i+1]))
			{
				a[i+1]=a[i+1]-a[i];
			}
		}
		b=a[i];
	}
	return b;
}

void xuat(int x){
	printf("%d",x);
}
int main()
{
	int n;
	int a[100];
	nhap(a,n);
	int kq=UCLN(a,n);
	xuat(kq);
	return 0;
}
