#include<stdio.h>

int giaithua(int x)
{
	int a=1;
	for(int i=x;i>0;i--)
	{
		a*=i;
	}
	return a;
}

int tinh(int a,int b,int c)
{
	int x;
	x=a/(b*c);
	return x;
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int a=giaithua(n);
	int b=giaithua(k);
	int c=giaithua(n-k);
	int x=tinh(a,b,c);
	printf("%d",x);
	return 0;
}
