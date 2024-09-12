#include<stdio.h>

void nhap(int a[][100],int &m,int &n)
{
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	scanf("%d",&a[i][j]);
}
void xuat(int a[][100],int m,int n)
{
	for(int i=0;i<m;i++)
	{for(int j=0;j<n;j++){
	printf("%5d",a[i][j]);}
	printf("\n");}
}
/*
void ktra(int a[][100],int m,int n)
{
	int dem;
	int c,d;
	for(int i=0;i<n;i++)
	{
		dem=0;
		for(int j=0;j<m;j++)
		{
			c=i;
			d=j;
			while (a[i][j]!=a[i+1][j] && a[i][j]==a[i][j+1])
			{
				dem++;
			
				
			}
		}
	}
}
*/
int main()
{
	int a[100][100];
	int m,n;
	nhap(a,m,n);
	xuat(a,m,n);
//	ktra(a,m,n);
	return 0;
}
