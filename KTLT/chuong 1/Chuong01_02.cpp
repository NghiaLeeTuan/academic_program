#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct phanso
{
	int tu;
	int mau;
};

void nhap(phanso a[],int &n)
{
	printf("so phan tu phan so: ");
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		printf("nhap tu so thu %d: ",i+1);
		scanf("%d", &a[i].tu);
		printf("nhap mau so thu %d: ",i+1);
		scanf("%d",& a[i].mau);
	}
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
phanso tinh1(phanso a[],int n)
{
	int b,d;
	phanso max;
	max.tu=a[0].tu;
	max.mau=a[0].mau;
	for(int i=1; i<n; i++)
	{
		//ucln
		int c= UCLN(max.mau,a[i].mau);
		
		//tim so lon nhat
		if( max.mau == a[i].mau)
		{
			if(max.tu >= a[i].tu)
			{
				max.tu= max.tu;
				max.mau=max.mau;
			}
			else if(max.tu < a[i].tu)
			{
				max.tu=a[i].tu;
				max.mau=a[i].mau;
			}
		}
		else if( max.mau != a[i].mau)
		{
			b=a[i].tu*c;
			d=max.tu*c;
			if( d>=b )
			{
				max.tu=max.tu;
				max.mau=max.mau;
			}
			else if (d<b)
			{
				max.tu=a[i].tu;
				max.mau=a[i].mau;
			}
		}
	}
	printf("phan so lon nhat: %d/%d \n",max.tu, max.mau);
}
phanso tinh2(phanso a[], int n)
{
	phanso b;
	b.mau=a[0].mau;
	b.tu=a[0].tu;
		//tinh tong
	for(int i=1; i<n; i++)
	{
			b.tu=b.tu*a[i].mau+a[i].tu*b.mau;
			b.mau=a[i].mau*b.mau;
	
	}
	int c=UCLN(b.tu,b.mau);
	b.tu=b.tu/c;
	b.mau=b.mau/c;
	printf("tong cac phan so: %d/%d\n",b.tu,b.mau);
}
phanso tinh3(phanso a[],int n)
{
	phanso c;
	c.mau=a[0].mau;
	c.tu=a[0].tu;
	for(int i=1; i<n; i++)
	{
			c.tu=c.tu*a[i].mau-a[i].tu*c.mau;
			c.mau=a[i].mau*c.mau;
	}
	int d=UCLN(c.tu,c.mau);
	c.tu=c.tu/d;
	c.mau=c.mau/d;
	printf("hieu cac phan so: %d/%d\n",c.tu,c.mau);
}
phanso tinh4(phanso a[],int n)
{
	phanso b;
	b.tu=a[0].tu;
	b.mau=a[0].mau;
	for(int i=1;i<n;i++)
	{
		b.tu=b.tu*a[i].tu;
		b.mau=b.mau*a[i].mau;
	}
	int c=UCLN(b.tu,b.mau);
	b.mau=b.mau/c;
	b.tu=b.tu/c;
	printf("tich cac phan so: %d/%d\n",b.tu,b.mau);
}
phanso tinh5(phanso a[],int n)
{
	phanso b[51];
	for(int i=0;i<n;i++)
	{
		b[i].tu=a[i].mau;
		b[i].mau=a[i].tu;
		printf("nghich dao phan so thu %d: %d/%d\n",i+1,b[i].tu,b[i].mau);
	}
	
}
int main()
{
	phanso a[51];
	int n;
	nhap(a,n);
	phanso max=tinh1(a,n);
	phanso tong=tinh2(a,n);
	phanso hieu=tinh3(a,n);
	phanso tich=tinh4(a,n);
	phanso nghichdao=tinh5(a,n);
	return 0;
}
