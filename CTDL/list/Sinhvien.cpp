#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100


struct sv {
	int mssv;
	char Ten[30];
	char ho[30];
	char male[4];
	int tuoi;
	int ngay;
	int thang;
	int nam;
	float dToan;
	float dLy;
	float dHoa;
	float dTB = 0;
	char xLoai[10] = "-";
};
/*
struct ArrList
{
	SinhVien stud[MAX];
	int len=0;
	int maxLen=MAX;
};*/

void Nhap_Thongtin(sv &x);
void Nhap_Soluong(sv A[], int &n);
void Xuat(sv A[],int n);
void Xuat1(sv x);
int Tim (sv A[], int n);
void Xoa(sv A[], int &n,int vt);
void Them(sv A[], int &n, sv x, int vt);
void Xuat2(sv A[],int n,int vt);
int Menu ();


int main()
{


	sv A[100];
	sv x;
	int n;
	int c;
	int vt;

	menu:
	printf ("\n-------------CHON MENU----------");
	printf ("\n1.Nhap 1 sinh vien ");
//	printf ("\n2.Xuat sinh vien vua nhap");
	printf ("\n3.Xuat danh sach sinh vien");
//	printf ("\n4.Xuat 1 sinh vien");
	printf ("\n5.Them sinh vien");
	printf ("\n6.Xoa sinh vien");
	printf ("\n7.Tim sinh vien");
	printf ("\n8.Nhap nhieu sinh vien ");
	printf ("\n9.Xoa man hinh");
	printf ("\n10.Thoat");
	printf ("\n========================================");
	c= Menu();
	switch(c)
	{
		case 1: Nhap_Thongtin(x);	goto menu;
	//	case 2: Xuat1(x);			goto menu;
		case 3: Xuat(A,n);			goto menu;	
	//	case 4: Xuat2(A,n,vt);		goto menu;
		case 5: Them(A,n,x,vt);		goto menu;
		case 6: Xoa(A,n,vt);		goto menu;
		case 7: Xuat2(A,n,vt);		goto menu;
		case 8: Nhap_Soluong(A,n);	goto menu;
		case 9: system("cls");		goto menu;
		case 10:						break;
	}
	return 0;
}
void Nhap_Thongtin(sv &x)
{
	int i;
	printf("Nhap ho va ten lot: ");
	fflush(stdin);
	gets(x.ho);
	int c=strlen(x.ho);
	if(x.ho[0]>='a' && x.ho[0]<='z')
	{
		x.ho[0]-=32;
	}
	for(i=0;i<c;i++)
	{
		if(x.ho[i]==' ')
			{
				if(x.ho[i+1]>='a' && x.ho[i+1]<='z')
				x.ho[i]-=32;}
	}
	printf("Nhap ten : ");
	fflush(stdin);
	gets(x.Ten);
	if(x.Ten[0]>='a' && x.Ten[0]<='z')
	{
		x.Ten[0]-=32;
	}

	printf("Nhap mssv: ");
	scanf("%d",&x.mssv);
	printf("Nhap gioi tinh(Nam/Nu): ");
	fflush(stdin);
	gets(x.male);
	printf("Nhap ngay thang nam sinh(5 11 2002): ");
	scanf("%d%d%d",&x.ngay,&x.thang,&x.nam);
	

}

void Nhap_Soluong(sv A[], int &n)
{
	printf("Nhap so luong sinh vien: ");
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		Nhap_Thongtin(A[i]);
	}
}
void Xuat(sv A[],int n)
{
	printf("\n|%-10d|%-15s|%-9s|%-5s|%-12s%d%d%d|","Ma so sinh vien","Ho va","ten","Gioi tinh","Ngay sinh");
	for (int i=0;i<n;i++)
	{
		Xuat1(A[i]);
	}
}
void Xuat1(sv x)
{
	printf("\n|%-10d|%-15s|%-9s|%-5s|%d%d%d|",x.mssv,x.ho,x.Ten,x.male,x.ngay,x.thang,x.nam);
}
int Tim (sv A[], int n)
{
	int mssv;
	printf("Nhap mssv: ");
	scanf("%d",mssv);
	int kt=0;
	for (int i=0;i<n;i++)
	{
		if(A[i].mssv==mssv)
		{
			kt=1;
			return i;
		}
	}
	if(kt==0)
		return -1;
}
void Xuat2(sv A[],int n,int vt)
{
	vt=Tim(A,n);
	if(vt==-1)
		printf("Khong tim thay");
	else
		Xuat1(A[vt]);

}
void Xoa(sv A[], int &n,int vt)
{ 
	vt=Tim(A,n);
	for(int i=vt;i<n;i++)
	{
		A[i]=A[i+1];
	}
	n--;
}
void Them(sv A[], int &n, sv x, int vt)
{
	printf("\n----------Nhap thong tin sinh vien can them----------\n ");
	Nhap_Thongtin(x);
	printf("Nhap vi tri them vao: ");
	scanf("%d",&vt);
	for (int i=n;i>=vt;i--)
	{
		A[i]=A[i-1];
	}
	A[vt]=x;
	n++;
}
int Menu ()
{
	int c=0;
	printf("\nMoi chon Menu\n");
	scanf("%d",&c);
	if(c>=1 || c<=8)
		return c;
	else
	{
		printf("\nMoi chon lai\n");
		return Menu();
	}
}
