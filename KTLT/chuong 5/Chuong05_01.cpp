#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

void nhap(int &n)
{
	scanf("%d",&n);
}
void test(int n)
{
	int a,c;
	int temp;
	int b;
	int i=1;
	while(i<=n)
	{
		c=i;
		temp=0;
		b=1;
		printf("%d -----> ",i);
		while(i>0)
		{
			a=i%2;
			temp=temp+a*b;
			b*=10;
			i=i/2;
		}
		printf("%d\n",temp);
		i=c+1;
	}
}

int main()
{
	int n;
	nhap(n);
	test(n);
	return 0;
}
