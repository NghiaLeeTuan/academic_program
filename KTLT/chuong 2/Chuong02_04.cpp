#include<stdio.h>
#include<conio.h>

void nhap(int a[][50], int &n,int &m)
{
 printf("nhap so dong:");
 scanf("%d",&n);
 printf("nhap so cot:");
 scanf("%d",&m);
 for(int i=0;i<n;i++)
  for(int j=0;j<m;j++)
    {
      scanf("%d",&a[i][j]);
    }
}
void xuat(int a[][50], int n, int m)
{
 for(int i=0;i<n;i++)
  {
   for(int j=0;j<m;j++)
     {
      printf("%4d",a[i][j]);
 }
     printf("\n");
  }
}
void Bien2ChieuThanh1Chieu(int a[][50],int n,int m)
{
 int b[n*m], k=0;
 for(int i=0;i<n;i++)
  {
     for(int j=0;j<m;j++)
        b[k++]=a[i][j];
  }
 for(int z=0;z<k;z++)
 {
 printf("%d ",b[z]);
 }
 
}

int main()
{
 int a[50][50],n,m;
 nhap(a,n,m);
 xuat(a,n,m);
 
 Bien2ChieuThanh1Chieu(a,n,m);
 
 return 0;
}
