#include<stdio.h>

float tinh(int n)
{
	float temp=1;
	float a;
	for(int i=1;i<=n;i++)
	{
		temp=temp*(1+1/float(i*i));
	}
	return temp;
}

int main()
{
	int n;
	scanf("%d",&n);
	float kq=tinh(n);
	printf("%.5f",kq);
	return 0;
}
