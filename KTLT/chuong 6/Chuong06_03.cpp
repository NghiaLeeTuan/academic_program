#include<stdio.h>

int fibonacii(int i)
{
	if(i==1 || i ==2) return 1;
	else return fibonacii(i-1) + fibonacii(i-2);
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int c=fibonacii(i);
		printf("%d\n",c);
	}
	return 0;
}
