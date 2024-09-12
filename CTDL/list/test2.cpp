#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct SinhVien {
    char MaSV[30];
    char HoTen[30];
    int NamSinh;
    char Lop[30];
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
 
void NhapTT(SinhVien &sv) {
    fflush(stdin);
    cout << "Ma SV: ";
    cin.getline(sv.MaSV, 30);
    cout << "Ho ten: ";
    cin.getline(sv.HoTen, 30);
    cout << "Nam sinh: ";
    cin >> sv.NamSinh;
    fflush(stdin);
    cout << "Lop: ";
    cin.getline(sv.Lop, 30);
    cout << "DTB: ";
    cin >> sv.DTB;
}
 
void XuatTT(SinhVien sv) {
    cout << "Ma SV: " << sv.MaSV << endl;
    cout << "Ho ten:" << sv.HoTen << endl;
    cout << "Nam sinh: " << sv.NamSinh << endl;
    cout << "Lop: " << sv.Lop << endl;
    cout << "DTB: " << sv.DTB << endl;
}
 
//1. Khoi tao
 
void InIt(Queue &Q) {
    Q.Front = Q.Rear = NULL;
}
 
//2. Kiem tra rong
bool IsEmpty(Queue Q) {
    if (Q.Rear == NULL) return true;
    else return false;
}
 
//3. Tao Node
Node*AddNode(Node* P, SinhVien x) {
    P = (Node*)malloc(sizeof(Node));
    P->Data = x;
    P->Next = NULL;
    return P;
}
 
//4.Dem so luong
int DemSoLuong(Queue Q) {
    int dem = 0;
    for (Node* M = Q.Front; M != NULL; M = M->Next) {
        dem++;
    }
    return dem;
}
 
void EnQueue(Queue &Q, SinhVien x) {
    Node* P = AddNode(P, x);
    if (IsEmpty(Q)) Q.Front = Q.Rear = P;
    else {
        Q.Rear->Next = P;
        Q.Rear = P;
    }
}
 
void DeQueue(Queue &Q) {
    Q.Front = Q.Front->Next;
}
 
void InPut(Queue &Q, int n) {
    SinhVien x;
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien " << i + 1 << endl;
        NhapTT(x);
        EnQueue(Q, x);
        cout << "-------------------------------------" << endl;
    }
}
 
void OutPut(Queue Q) {
    for (Node* M = Q.Front; M != NULL; M = M->Next) {
        XuatTT(M->Data);
        cout << "---------------------------------------" << endl;
    }
}
void AddAny(Queue& Q, Queue& Q2, int k, SinhVien x) {
    InIt(Q2);
    SinhVien sv;
    int a = DemSoLuong(Q) - (k - 1);
    for (int i = 0; i < k - 1; i++) {
        sv = Q.Front->Data;
        DeQueue(Q);
        EnQueue(Q2, sv);
    }
    EnQueue(Q2, x);
 
    for (int i = 0; i < a; i++) {
        sv = Q.Front->Data;
        DeQueue(Q);
        EnQueue(Q2, sv);
    }
    Q = Q2;
 
}
 
void DeleteAny(Queue& Q, Queue& Q2, int k) {
    InIt(Q2);
    SinhVien sv;
    int a = (DemSoLuong(Q) - (k - 1)) - 1;
    for (int i = 0; i < k - 1; i++) {
        sv = Q.Front->Data;
        DeQueue(Q);
        EnQueue(Q2, sv);
    }
    DeQueue(Q);
    for (int i = 0; i < a; i++) {
        sv = Q.Front->Data;
        DeQueue(Q);
        EnQueue(Q2, sv);
    }
    Q = Q2;
}
int main() {
    SinhVien sv;
    Queue Q, Q2;
    InIt(Q);
    int n, chon;
    cout << "Nhap so luong: ";
    cin >> n;
    InPut(Q, n);
    do
    {
        cout << "1. Them sinh vien. " << endl;
        cout << "2. Xuat sinh vien." << endl;
        cout << "3. Xoa sinh vien. " << endl;
        cout << "4. Them bat ky." << endl;
        cout << "5. Xoa bat ky. " << endl;
        cin >> chon;
        switch (chon) {
        case 1:
        {
 
            NhapTT(sv);
            EnQueue(Q, sv);
            break;
        }
        case 2:
        {
            OutPut(Q);
            system("pause");
            break;
        }
        case 3:
        {
            DeQueue(Q);
            break;
        }
        case 4:
        {
            int k;
            cout << "vi tri them: ";
            cin >> k;
            if (k < 1 || k >DemSoLuong(Q)) cout << "vi tri khong hop le. ";
            else {
                NhapTT(sv);
                AddAny(Q, Q2, k, sv);
 
            }
            system("pause");
            break;
        }
        case 5:
        {
            int k;
            cout << "vi tri xoa: ";
            cin >> k;
            if (k < 1 || k >DemSoLuong(Q)) cout << "vi tri khong hop le. ";
            else {
 
                DeleteAny(Q, Q2, k);
 
            }
            system("pause");
            break;
        }
        case 6 :
        	{
        		OutPut(Q);
			}
        }
    } while (chon != 0);
    return 0;
}
