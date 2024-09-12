#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct date
{
	int ngay, thang, nam;
};
struct VoChong
{
	string HoTen;
	date Birth;
	int Died;
	string TieuSu;
	date NgayMat;	
};
struct Nguoi
{
	int ID;
	string HoTen;
	date Birth;
	string Sex;
	int HonNhan;
	int Died;
	string TieuSu;
	date NgayMat;
	VoChong Info;
};
struct TreeNode {
Nguoi data;
TreeNode* fChild= NULL;
TreeNode* nSib= NULL;
};

TreeNode* newNode(Nguoi x){
TreeNode* q = new TreeNode();
q->data=x;q->fChild=q->nSib=NULL;
return q;
};

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

void checkName(string &name)
{
	char s[30];
	strcpy(s,name.c_str());
	int len=strlen(s);
	strlwr(s);
	bool start=false;
	int n=0;
	for(int i=0;i<len;i++)
	{
		if( s[i] != ' ' )
		{
			if(start==false)
			{
				start=true;
				if(s[i] >='a' && s[i]<='z')
				s[i]-=32;
				s[n++]=s[i];
			}
			else
				s[n++]=s[i];
		}
		else
		{
			if(start==true)
			{
				s[n++]=s[i];
				start=false;
			}
		}	
	}
	if(s[n-1]==' ')
		s[n-1]=0;
	else
		s[n]=0;
	name = s;
}

VoChong NhapVoChong()
{
	VoChong a;
	cout << "HO VA TEN: ";
	cin.ignore();
	getline(cin,a.HoTen);
	checkName(a.HoTen);
	cout<< "NGAY SINH :";
	cin>>a.Birth.ngay>>a.Birth.thang>>a.Birth.nam;
	while(!checkday(a.Birth.ngay,a.Birth.thang,a.Birth.nam))
	{
		cout<<"NGAY SINH KHONG HOP LE. MOI NHAP LAI: ";
		cin>>a.Birth.ngay>>a.Birth.thang>>a.Birth.nam;
	}
	cout<<"(1-CON SONG\t0-DA MAT:) ";
	cin>>a.Died;
	if(a.Died==0)
	{
		cout<<"NGAY MAT: ";
		cin>>a.NgayMat.ngay>>a.NgayMat.thang>>a.NgayMat.nam;
	}
	return a;
}

Nguoi NhapNguoi()
{
	Nguoi a;
	cout << "ID: ";
	cin>>a.ID;
	cout << "HO VA TEN: ";
	cin.ignore();
	getline(cin,a.HoTen);
	checkName(a.HoTen);
	cout<< "NGAY SINH: ";
	cin>>a.Birth.ngay>>a.Birth.thang>>a.Birth.nam;
	while(!checkday(a.Birth.ngay,a.Birth.thang,a.Birth.nam))
	{
		cout<<"NGAY SINH KHONG HOP LE. MOI NHAP LAI: ";
		cin>>a.Birth.ngay>>a.Birth.thang>>a.Birth.nam;
	}
	int s;
	char sex[]="Nam";
	char sex1[]="Nu";
	while(true){
    cout<<"\nGioi Tinh(0:Nam/1:Nu): ";
    cin>>s;
    if(s==0)
    {
    	a.Sex.replace(0,3,sex);
    	break;
	}
	else if(s==1)
	{
		a.Sex.replace(0,3,sex1);
		break;
	}
	else
	cout<<"\nNHAP SAI!!NHAP LAI!!";  }
	cout<<"TRANG THAI: (1-CON SONG\t0-DA MAT:) ";
	cin>>a.Died;
	if(a.Died==0)
	{
		cout<<"NGAY MAT: ";
		cin>>a.NgayMat.ngay>>a.NgayMat.thang>>a.NgayMat.nam;
	}
	cout << "TIEU SU: ";
	cin.ignore();
	getline(cin,a.TieuSu);
	cout<<"TINH TRANG HON NHAN (1-KET HON\t0-DOC THAN): ";
	cin>>a.HonNhan;
	cout<<endl;
	if(a.HonNhan==1)
	{
		cout<<"NHAP THONG TIN VO/CHONG: "<<endl;
		a.Info=NhapVoChong();
		cout<<"NHAP THONG TIN CUA VO/CHONG HOAN TAT!!"<<endl;
	}
	return a;
}
void find(TreeNode* T, string x,int lc,TreeNode* q){
	if(T==NULL)	return ;
	else{
	TreeNode* a=T->fChild;
	if(T->data.HoTen==x)	
	{
		if(lc==1)
		{
			T->fChild=q;
			return ;
		}
		else if (lc==2)
		{
			T->nSib=q;
			return ;
		}
	}
	while(a!=NULL)
		{
			find(a,x,lc,q);
			a=a->nSib;
		}
	}
}


TreeNode* find(TreeNode *T, string x)
{
		if(T==NULL)
		{
			return NULL;
		}
		TreeNode *p;
		if(T->data.HoTen==x)
		{
			p=T;
			return p;
		}
		TreeNode *q= T->fChild;
		p=NULL;
		while(p==NULL && q!= NULL)
		{
			p= find(q,x);
			q= q->nSib;
		}
		return p;
}
TreeNode* findFather(TreeNode *T, string x)
	{
		if(T==NULL)
		{
			return NULL;
		}
		TreeNode *p;
		if(T->fChild->data.HoTen==x)
		{
			p=T;
			return p;
		}
		TreeNode *q= T->fChild;
		p=NULL;
		while(p==NULL && q!= NULL)
		{
			p= findFather(q,x);
			q= q->nSib;
		}
		return p;
	}

