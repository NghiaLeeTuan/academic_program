#include<conio.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include<fstream>
#include <iomanip>

using namespace std;
//tao cau truc sinh vien


struct SinhVien
{
	int mssv;
	string ho;
	string ten;
	int ngay;
	int thang;
	int nam;
	string sex;
	float dtoan;
	float dhoa;
	float dly;
	float dtb;
};
//tao cau truc danh sach lien ket don
struct Node
{
	SinhVien* data;
	Node* pNext;
};
struct SingleList
{
	Node* pHead;
};

//khoi tao danh sach lien ket don
void Initialize(SingleList*& list)
{
	list = new SingleList;
	list->pHead = NULL;
}

//ktra ngay
bool laNamNhuan(int nYear)
{
	if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
	{
		return true;
	}
	return false;

}

int tinhSoNgayTrongThang(int nMonth, int nYear)
{
	int nNumOfDays;

	switch (nMonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		nNumOfDays = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		nNumOfDays = 30;
		break;
	case 2:
		if (laNamNhuan(nYear))
		{
			nNumOfDays = 29;
		}
		else
		{
			nNumOfDays = 28;
		}
		break;
	}

	return nNumOfDays;
}
bool checkday(int nDay, int nMonth, int nYear)
{

	if (nYear < 0)
	{
		return false; // Ngày không còn h?p l? n?a!
	}

	if (nMonth < 1 || nMonth > 12)
	{
		return false; // Ngày không còn h?p l? n?a!
	}

	// Ki?m tra ngày
	if (nDay < 1 || nDay > tinhSoNgayTrongThang(nMonth, nYear))
	{
		return false;
	}

	return true;
}

//nhap thong tin sinh vien
SinhVien* NhapSinhVien()
{
	SinhVien* sv = new SinhVien;
	cout << "Nhap MSSV: ";
	cin >> sv->mssv;
	cin.ignore();
	cout << "Nhap ho va ten lot: ";
	getline(cin, sv->ho);
	int c = sv->ho.length();
	if (sv->ho[0] >= 'a' && sv->ho[0] <= 'z')
	{
		sv->ho[0] -= 32;
	}
	for (int i = 1;i < c;i++)
	{
		if (sv->ho[i] == ' ')
		{
			if (sv->ho[i + 1] >= 'a' && sv->ho[i + 1] <= 'z')
				sv->ho[i + 1] -= 32;
		}
	}
	cout << "Nhap ten: ";
	getline(cin, sv->ten);
	if (sv->ten[0] >= 'a' && sv->ten[0] <= 'z')
	{
		sv->ten[0] -= 32;
	}

	int s;
	char sex[] = "Nam";
	char sex1[] = "Nu";
	while (true) {
		cout << "Nhap gioi tinh(0:Nam/1:Nu): ";
		cin >> s;
		if (s == 0)
		{
			sv->sex.replace(0, 3, sex);
			break;
		}
		else if (s == 1)
		{
			sv->sex.replace(0, 3, sex1);
			break;
		}
		else
			cout << "Nhap sai!!,Nhap lai!!";
	}
	while (true) {
		cout << "Nhap ngay thang nam sinh(5 11 2002): ";
		cin >> sv->ngay >> sv->thang >> sv->nam;
		if (checkday(sv->ngay, sv->thang, sv->nam))
		{
			break;
		}
		else
		{
			cout << "Nhap sai, Vui long nhap lai!!\n";
		}
	}
	cout << "Diem Toan: ";
	cin >> sv->dtoan;
	cout << "Diem Ly: ";
	cin >> sv->dly;
	cout << "Diem hoa: ";
	cin >> sv->dhoa;
	sv->dtb = (sv->dhoa + sv->dly + sv->dtoan) / 3;
	return sv;
}


