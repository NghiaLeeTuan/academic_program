#include<stdio.h>

void ktra(int a[][100],int n)
{
	int b=1;
	int i,j;
	int c,d;
	for(i=n-1;i>=0;i--)
	{	d=0;
		a[i][d]=b;
		b++;
		c=i;
		while ((c+1<n)&&(d+1<n))
		{
			c++;
			d++;
			a[c][d]=b;
			b++;}
	}
			
	for(j=1;j<n;j++)
	{	
		c=0;
		a[c][j]=b;
		b++;
		d=j;
		while((c+1<n)&&(d+1<n))
		{
			d++;
			c++;
			a[c][d]=b;
			b++;}
					
	}
}

void xuat(int a[][100],int n)
{
	for(int i=0;i<n;i++){
	for(int j=0;j<n;j++)
	{printf("%5d ",a[i][j]);}
	printf("\n");}
}

int main()
{
	int a[100][100],n;
	scanf("%d",&n);
	if(n<3 || n>10) { printf("nhap sai");
		return 0;}
	else{
	ktra(a,n);
	xuat(a,n);}
	return 0;
}
