#include<stdio.h>
#include<math.h>

struct sophuc
{
	int thuc;
	int ao;
};

void nhap(sophuc a[],int &n)
{
	printf("nhap so phan tu:");
	scanf("%d",&n);
	for(int i=0 ; i<n; i++)
	{
	printf("phan tu thu %d:\n",i+1);
	printf("phan thuc: ");
	scanf("%d",&a[i].thuc);
	printf("phan ao: ");
	scanf("%d",&a[i].ao);
	printf("so phuc thu %d la: %d + %di\n",i+1,a[i].thuc,a[i].ao);
	}
}
sophuc tinh(sophuc a[],int n)
{
	//tinh tong
	sophuc c;
	c.ao=a[0].ao;
	c.thuc=a[0].thuc;
	for(int i=1;i<n;i++)
	{
		c.thuc+=a[i].thuc;
		c.ao+=a[i].ao;
		printf("tong la: %d + %di\n",c.thuc,c.ao);
	}
	//tinh hieu
	sophuc d;
	d.ao=a[0].ao;
	d.thuc=a[0].thuc;
	for(int i=1;i<n;i++)
	{
		d.thuc-=a[i].thuc;
		d.ao-=a[i].ao;
	printf("hieu la: %d + %di\n",d.thuc,d.ao);
	}	
	//tich
	int e,f;
	sophuc h;
	h.ao=a[0].ao;
	h.thuc=a[0].thuc;
	for(int i=1;i<n;i++)
	{
		e=h.thuc*a[i].thuc-h.ao*a[i].ao;
		f=h.thuc*a[i].ao+h.ao*a[i].thuc;
	printf("tich la: %d + %di\n",e,f);
	}	
}
int main()
{	
	sophuc a[51];
	int n;
	nhap(a,n);
	sophuc c=tinh(a,n);
	return 0;
}