//tao node sinh vien
Node* CreateNode(SinhVien* sv)
{
	Node* pNode = new Node;
	if (pNode != NULL)
	{
		pNode->data = sv;
		pNode->pNext = NULL;
	}
	else
	{
		cout << "cap phat bo nho that bai!!!";
	}
	return pNode;
}
//them node vao cuoi danh sach
void InsertLast(SingleList*& list, SinhVien* sv)
{
	Node* pNode = CreateNode(sv);
	if (list->pHead == NULL)
	{
		list->pHead = pNode;
	}
	else
	{
		Node* pTmp = list->pHead;

		while (pTmp->pNext != NULL)
		{
			pTmp = pTmp->pNext;
		}
		pTmp->pNext = pNode;
	}
}

//them node vao dau danh sach
void InsertFirst(SingleList*& list, SinhVien* sv)
{
	Node* pNode = CreateNode(sv);
	pNode->pNext = list->pHead;
	list->pHead = pNode;
}

void InsertAt(SingleList*& list, SinhVien* sv) {
	Node* pNode = CreateNode(sv);
	int n;
	cout << "Nhap vi tri can them: ";
	cin >> n;
	n--;
	if (n == 0 || list->pHead == NULL) {
		pNode->pNext = list->pHead;
		list->pHead = pNode;
	}
	else {
		int k = 1;
		Node* p = list->pHead;
		while (p != NULL && k != n) {
			p = p->pNext;
			++k;
		}

		if (k != n) {
			if (list->pHead == NULL)
			{
				list->pHead = pNode;
			}
			else
			{
				Node* pTmp = list->pHead;

				while (pTmp->pNext != NULL)
				{
					pTmp = pTmp->pNext;
				}
				pTmp->pNext = pNode;
			}
		}
		else {
			Node* temp = CreateNode(sv);
			temp->pNext = p->pNext;
			p->pNext = temp;
		}
	}
}

//hien thi danh sach
void PrintList(SingleList* list)
{
	int i = 1;
	cout << setw(5) << left << "|STT" << setw(10) << left << "|MSSV" << setw(15) << left << "|Ho va" << setw(10) << left << "Ten" << setw(15) << left << "|Gioi tinh" << setw(12) << left << "|Ngay sinh" << setw(10) << left << "|Diem Toan" << setw(10) << left << "|Diem Ly" << setw(10) << left << "|Diem hoa" << setw(10) << left << "|Diem TB" << "\n";
	Node* pTmp = list->pHead;
	if (pTmp == NULL)
	{
		cout << "Danh sach rong";
		return;
	}
	while (pTmp != NULL)
	{
		SinhVien* sv = pTmp->data;
		cout << "|" << setw(4) << left << i << "|" << setw(9) << left << sv->mssv << "|" << setw(14) << left << sv->ho << setw(10) << left << sv->ten << "|" << setw(14) << left << sv->sex << "|" << setw(2) << left << sv->ngay << "/" << setw(2) << left << sv->thang << "/" << setw(5) << left << sv->nam << "|" << setw(9) << left << sv->dtoan << "|" << setw(9) << left << sv->dly << "|" << setw(9) << left << sv->dhoa << "|" << setw(9) << left << sv->dtb << "\n";
		pTmp = pTmp->pNext;
		i++;
	}
}

//xuat 2
void output(SinhVien* sv, int i)
{

	cout << "|" << setw(4) << left << i << "|" << setw(9) << left << sv->mssv << "|" << setw(14) << left << sv->ho << setw(10) << left << sv->ten << "|" << setw(14) << left << sv->sex << "|" << setw(2) << left << sv->ngay << "/" << setw(2) << left << sv->thang << "/" << setw(5) << left << sv->nam << "|" << setw(9) << left << sv->dtoan << "|" << setw(9) << left << sv->dly << "|" << setw(9) << left << sv->dhoa << "|" << setw(9) << left << sv->dtb << "\n";

}

