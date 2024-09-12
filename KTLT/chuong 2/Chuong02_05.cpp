#include<stdio.h>
#include<conio.h>

void nhap(int a[], int &n,int &m)
{
 printf("nhap so dong:");
 scanf("%d",&m);
 printf("nhap so cot:");
 scanf("%d",&n);
 for(int i=0;i<n*m;i++)
    {
      scanf("%d",&a[i]);
    }
}
void Bien1ChieuThanh2Chieu(int a[],int n,int m)
{
 	int b[50][50], k=0;
 	for(int i=0;i<m;i++)
  	{
     	for(int j=0;j<n;j++)
        	b[i][j]=a[k++];
  	}
	for(int i=0;i<m;i++)
  	{
     	for(int j=0;j<n;j++)
			{printf("%d ",b[i][j]);}
		printf("\n");
 	}
 
}

int main()
{
 int a[100],n,m;
 nhap(a,n,m);
 
 Bien1ChieuThanh2Chieu(a,n,m);
 
 return 0;
}
