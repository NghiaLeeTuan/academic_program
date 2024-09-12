#include <stdio.h>
void try(int i, int m, int *s, int n) {
	int z;
	for(z=s[i-1] + 1; z<=n; z++) {
		s[i] = z;
		if(i==m) {
			int k;
			for(k=1; k<=m; k++) {
				printf("%d", s[k]);
			}
			printf("\n");
		}
		else {
			try(i+1, m, s, n);
		}
	}
}
int main()
{
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	int *s= NULL;
	a=new int[n];
	
 	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	for(i=0; i<=n; i++) 
	{
		xuat(a, n);
        ktra(a, n);
	}
	return 0;
}