//tim sv theo MSSV
void Find1(SingleList* list)
{
	Node* p;
	int k;
	cout << "Nhap MSSV can tim: ";
	cin >> k;
	int dem = 1;

	p = list->pHead;
	cout << setw(5) << left << "|STT" << setw(10) << left << "|MSSV" << setw(15) << left << "|Ho va" << setw(10) << left << "Ten" << setw(15) << left << "|Gioi tinh" << setw(12) << left << "|Ngay sinh" << setw(10) << left << "|Diem Toan" << setw(10) << left << "|Diem Ly" << setw(10) << left << "|Diem hoa" << setw(10) << left << "|Diem TB" << "\n";
	while (p != NULL)
	{
		if (p->data->mssv == k)
		{
			output(p->data, dem);
			dem++;
		}
		p = p->pNext;
	}
	if (dem == 1)
	{
		cout << "Khong co sinh vien can tim!!";
	}
}
//check ten
bool SoSanh(string s1, string s2)
{

	for (unsigned int i = 0; i < s1.size(); i++) {

		if (s1[i] >= 'a' && s1[i] <= 'z') {

			s1[i] -= 32;
		}
	}

	for (unsigned int i = 0; i < s2.size(); i++) {

		if (s2[i] >= 'a' && s2[i] <= 'z') {

			s2[i] -= 32;
		}
	}

	if (s1.compare(s2) == 0)
	{
		return true;
	}

	return false;
}

//tim sv theo ten
void Find2(SingleList* list)
{
	Node* p;
	char k[30];

	cout << "Nhap ten sv can tim: ";
	cin >> k;
	if (k[0] >= 'a' && k[0] <= 'z')	k[0] -= 32;
	int dem = 1;
	p = list->pHead;
	cout << setw(5) << left << "|STT" << setw(10) << left << "|MSSV" << setw(15) << left << "|Ho va" << setw(10) << left << "Ten" << setw(15) << left << "|Gioi tinh" << setw(12) << left << "|Ngay sinh" << setw(10) << left << "|Diem Toan" << setw(10) << left << "|Diem Ly" << setw(10) << left << "|Diem hoa" << setw(10) << left << "|Diem TB" << "\n";
	while (p != NULL)
	{
		if (SoSanh(p->data->ten, k))
		{
			output(p->data, dem);
			dem++;
		}
		p = p->pNext;
	}
	if (dem == 1)
	{
		cout << "Khong co sinh vien can tim!!";
	}
}

