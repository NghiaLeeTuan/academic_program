#include<stdio.h>

void nhap(int a[50][50],int &m,int &n)
{
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
}

int test1(int a[50][50],int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if (a[i][j]>a[i][j+1] && a[i][j]>a[i][j-1])
			{
				if (a[i][j]>a[i+1][j] && a[i][j]>a[i-1][j])
				{
					return j;
				}
			}
		}
	}
	return -1;
}
int test2(int a[50][50],int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if (a[i][j]>a[i][j+1] && a[i][j]>a[i][j-1])
			{
				if (a[i][j]>a[i+1][j] && a[i][j]>a[i-1][j])
				{
					return i;
				}
			}
		}
	}
	return -1;
}
void test3(int i,int j)
{
	if(i==-1 || j==-1)
	{
		printf("-1");
	}
	else 
	printf("%d     %d",i+1,j+1);
}
int main()
{
	int a[50][50];
	int m,n;
	nhap(a,m,n);
	int j=test1(a,m,n);
	int i=test2(a,m,n);
	test3(i,j);
	return 0;
}
