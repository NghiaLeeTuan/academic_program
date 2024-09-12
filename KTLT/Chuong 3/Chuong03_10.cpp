#include<stdio.h>

int ktra(float A)
{
	float b;
	float sum=0;
	float n=1;
	while(sum<=A)
	{
		b=1/n;
		sum+=b;
		n++;
	}
	return n-1;
}

int main()
{
	float A;
	scanf("%f",&A);
	int kq=ktra(A);
	printf("%d",kq);
	return 0;
}
