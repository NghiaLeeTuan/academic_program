#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct Date
{
	int ngay, thang, nam;
};

struct sinhvien
{
	char MSSV[6];
	char hoten[31];
	Date ngaysinh;
	char diachi[51];
	char phai[4];
	float diemtb;
};

void nhap(sinhvien a[], int &n)
{
	printf("nhap so sv:");
	scanf("%d",&n);
	for(int i=0; i<n ;i++)
	{
		fflush(stdin);
		printf("nhap MSSV: ");
		gets(a[i].MSSV);
		fflush(stdin);
		printf("nhap ho ten: ");
		gets(a[i].hoten);
		
		printf("nhap ngay sinh: ");
		scanf("%d%d%d",&a[i].ngaysinh.ngay,&a[i].ngaysinh.thang,&a[i].ngaysinh.nam);
		fflush(stdin);
		printf("nhap dia chi: ");
		gets(a[i].diachi);
		fflush(stdin);
		printf("nhap phai:");
		gets(a[i].phai);
		
		printf("nhap diem tb: ");
		scanf("%f",&a[i].diemtb);
	}
}

sinhvien trentb(sinhvien a[],int n)	
{
	int b=0;
	for(int i=0;i<n;i++)
	{
		if(a[i].diemtb >= 5.0)
		{
			b++;
			printf("%s\n",a[i].MSSV);
			printf("%s\n",a[i].hoten);
			printf("%.2f\n",a[i].diemtb);
		}
	}
	printf("sv dat dk: %d",b);
}

int main()
{
	sinhvien a[51];
	int n;
	nhap(a,n);
	printf("================================================================\n");
	sinhvien kq=trentb(a,n);
	return 0;
}
