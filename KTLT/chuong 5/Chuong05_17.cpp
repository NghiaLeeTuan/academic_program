#include<stdio.h>

int tinh(int n)
	{
		if(n==0)return 0;
		if(n==1)return 1;
		if(n%2==0){
			return tinh(n/2);
		}else{
			return tinh(n/2) + tinh(n/2+1);
		}
	}

int main()
{
	int n;
	scanf("%d",&n);
	int f=tinh(n);
	printf("%d",f);
	return 0;
}
