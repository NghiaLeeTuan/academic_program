#include<bits/stdc++.h>
#include<iostream>

using namespace std;
struct SinhVien {
    string HoTen;
    int ngay;
    int thang;
    int nam;
    string Place;
    float DTB;
};
 
struct Node {
    SinhVien Data;
    Node* Next;
};
 
struct Queue {
    Node* Front;
    Node* Rear;
};

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
 
SinhVien NhapTT() {
	SinhVien sv;
	fflush(stdin);
    cout << "Ho va ten: ";
    getline(cin, sv.HoTen);
    int c=sv.HoTen.length();
	if(sv.HoTen[0]>='a' && sv.HoTen[0]<='z')
	{
		sv.HoTen[0]-=32;
	}
	for(int i=0;i<c;i++)
	{
		if(sv.HoTen[i]==' ')
			{
				if(sv.HoTen[i+1]>='a' && sv.HoTen[i+1]<='z')
				sv.HoTen[i+1]-=32;}
	}
	while(true){
    cout << "Ngay sinh (dd mm yyyy): ";
    cin >> sv.ngay >> sv.thang >> sv.nam;
    if (checkday(sv.ngay, sv.thang, sv.nam))
		{
			break;
		}
		else
		{
			cout << "Nhap sai, Vui long nhap lai!!\n"; 
		}
	}
    cout << "Noi sinh: ";
    fflush(stdin);
    getline(cin,sv.Place);
    cout << "GPA: ";
    cin >> sv.DTB;
    return sv;
}

//khoi tao Queue
void InIt(Queue &Q) {
    Q.Front = Q.Rear = NULL;
}
 
//kiem tra rong
bool IsEmpty(Queue Q) {
    if (Q.Rear == NULL) return true;
    else return false;
}
 
//tao Node
Node*CreateNode(SinhVien x) {
    Node *pNode=new Node;
    if(pNode!=NULL)
    {
        pNode->Data=x;
        pNode->Next=NULL;
    }
    else
    {
        cout<<"cap phat bo nho that bai!!!";
    }
    return pNode;
}

 
void XuatTT(SinhVien sv) {
    cout << "|"<< setw(29)<<left <<sv.HoTen;
    cout << "|"<<setw(2)<<left << sv.ngay<<"/"<<setw(2)<<sv.thang<<"/"<<setw(5)<<left<<sv.nam ;
    cout << "|"<<setw(19)<<left<<sv.Place ;
    cout << "|"<<setw(9)<<left<<sv.DTB <<"|"<<endl;
}
 
void OutPut(Queue Q) {
	if(IsEmpty(Q)) cout<<"\n Danh sach rong!!!\n";

	else{
	int i=1;
	cout<<"______________________________________________________________________________"<<endl;
	cout<< setw(5)<< left<<"|STT"<<setw(30)<< left<<"|Ho va Ten"<<setw(12)<<left<<"|Ngay sinh"<<setw(20)<<left<<"|Noi sinh"<<setw(10)<<left<<"|Diem GPA"<<"|"<<"\n";
    for (Node* M = Q.Front; M != NULL; M = M->Next) {
    	cout<<"|"<<setw(4)<<left<<i;
    	i++;
        XuatTT(M->Data);}
	cout << "______________________________________________________________________________" << endl;}
}

//them Cuoi
void EnQueue(Queue &Q, SinhVien x) {
    Node* P = CreateNode(x);
    if (IsEmpty(Q)) Q.Front = Q.Rear = P;
    else {
        Q.Rear->Next = P;
        Q.Rear = P;
    }
}

//xoa dau
void DeQueue(Queue &Q) {
	if(IsEmpty(Q)) cout<<"Danh sach trong!!"<<endl;
	else{	
 	 Q.Front = Q.Front->Next;
 	 cout<<"Da xoa sinh vien dau danh sach!!"<<endl;
 	 }
}

//TTSV dau ds
void First(Queue Q){
	Node* Temp;
	if(!IsEmpty(Q)){
		Temp= Q.Front;
		cout<<"_________________________________________________________________________"<<endl;
	cout<<setw(30)<< left<<"|Ho va Ten"<<setw(12)<<left<<"|Ngay sinh"<<setw(20)<<left<<"|Noi sinh"<<setw(10)<<left<<"|Diem GPA"<<"|"<<"\n";
		XuatTT(Temp->Data);
	}
	else{
		cout<<"Danh sach trong!!";
	}
}
 
void InPut(Queue &Q, int n) {

    for (int i = 0; i < n; i++) {
        cout << "Sinh vien " << i + 1 << endl;
        SinhVien x=NhapTT();
        EnQueue(Q, x);
        cout << "-------------------------------------" << endl;
    }
}
 
//doc file
SinhVien doc(Queue &Q,ifstream& file)
{		string c;
		SinhVien a;
		getline(file,a.HoTen,';');
		file>>a.ngay;
		file>>a.thang;
		file>>a.nam;
		getline(file,c,';');
		getline(file,a.Place,';');
		file>>a.DTB;
		getline(file,c,'\n');
		return a;

}

void docfile(Queue &Q,ifstream& file)
{
	int n=0;
	while(file.eof()==false){
		SinhVien a=doc(Q,file);
		EnQueue(Q, a);
		n++;
	}
	if(n!=0){
	cout<< "So luong sv co trong file: "<< n << endl; }
	else{
	cout<<"File trong!! Khong co sv trong file!!";}
	cout<< "\nDoc file thanh cong!!\n";
}


int main() {
    SinhVien sv;
    Queue Q;
    InIt(Q);
    int n, chon;

    do
    {	cout << "_________________MENU_________________" << endl;
        cout << "|         1. Them sinh vien          |" << endl;
        cout << "|    2. Xuat sinh vien trong Queue   |" << endl;
        cout << "|          3. Xoa sinh vien          |" << endl;
        cout << "|          4. Kiem tra rong          |" << endl;
        cout << "|     5. Sinh vien dau danh sach     |" << endl;
        cout << "|         6. Doc file Input          |" << endl;
        cout << "|       7. Nhap tay nhieu sv         |" << endl;
        cout << "|             0. Thoat.              |" << endl;
        cout << "+------------------------------------+" << endl;
        cout << "\nNhap lua chon: ";
        cin >> chon;
        switch (chon) {
        case 1:
        {   system("cls");
 			SinhVien x=NhapTT();
            EnQueue(Q, x);
            break;
        }
        case 2:
        {        system("cls");
            OutPut(Q);
            break;
        }
        case 3:
        {        system("cls");
            DeQueue(Q);
            break;
        }
		case 4:
		{
			system("cls");
			if(IsEmpty(Q))
				cout<<"\nDanh sach trong!!\n";
			else
				cout<<"\nDanh sach khong trong!!\n";
			break;
		}
		case 5:
		{
			system("cls");
			First(Q);
			break;
		}
		case 6:
		{		system("cls");
		    std::ifstream file;
			file.open("Input.txt", ios_base::in);
			if(file.fail()==true)
			{	
				cout<<"\nFile khong ton tai hoac sai duong dan!!\n";
			}
			else{
				docfile(Q,file);}
			file.close();
			break;
		}
		case 7:
		{		system("cls");
			cout << "Nhap so luong: ";
			cin >> n;
			InPut(Q, n);
			break;
		}	
		case 0:
		{		system("cls");
			cout<< "\nDa dung chuong trinh!!\n";
			break;
		}
        default: cout << "\nKhong co lua chon!!\n";}
    } while (chon != 0);
    return 0;
}
