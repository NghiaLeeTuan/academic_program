#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int b=1;
	for(int i=n;i>1;i--)
	{b*=i;};
	printf("%d",b);
	return 0;
}
