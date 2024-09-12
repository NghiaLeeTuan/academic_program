#include<stdio.h>

void NP(int n)
{	int a=1;
	int c=0;
	while(n>0)
	{
		int b;
		b=n%2;
		n=n/2;
		c=b*a+c;
		a*=10;
	}
	printf("%d",c);
	printf("\n");
}

int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		printf("%d--->",i);
		NP(i);
	}
	
	return 0;
}