//sap xep theo diem TB
void SortList1(SingleList*& list)
{
	for (Node* pTmp = list->pHead;pTmp != NULL;pTmp = pTmp->pNext)
	{
		for (Node* pTmp2 = pTmp->pNext;pTmp2 != NULL;pTmp2 = pTmp2->pNext)
		{
			SinhVien* svTmp = pTmp->data;
			SinhVien* svTmp2 = pTmp2->data;
			if (svTmp2->dtb > svTmp->dtb)
			{
				int mssv = svTmp->mssv;
				string ten;
				string ho;
				string sex;
				int d = svTmp->ngay;
				int m = svTmp->thang;
				int y = svTmp->nam;
				float t = svTmp->dtoan;
				float l = svTmp->dly;
				float h = svTmp->dhoa;
				float tb = svTmp->dtb;
				ten.replace(0, svTmp->ten.length(), svTmp->ten);
				ho.replace(0, svTmp->ho.length(), svTmp->ho);
				sex.replace(0, svTmp->sex.length(), svTmp->sex);

				svTmp->mssv = svTmp2->mssv;
				svTmp->dtoan = svTmp2->dtoan;
				svTmp->dly = svTmp2->dly;
				svTmp->dhoa = svTmp2->dhoa;
				svTmp->dtb = svTmp2->dtb;
				svTmp->ngay = svTmp2->ngay;
				svTmp->thang = svTmp2->thang;
				svTmp->nam = svTmp2->nam;
				svTmp->ten.replace(0, svTmp2->ten.length(), svTmp2->ten);
				svTmp->sex.replace(0, svTmp2->sex.length(), svTmp2->sex);
				svTmp->ho.replace(0, svTmp2->ho.length(), svTmp2->ho);

				svTmp2->mssv = mssv;
				svTmp2->dtoan = t;
				svTmp2->dly = l;
				svTmp2->dhoa = h;
				svTmp2->dtb = tb;
				svTmp2->ngay = d;
				svTmp2->thang = m;
				svTmp2->nam = y;
				svTmp2->ten.replace(0, ten.length(), ten);
				svTmp2->sex.replace(0, sex.length(), sex);
				svTmp2->ho.replace(0, ho.length(), ho);
			}
		}
	}
}
//sap xep theo MSSV
void SortList(SingleList*& list)
{
	for (Node* pTmp = list->pHead;pTmp != NULL;pTmp = pTmp->pNext)
	{
		for (Node* pTmp2 = pTmp->pNext;pTmp2 != NULL;pTmp2 = pTmp2->pNext)
		{
			SinhVien* svTmp = pTmp->data;
			SinhVien* svTmp2 = pTmp2->data;
			if (svTmp2->mssv < svTmp->mssv)
			{
				int mssv = svTmp->mssv;
				string ten;
				string ho;
				string sex;
				int d = svTmp->ngay;
				int m = svTmp->thang;
				int y = svTmp->nam;
				float t = svTmp->dtoan;
				float l = svTmp->dly;
				float h = svTmp->dhoa;
				float tb = svTmp->dtb;
				ten.replace(0, svTmp->ten.length(), svTmp->ten);
				ho.replace(0, svTmp->ho.length(), svTmp->ho);
				sex.replace(0, svTmp->sex.length(), svTmp->sex);

				svTmp->mssv = svTmp2->mssv;
				svTmp->dtoan = svTmp2->dtoan;
				svTmp->dly = svTmp2->dly;
				svTmp->dhoa = svTmp2->dhoa;
				svTmp->dtb = svTmp2->dtb;
				svTmp->ngay = svTmp2->ngay;
				svTmp->thang = svTmp2->thang;
				svTmp->nam = svTmp2->nam;
				svTmp->ten.replace(0, svTmp2->ten.length(), svTmp2->ten);
				svTmp->sex.replace(0, svTmp2->sex.length(), svTmp2->sex);
				svTmp->ho.replace(0, svTmp2->ho.length(), svTmp2->ho);

				svTmp2->mssv = mssv;
				svTmp2->dtoan = t;
				svTmp2->dly = l;
				svTmp2->dhoa = h;
				svTmp2->dtb = tb;
				svTmp2->ngay = d;
				svTmp2->thang = m;
				svTmp2->nam = y;
				svTmp2->ten.replace(0, ten.length(), ten);
				svTmp2->sex.replace(0, sex.length(), sex);
				svTmp2->ho.replace(0, ho.length(), ho);
			}
		}
	}
}

//xoa
void RemoveNode(SingleList*& list) {
	cout << "\nBan muon xoa sinh vien co MSSV: ";
	int mssv;
	cin >> mssv;
	Node* pDel = list->pHead;
	if (pDel == NULL)
	{
		cout << "Danh sach rong!" << "\n";
	}
	else
	{
		Node* pPre = NULL;
		while (pDel != NULL)
		{
			SinhVien* sv = pDel->data;
			if (sv->mssv == mssv)
				break;
			pPre = pDel;
			pDel = pDel->pNext;
		}
		if (pDel == NULL)
		{
			cout << "khong tim thay MSSV: " << mssv << "\n";
		}
		else
		{
			if (pDel == list->pHead)
			{
				list->pHead = list->pHead->pNext;
				pDel->pNext = NULL;
				delete pDel;
				pDel = NULL;
			}
			else
			{
				pPre->pNext = pDel->pNext;
				pDel->pNext = NULL;
				delete pDel;
				pDel = NULL;
			}
			cout << "Da xoa sinh vien!!" << "\n";
		}
	}
}

