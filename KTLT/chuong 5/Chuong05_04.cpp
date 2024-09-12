#include<stdio.h>
#include<conio.h>


void on(int x)
{
	int i;
	printf("\nBat bit thu i: ");
	scanf("%d",&i);
	x= x | (0x01<<(i-1));
	for(int j=15;j>=0;j--)
	{	printf("%d", (x >> j) & 0x01);	}
}

void off(int x)
{
	int i;
	printf("\nTat bit thu i: ");
	scanf("%d",&i);
	x= x&(~(0x1<<(i-1)));
	for(int j=15;j>=0;j--)
	{	printf("%d", (x >> j) & 0x01);	}
}

void take(int x)
{
	int i;
	printf("\nNhap vi tri can lay: ");
	scanf("%d",&i);
	printf("%d", (x>>(i-1)) & 0x01);
}

int main()
{
	int x;
	scanf("%d",&x);
	for(int j=15;j>=0;j--)
	{	printf("%d", (x >> j) & 0x01);	}
	off(x);
	on(x);
	take(x);
	
	return 0;
}
