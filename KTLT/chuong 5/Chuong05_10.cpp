#include <stdio.h>
 
void xuat(int A[], int n);
void sinhToHop(int A[],int n, int k);
 
void sinhToHop(int A[],int n,int k)
{
    int B[100]={0};
    for (int i=0;i<k;i++)
        B[i]=i;
    while (1)
    {
        xuat(B,k);
        int j;
        for (j=k-1;B[j]==n-k+j && j>=0;j--);
        if (j>=0)
            B[j]++;
        else return;
        for (int jj=j+1;jj<k;jj++)
            B[jj]=B[jj-1]+1;
    }
}
 
void xuat(int A[], int n)
{
    for (int i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
}
 
int main()
{	int A[100], n;
	int k;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {	 A[i]=i;	}
    for(k=1;k<=n;k++)    
    {sinhToHop(A,n,k);}
    return 0;
}
 

