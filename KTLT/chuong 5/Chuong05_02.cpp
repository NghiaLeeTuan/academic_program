#include<stdio.h>
int  power(int n, int r) 
{
  int c, p = 1;

  for (c = 1; c <= r; c++)
     p = p*n;
  return p;  

}

int check_armstrong(int n) {
  int sum = 0, temp;
  int a, k = 0;
  temp = n;
  while (temp != 0) {
     k++;
     temp = temp/10;
  }
  temp = n;
  while (temp != 0) {
     a = temp%10;
     sum = sum + power(a,k);
     temp = temp/10;
  }

  if (n == sum)

     return 1;

  else

     return 0;

}


void nhap(int a[],int &n)
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
int sum(int a[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(check_armstrong(a[i])==1)
		sum=sum+a[i];
	}
	return sum;
}

int main()
{
	int n, a[100];
	nhap(a,n);
	int tong=sum(a,n);
	printf("%d",tong);
	return 0;
}
