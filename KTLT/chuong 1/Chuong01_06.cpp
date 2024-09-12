#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct phanso
{
	int tu;
	int mau;
};

void nhap(phanso &a)
{
	printf("nhap tu, mau:");
	scanf("%d%d",&a.tu,&a.mau);
}

void xuat(phanso a)
{
	printf("phan so vua nhap la: %d/%d\n",a.tu,a.mau);
}
int UCLN(int a,int b)
{
	if (a == 0 ||b == 0)
        return a + b;
    while (a != b)
	{
        if (a > b)
		{
            a -= b; 
        }
		else
		{
            b -= a;
        }
    }
    return a;
}	
phanso rutgon(phanso a)
{
	int c=UCLN(a.tu,a.mau);
	a.tu/=c;
	a.mau/=c;
	return a;
}
phanso tinh2(phanso a, phanso b)
{
	phanso d;
	d.tu=a.tu*b.mau+b.tu*a.mau;
	d.mau=a.mau*b.mau;
	phanso c=rutgon(d);
	printf("tong la: %d/%d\n",c.tu,c.mau);
}
phanso tinh3(phanso a, phanso b)
{
	phanso d;
	d.tu=a.tu*b.mau-b.tu*a.mau;
	d.mau=a.mau*b.mau;
	phanso c=rutgon(d);
	printf("hieu la: %d/%d\n",c.tu,c.mau);
}
phanso tinh4(phanso a, phanso b)
{
	phanso c;
	c.tu=a.tu*b.tu;
	c.mau=a.mau*b.mau;
	phanso d=rutgon(c);
	printf("tich la: %d/%d\n",d.tu,d.mau);
}
phanso tinh5(phanso a, phanso b)
{
	phanso c;
	c.tu=a.tu*b.mau;
	c.mau=a.mau*b.tu;
	phanso d=rutgon(c);
	printf("thuong la: %d/%d\n",d.tu,d.mau);
}
phanso tinh6(phanso a,phanso b)
{
	a.tu=a.tu*b.mau;
	a.mau=a.mau*b.mau;
	b.tu=b.tu*a.mau;
	b.mau=b.mau*a.mau;
	printf("quy dong phan so a: %d/%d\n",a.tu,a.mau);
	printf("quy dong phan so b: %d/%d\n",b.tu,b.mau);
}
phanso tinh7(phanso a, phanso b)
{
	int d;
	d=a.tu*b.mau-b.tu*a.mau;
	if (d>0)
	printf("%d/%d > %d/%d",a.tu,a.mau,b.tu,b.mau);
	else if (d<0)
	printf("%d/%d < %d/%d",a.tu,a.mau,b.tu,b.mau);
	else if(d=0)
	printf("%d/%d = %d/%d",a.tu,a.mau,b.tu,b.mau);
}
int main()
{
	phanso a,b;
	printf("nhap phan so a:\n");
	nhap(a);
	xuat(a);
	printf("nhap phan so b:\n");
	nhap(b);
	xuat(b);
	//tong
	phanso tong=tinh2(a,b);
	//hieu
	phanso hieu=tinh3(a,b);
	//tich
	phanso tich=tinh4(a,b);
	//thuong
	phanso thuong=tinh5(a,b);
	//quy dong
	phanso quydong=tinh6(a,b);

	//sosanh
	phanso sosanh=tinh7(a,b);
	
	return 0;
}

