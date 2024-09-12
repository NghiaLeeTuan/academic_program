#include <stdio.h>
#include <conio.h>
unsigned int a[20][20];
unsigned int b[20][20];
int dem;
void lienthong(int i, int j, int m, int n)
{
	if (i != 0)
		if ((a[i][j] == a[i - 1][j]) && (b[i - 1][j] == 0))
		{
			b[i][j] = 1;
			lienthong(i - 1, j, m, n);
			b[i][j] = 0;
		}
	if (i != m - 1)
		if ((a[i][j] == a[i + 1][j]) && (b[i + 1][j] == 0))
		{
			b[i][j] = 1;
			lienthong(i + 1, j, m, n);
			b[i][j] = 0;
		}
	if (j != 0)
		if ((a[i][j] == a[i][j - 1]) && (b[i][j - 1] == 0))
		{
			b[i][j] = 1;
			lienthong(i, j - 1, m, n);
			b[i][j] = 0;
		}
	if (j != n - 1)
		if ((a[i][j] == a[i][j + 1]) && (b[i][j + 1] == 0))
		{
			b[i][j] = 1;
			lienthong(i, j + 1, m, n);
			b[i][j] = 0;
		}
	b[i][j] = 2;
	dem++;
}
int main()
{
	int m, n, i, j, index, spt;
	printf("Nhap kich thuoc ma tran m va n:");
	scanf("%d%d", &m, &n);
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			printf("a[%d][%d]=", i, j);
			scanf("%d", &a[i][j]);
			b[i][j] = 0;
		}
	index = a[0][0];
	spt = 0;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (b[i][j] != 2)
			{
				dem = 0;
				lienthong(i, j, m, n);
				if (dem > spt)
				{
					index = a[i][j];
					spt = dem;
				}
			}
	printf("%d %d", index, spt);
	return 0;
}