TreeNode* deleteTV(TreeNode *T){
	TreeNode *p, *q;
	cout<<"NHAP TEN CUA NGUOI CAN XOA: ";
			string xoa;
			cin.ignore(1000,'\n');
			getline(cin,xoa);
			p= find(T,xoa);
			if(p->fChild==NULL)
			{
				q= findFather(T,xoa);
				q->fChild=p->nSib;
				delete p;
			}
			else
			{
				cout<<"KHONG THE XOA\n";
			}
}

TreeNode* addChild(TreeNode *p,int lc){
	string Dad;
	cout<< "\nNhap Child can them: ";
	Nguoi Child=NhapNguoi();
	TreeNode* q = newNode(Child);
	cout<< "\nNhap Dad cua Child: ";
	cin.ignore();
	getline(cin,Dad);
	checkName(Dad);
	if(p==NULL)
	{
		p=q;
	}
	else{
	find(p,Dad,lc,q);
}
	return p;
}


TreeNode* addSib(TreeNode *p, int lc){
	string Bro;
	cout<< "\nNhap Sib can them: ";
	Nguoi Sib=NhapNguoi();
	TreeNode* q = newNode(Sib);
	cout<< "\nNhap Bro cua Sib: ";
	cin.ignore();
	getline(cin,Bro);
	checkName(Bro);

if (p==NULL)
p=q;
else{
find(p,Bro,lc,q);
}
return p;
}

void preOrder(TreeNode *p){
if (p!=NULL){
	TreeNode *q=p->fChild;
	cout << p->data.HoTen <<'-';
	preOrder(q);
	if (q!=NULL)
	{
		q=q->nSib;
		while (q!= NULL){
		preOrder(q);
		q=q->nSib;
	}	
	}
}

}
void inOrder(TreeNode *p){
if (p!=NULL){
TreeNode *q=p->fChild;
inOrder(q);
cout << p->data.HoTen <<'-';
if (q!=NULL)
{
q=q->nSib;
while (q!= NULL){
inOrder(q);
q=q->nSib;
}
}
}
}

void postOrder(TreeNode *p){
if (p!=NULL){
TreeNode *q=p->fChild;
postOrder(q);
if (q!=NULL)
{
q=q->nSib;
while (q!= NULL){
postOrder(q);
q=q->nSib;
}
}
cout << p->data.HoTen <<'-';
}
}

void xuatdate(date d)
{
	cout<<setw(2)<< d.ngay << "/" <<setw(2)<< d.thang << "/" <<setw(4)<<left<< d.nam ;
}

void xuatVC(VoChong x)
{
	cout << setw(25) << left << x.HoTen << " (";
	xuatdate(x.Birth);
	cout<<"-";
	if(x.Died==0)
	{
		xuatdate(x.NgayMat);
	}
	else
	{
		cout<<"__/__/____";
	}
	cout<<")|\n";
	cout<<"|TIEU SU: " << setw(50) << left << x.TieuSu << "|"<<endl;
	
}
void XuatThongTin(Nguoi a)
{
	cout<<"=============================================================\n";
	cout<<"||ID: "<< setw(53)<<left<<a.ID<<"||\n";
	cout<<"||"<< setw(33) << left << a.HoTen << " (";
	xuatdate(a.Birth);
	cout<<"-";
	if(a.Died==0)
	{
		xuatdate(a.NgayMat);
	}
	else
	{
		cout<<"__/__/____";
	}
	cout<<")||"<<endl;
	cout<<"||GIOI TINH: " << setw(46) << left << a.Sex <<"||"<<endl;
	cout<<"||TIEU SU: " << setw(48) << left << a.TieuSu << "||"<<endl;
	if(a.HonNhan==1)
	{
		cout<<"|Vo/Chong: ";
		xuatVC(a.Info);
	}
	else
	{
		cout<<"||"<<setw(57)<<left<<"CHUA KET HON "<<"||\n";
	}
		cout<<"=============================================================\n";
}

void XuatDS(TreeNode* p) 
{
	if (p != NULL) 
	{
		TreeNode* q = p->fChild;
		XuatThongTin(p->data);
		XuatDS(q);
		if (q != NULL)
		{
			q = q->nSib;
			while (q != NULL)
			{
				XuatDS(q);
				q = q->nSib;
			}
		}
	}
}

int main()
{
	
Nguoi x;
cout<< "Nhap thong tin chu ho: "<<endl;
x= NhapNguoi();
TreeNode *A=newNode(x);
TreeNode *T= A;
int lc;
TreeNode *p;

do
{
	cout<< "\n 0. Thoat chuong trinh ";
	cout<< "\n 1. Them thanh vien Child";
	cout<< "\n 2. Them thanh vien Sibling";
	cout<< "\n 3. Xoa thanh vien(Xoa thanh vien khong co con)";
	cout<< "\n 4. Duyet cay";
	cout<< "\n 5. Xuat thong tin gia pha";
	cout<< "\n Nhap lua chon: ";
	cin>>lc;
	if(lc==0)	break;
	else if(lc==1)
	{	system("cls");
		p=addChild(T,lc);
	}	
	else if(lc==2)
	{	system("cls");
		p=addSib(T,lc);
	}
	else if(lc==3)
	{	system("cls");
		p=deleteTV(T);
	}
	else if(lc==4)
	{	system("cls");
		cout << "\n=========PREORDER=========="<<endl;
		preOrder(T);
		cout << "\n=========INORDER=========="<<endl;
		inOrder(T);
		cout << "\n=========POSTORDER=========="<<endl;
		postOrder(T);
	}
	else if(lc==5)
	{	system("cls");
		XuatDS(T);
	}
}while(true);

return 0;
}