void deleteHead(SingleList*& list) {
	Node* pDel = list->pHead;
	if (pDel == NULL)
	{
		cout << "Danh sach rong!";
	}
	list->pHead = list->pHead->pNext;
	pDel->pNext = NULL;
	delete pDel;
	pDel = NULL;
	cout << "Da xoa sinh vien!!" << "\n";
}

void deleteTail(SingleList*& list) {
	Node* pDel = list->pHead;
	if (pDel == NULL)
	{
		cout << "Danh sach rong!\n";
	}
	while (pDel->pNext->pNext != NULL) {
		pDel = pDel->pNext;
	}
	delete(pDel->pNext);
	pDel->pNext = NULL;
	cout << "Da xoa sinh vien!!" << "\n";
}

void deleteAt(SingleList*& list) {
	int k;
	cout << "Xoa vi tri thu: ";
	cin >> k;
	Node* pDel = list->pHead;
	if (pDel == NULL)
	{
		cout << "Danh sach rong!\n";
	}
	for (int i = 0; i < k - 2; i++) {
		pDel = pDel->pNext;
	}
	Node* temp = pDel->pNext;
	pDel->pNext = pDel->pNext->pNext;
	delete(temp);

}

//menu
void Printmenu()
{
	cout << "\n-------------CHON MENU-----------";
	cout << "\n|       1.Them 1 sinh vien      |";
	cout << "\n|2.Them nhieu sinh vien vao cuoi|";
	cout << "\n|        3.Xoa 1 sinh vien      |";
	cout << "\n|         4.Tim sinh vien       |";
	cout << "\n|          5.In danh sach       |";
	cout << "\n|       6.Sap xep danh sach     |";
	//	cout<< "\n|           7.Doc file          |";
	//	cout<< "\n|          8.Xuat file          |";
	cout << "\n|           ctrl+Q.Thoat        |";
	cout << "\n=================================\n";
}

void menusort()
{
	cout << "\n-------------CHON MENU-----------";
	cout << "\n|           1.Theo mssv         |";
	cout << "\n|            2.Theo dtb         |";
	cout << "\n|             0.Thoat           |";
	cout << "\n=================================\n";
}

void Sort(SingleList*& list)
{
	int c;
	while (true) {
		menusort();
		cout << "Nhap lua chon: ";
		cin >> c;
		if (c == 1) {
			system("cls");
			SortList(list);		break;
		}
		else if (c == 2) {
			system("cls");
			SortList1(list);	break;
		}
		else if (c == 0) {
			system("cls");
			break;
		}
		else {
			system("cls");
			cout << "Khong co lua chon!!\n";
		}
	}
}

void menuadd()
{
	cout << "\n-------------CHON MENU-----------";
	cout << "\n|         1.Them vao dau        |";
	cout << "\n|        2.Them vao cuoi        |";
	cout << "\n|    3.Them vao vi tri thu p    |";
	cout << "\n|             0.Thoat           |";
	cout << "\n=================================\n";
}

void Add(SingleList*& list, SinhVien* sv)
{
	int c;
	while (true) {
		menuadd();
		cout << "Nhap lua chon: ";
		cin >> c;
		if (c == 1) {
			system("cls");
			InsertFirst(list, sv);	break;
		}
		else if (c == 2) {
			system("cls");
			InsertLast(list, sv);	break;
		}
		else if (c == 3) {
			system("cls");
			InsertAt(list, sv);		break;
		}
		else if (c == 0) {
			system("cls");
			break;
		}
		else {
			system("cls");
			cout << "Khong co lua chon!!\n";
		}
	}
}

void menufind()
{
	cout << "\n-------------CHON MENU-----------";
	cout << "\n|           1.Theo MSSV         |";
	cout << "\n|           2.Theo ten          |";
	cout << "\n|             0.Thoat           |";
	cout << "\n=================================\n";
}

