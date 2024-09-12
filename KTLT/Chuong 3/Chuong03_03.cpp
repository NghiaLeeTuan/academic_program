#include<stdio.h>

int tinh(int n)
{
	int a=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			a=a+j;
		}
	}
	return a;
}

int main()
{
	int n;
	scanf("%d",&n);
	int kq=tinh(n);
	printf("%d",kq);
	return 0;
}
