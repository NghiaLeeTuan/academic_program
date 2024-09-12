#include<stdio.h>

int main()
{
	int n;
	int dem=0;
	scanf("%d",&n);
	for(int j=15;j>=0;j--)
	{	printf("%d",(n>>j)&0x01);	}
	
	for(int i=15;i>=0;i--)
	{
		if((n>>i & 0x01)==1)
		dem++;
	}
	printf("\n%d", dem);
	return 0;
}
