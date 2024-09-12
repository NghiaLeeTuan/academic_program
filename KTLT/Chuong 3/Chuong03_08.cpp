#include<stdio.h>

void nhap(int &x)
{
	scanf("%d",&x);
}
void xuat(double x)
{
	printf("%.5f",x);
}

double giaithua(int n)
{
	double a=1;
	for(int i=1;i<=n;i++)
	{
		a=a*i;
	}
	return a;
}
double luythua(int x,int n)
{
	double a=1;
	for(int i=1;i<=n;i++)
	{
		a*=x;
	}
	return a;
}
double tinh(int x)
{
    double sum = 0;
    int i = 0;
    while (luythua(x, i) / giaithua(i) > 1e-10 ) {
        sum += luythua(x, i) / giaithua(i);
        i++;
    }
    return sum;
}
int main()
{
	int x;
	nhap(x);
	double kq=tinh(x);
	xuat(kq);
	return 0;
}
