#include<stdio.h>

int tinh(int n,int k)
{
	int tu=1;
	int mau1=1,mau2=1;
	int a;
	if(n>=k)
	{
	for(int i=n;i>1;i--)
	{tu*=i;}
	for(int j=k;j>1;j--)
	{mau1*=j;}
	for(int e=n-k;e>1;e--)
	{mau2*=e;}
	a=tu/(mau1*mau2);
	return a;
	}
	else if(n<k)
	{
		return -1;
	}
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int b=tinh(n,k);
	printf("%d",b);
	return 0;
}
