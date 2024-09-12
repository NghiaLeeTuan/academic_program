#include <stdio.h>
void nhap(int &x,int &y,int z[][10])
{
	scanf("%d%d",&x,&y);
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			scanf("%d",&z[i][j]);
		}
	}
}

int main()
{
	int a[10][10], b[10][10],c[10][10];
	int x,y,m,n;


	printf("\nNhap vao dong/cot cua ma tran A: ");
	nhap(x,y,a);

	printf("\nNhap vao dong/cot cua ma tran B: ");
	nhap(m,n,b);

	if(y == m)
	{
		for(int i = 0; i < x; i++)
		{
			for(int j = 0; j < n; j++)
			{
				c[i][j] = 0;
				for(int k = 0; k < m; k++)
				{
					c[i][j] += a[i][k] * b[k][j];
				}
			}
		}

		for(int i = 0; i < x; i++)
		{
			for(int j = 0; j < n; j++)
			{
				printf("%d  ",c[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("Khong chia duoc!");
	}
	return 0;
}
