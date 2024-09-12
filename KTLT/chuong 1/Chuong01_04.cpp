#include <iostream>
#include <math.h>
using namespace std;

struct tg {
	int ngay;
	int thang;
	int nam;
};
void nhap(tg& a);
void xuat(tg a);
tg khoangCach(tg a, tg b);
int namNhuan(int i);
int demNgay(tg a);
int ngayThang(int i, int y);

void main()
{
	tg a;
	tg b;
	nhap(a);
	nhap(b);
	xuat(a);
	xuat(b);
	khoangCach(a, b);
	

}

void nhap(tg& a)
{
	cout << "nhap ngay thang nam: ";
	cin >> a.ngay >> a.thang >> a.nam;
}

void xuat(tg a)
{
	printf("%d %d %d\n", a.ngay, a.thang, a.nam);
}
tg khoangCach(tg a, tg b)
{
	int kc1 = demNgay(a);
	int kc2 = demNgay(b);
	int kc = abs(kc1 - kc2);
	printf("%d", kc);
	return a;

}
int namNhuan(int i)
{
	if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
		return 1;
	return 0;
}

int demNgay(tg a)
{
	int kc = 0;
	for (int i = 1; i < a.nam; i++)
	{
		if (namNhuan(i))
			kc = kc + 366;
		else
			kc = kc + 365;
	}
	for (int i = 1; i < a.thang; i++)
	{
		kc = kc + ngayThang(i,a.nam);
	}
	kc = kc + a.ngay;
	return kc;
}
int ngayThang(int i, int y)
{
	if (i == 2)
	{
		if (namNhuan(y))
			return 29;
		else
			return 28;
	}
	else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
		return 31;
	else
		return 30;
}