void Find(SingleList* list)
{
	int c;
	while (true) {
		menufind();
		cout << "Nhap lua chon: ";
		cin >> c;
		if (c == 1) {
			system("cls");
			Find1(list);	break;
		}
		else if (c == 2) {
			system("cls");
			Find2(list);	break;
		}
		else if (c == 0) {
			system("cls");
			break;
		}
		else {
			system("cls");
			cout << "Khong co lua chon!!\n";
		}
	}
}

void menuremove()
{
	cout << "\n-------------CHON MENU-----------";
	cout << "\n|            1.Xoa dau          |";
	cout << "\n|           2.Xoa cuoi          |";
	cout << "\n|       3.Xoa tai vi tri p      |";
	cout << "\n|         4.Xoa theo MSSV       |";
	cout << "\n|             0.Thoat           |";
	cout << "\n=================================\n";
}

void Remove(SingleList*& list)
{
	int c;
	while (true) {
		menuremove();
		cout << "Nhap lua chon: ";
		cin >> c;
		if (c == 1) {
			system("cls");
			deleteHead(list);	break;
		}
		else if (c == 2) {
			system("cls");
			deleteTail(list);	break;
		}
		else if (c == 3) {
			system("cls");
			deleteAt(list);		break;
		}
		else if (c == 4) {
			system("cls");
			RemoveNode(list); 	break;
		}
		else if (c == 0) {
			system("cls");
			break;
		}
		else {
			system("cls");
			cout << "Khong co lua chon!!\n";
		}
	}
}

SinhVien* doc(ifstream& file, SinhVien* a)
{
	SinhVien* sv = new SinhVien();
	file >> sv->mssv;
	cout << sv->mssv;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(file, sv->ho);
	cout << sv->ho;
	getline(file, sv->ten);
	getline(file, sv->sex);
	file >> sv->ngay;
	file >> sv->thang;
	file >> sv->nam;
	file >> sv->dtoan;
	file >> sv->dly;
	file >> sv->dhoa;
	sv->dtb = (sv->dtoan + sv->dly + sv->dhoa) / 3;
	return sv;
}

void docfile(SingleList*& list, ifstream& file)
{
	int n = 0;
	int i;
	SinhVien* a=new SinhVien();

	while (file.eof() == false) {
		a = doc(file, a);
		n++;
		InsertLast(list, a);
	}
	cout << "So luong sv co trong file: " << n << endl;
	cout << "\nDoc file thanh cong!!\n";
}

int main(int argc, char** argv) {
	SingleList* list;
	Initialize(list);


	/*
	   int x;
	   cout<<"Nhap so sinh vien dau vao: ";
	   cin>>x;
	   for(int i=0;i<x;i++){
	   SinhVien *tao=NhapSinhVien();
	   InsertLast(list,tao);
	   }*/




	int c;
	do {

		Printmenu();
		cout << "Nhap lua chon cua ban: ";
		cin >> c;
		if (c == 1) {
			system("cls");
			SinhVien* a = NhapSinhVien();	Add(list, a);
		}
		else if (c == 2) {
			system("cls");
			cout << "Nhap so sinh vien can them: ";
			int add;
			cin >> add;
			for (int i = 0;i < add;i++) {
				SinhVien* a = NhapSinhVien();
				InsertLast(list, a);
			}
		}
		else if (c == 3) {
			system("cls");
			Remove(list);
		}
		else if (c == 4) {
			system("cls");
			Find(list);
		}
		else if (c == 5) {
			system("cls");
			PrintList(list);
		}
		else if (c == 6) {
			system("cls");
			Sort(list);
		}
		else if (c == 7) {
			system("cls");

			std::ifstream file;
			file.open("D://testlist.txt", ios_base::in);
			docfile(list, file);
			file.close();
		}

		//	else if(c==8){			system("cls");
		//	xuatfile()}
		else if (c == 0) {
			system("cls");
			cout << "Da thoat chuong trinh!!";	break;
		}
		else
			cout << "Khong co lua chon, Nhap lai!!";

	} while (true);

}