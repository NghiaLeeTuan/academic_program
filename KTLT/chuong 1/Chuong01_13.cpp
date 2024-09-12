#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct sv
{
	char MSSV[9];
	char Ten[31];
	int Nam;
	int Toan;
	int Ly;
	int Hoa;
	float TB;
};
void nhap(sv a[],int &n)
{
	printf("so sv:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("SV thu %d:\n",i+1);
		printf("nhap MSSV:");
		fflush(stdin);
		gets(a[i].MSSV);
		printf("nhap Ten: ");
		fflush(stdin);
		gets(a[i].Ten);
		printf("nam sinh:");
		scanf("%d",&a[i].Nam);
		printf("Nhap diem Toan, Ly, Hoa:");
		scanf("%d%d%d",&a[i].Toan,&a[i].Ly,&a[i].Hoa);
		a[i].TB=(a[i].Toan+a[i].Ly+a[i].Hoa)/3;
		printf("========================================================\n");
	}
}
void xuat(sv a[],int n)
{
	printf("Danh sach SV vua nhap la:");
	for(int i=0;i<n;i++)
	{
		printf("SV thu %d:\n",i+1);
		printf("MSSV: %s\n",a[i].MSSV);
		printf("Ten SV: %s\n",a[i].Ten);
		printf("Nam sinh: %d\n",a[i].Nam);
		printf("Diem Toan: %d\n",a[i].Toan);
		printf("Diem Ly: %d\n",a[i].Ly);
		printf("Diem Hoa: %d\n",a[i].Hoa);
		printf("Diem TB: %.2f\n",a[i].TB);
		printf("========================================================\n");
	}
}
int main()
{
	sv a[51];
	int n;
	nhap(a,n);
	xuat(a,n);
	return 0;
}
