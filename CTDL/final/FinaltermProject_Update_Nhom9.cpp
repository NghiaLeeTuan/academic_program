#include <string.h>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;

//tao cau truc Thông Tin
struct Date
{
	int ngay;
	int thang;
	int nam;
};

struct Point
{
	float dToan;
	float dVan;
	float dAv;
	string tohop;
	float dLy;
	float dHoa;
	float dSinh;
	float dSu;
	float dDia;
	float dGDCD;
	float tb12;
	float tbth;
	float dkk;
	float dut;
	float dxtn;
};

struct Place
{
	string place;	//luu dia diem thi
	int place1; 	//luu khu vuc thi (1-30)
};

struct ThongTin
{
	//thong tin
	int MSHS;
	string Ho;
	string Ten;
	string Sex;
	Date Birth;
	//DiemThi
	Point DiemThi;
	//khu vuc va tinh trang
	Place DiaDiem;		//luu khu vuc thi
	string check;	
};

//tao cau truc danh sach lien ket don
struct Node
{
    ThongTin *data;
    Node *pNext;
};
struct SingleList
{
    Node *pHead;
};

//khoi tao danh sach lien ket don
void Initialize(SingleList *&list)
{
    list=new SingleList;
    list->pHead=NULL;
}

//tao node hs
Node *CreateNode(ThongTin *hs)
{
    Node *pNode=new Node;
    if(pNode!=NULL)
    {
        pNode->data=hs;
        pNode->pNext=NULL;
    }
    else
    {
        cout<<"cap phat bo nho that bai!!!";
    }
    return pNode;
}

//ktra ngay
bool laNamNhuan(int Year)
{
	if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
		return true;
	return false;

}
int DayInMonth(int Month, int Year)
{
	int Days;

	switch (Month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: 
		Days = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11: 
		Days = 30;
		break;
	case 2:
		if (laNamNhuan(Year))
			Days = 29;
		else
			Days = 28;
		break;
	}

	return Days;
}
bool checkday(int Day, int Month, int Year)
{

	if (Year < 0)
		return false; 
	if (Month < 1 || Month > 12)
		return false; 
	if (Day < 1 || Day > DayInMonth(Month, Year))
		return false; 

	return true;
}

float checkPoint()
{
	float Diem;
	while(true)
	{
		cout<<"\nNhap diem: ";
		cin>>Diem;
		if(Diem >=0 && Diem<=10)
			return Diem;
		else
			cout<<"Nhap sai!! Vui long nhap lai!!"<<endl;
	}
}

//chuan hoa ten
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

//nhap thong tin hs
ThongTin *NhapThongTin()
{
    ThongTin *hs=new ThongTin;
    do{
    cout<<"\nNhap MSHS(8 so): ";
 	cin>>hs->MSHS;
 	if(hs->MSHS >=100000000 || hs->MSHS <=9999999)
 		cout<<"\nMSHS khong hop le!!";
 	}while(hs->MSHS >=100000000 || hs->MSHS <=9999999);
    cin.ignore();
    cout<<"\nNhap ho va ten lot: ";
    getline(cin,hs->Ho);
	checkName(hs->Ho);
    cout<<"\nNhap ten: ";
    getline(cin,hs->Ten);
    checkName(hs->Ten);
	int s;
	char sex[]="Nam";
	char sex1[]="Nu";
	while(true){
    cout<<"\nNhap gioi tinh(0:Nam/1:Nu): ";
    cin>>s;
    if(s==0)
    {
    	hs->Sex.replace(0,3,sex);
    	break;
	}
	else if(s==1)
	{
		hs->Sex.replace(0,3,sex1);
		break;
	}
	else
	cout<<"\nNhap sai!!Nhap lai!!";  
	}
    while(true){
    cout<<"\nNhap ngay thang nam sinh(dd mm yyyy): ";
	cin>>hs->Birth.ngay>>hs->Birth.thang>>hs->Birth.nam;
		if (checkday(hs->Birth.ngay, hs->Birth.thang, hs->Birth.nam))
		{
			break;
		}
		else
		{
			cout << "Ngay sinh khong hop le!! Vui long nhap lai!!\n"; 
		}
	}
	cout<<"\nDiem Van: ";
	hs->DiemThi.dVan=checkPoint();
	cout<<"\nDiem Toan: ";
	hs->DiemThi.dToan=checkPoint();
	cout<<"\nDiem Anh Van: ";
	hs->DiemThi.dAv=checkPoint();
	//nhap diem to hop
	do{
		cout << "\nNhap To hop mon thi(1:Tu nhien / 2:Xa hoi): ";
		cin>>s;
		if(s==1)
		{
			hs->DiemThi.tohop="Tu nhien";
			cout<<"\nDiem Ly: ";
			hs->DiemThi.dLy=checkPoint();
			cout<<"\nDiem Hoa: ";
			hs->DiemThi.dHoa=checkPoint();
			cout<<"\nDiem Sinh: ";
			hs->DiemThi.dSinh=checkPoint();
			hs->DiemThi.tbth=( hs->DiemThi.dLy + hs->DiemThi.dHoa + hs->DiemThi.dSinh ) / 3;
			hs->DiemThi.dSu=hs->DiemThi.dDia=hs->DiemThi.dGDCD=-1;
			break;
		}
		else if(s==2)
		{
			hs->DiemThi.tohop="Xa hoi";
			cout<<"\nDiem Su: ";
			hs->DiemThi.dSu=checkPoint();
			cout<<"\nDiem Dia: ";
			hs->DiemThi.dDia=checkPoint();
			cout<<"\nDiem GDCD: ";
			hs->DiemThi.dGDCD=checkPoint();
			hs->DiemThi.tbth = ( hs->DiemThi.dSu + hs->DiemThi.dDia + hs->DiemThi.dGDCD ) / 3;
			hs->DiemThi.dLy=hs->DiemThi.dHoa=hs->DiemThi.dSinh=-1;
			break;
		}
		else		cout <<"Nhap sai !!Vui long nhap lai!!";
	}while(true);
	cout<<"\nDiem trung binh 12: ";
	hs->DiemThi.tb12=checkPoint();
	cout<<"\nNhap diem khuyen khich(khong co thi nhap 0): ";
	cin>>hs->DiemThi.dkk;
	cout<<"\nNhap diem uu tien(khong co thi nhap 0): ";
	cin>>hs->DiemThi.dut;
	hs->DiemThi.dxtn=((((hs->DiemThi.dVan+hs->DiemThi.dToan+hs->DiemThi.dAv+hs->DiemThi.tbth+hs->DiemThi.dkk)/4) * 7) + (hs->DiemThi.tb12 * 3)) / 10 + hs->DiemThi.dut;
	if(s==1)
	{
	if(hs->DiemThi.dxtn>=4.995 && hs->DiemThi.dVan >=1.00 && hs->DiemThi.dToan>1.00 && hs->DiemThi.dAv>=1.00 && hs->DiemThi.dLy>=1.00 && hs->DiemThi.dHoa>=1.00 && hs->DiemThi.dSinh>=1.00)
		hs->check.replace(0,20,"Tot Nghiep");
	else
		hs->check.replace(0,20,"Chua Tot Nghiep");}
	else{
		if(hs->DiemThi.dxtn>=4.995 && hs->DiemThi.dVan >=1.00 && hs->DiemThi.dToan>1.00 && hs->DiemThi.dAv>=1.00 && hs->DiemThi.dSu>=1.00 && hs->DiemThi.dDia>=1.00 && hs->DiemThi.dGDCD>=1.00)
		hs->check.replace(0,20,"Tot Nghiep");
	else
		hs->check.replace(0,20,"Chua Tot Nghiep");
	}
	//dia diem thi
	do{
		cout<<"\nDia diem thi so (1-30): ";
		cin>>hs->DiaDiem.place1;
		if(hs->DiaDiem.place1 < 1 || hs->DiaDiem.place1 > 30)
			cout<<"\nKhong co dia diem thi nay!!";
		else 
		{
			ostringstream tmp;
			tmp<<hs->DiaDiem.place1;
			hs->DiaDiem.place="Dia diem thi so " + tmp.str();
			break;
		}	
	}while(true);
    return hs;
}

//xuat
void outputTT(ThongTin *hs,int i)
{

        cout<<"||"<<setw(3)<<left<<i<<"||"<<setw(8)<< left<<hs->MSHS<<"||";
		cout<<setw(14)<<hs->Ho<<setw(10)<<hs->Ten;
		cout<<"||"<<setw(9)<<left<<hs->Sex<<"||"<<setw(2)<<left<<hs->Birth.ngay<<"/"<<setw(2)<<left<<hs->Birth.thang<<"/"<<setw(4)<<left<<hs->Birth.nam<<"||"<<setw(8)<<left<<hs->DiemThi.dVan<<"||"<<setw(10) << left<< hs->DiemThi.dToan<<"||"<<setw(8) << left<<hs->DiemThi.dAv<<"||" << setw(8)<<left<<hs->DiemThi.tohop<<"||"<<setw(11) << left<<hs->DiemThi.tbth<<"||"<<setw(8)<<left<<hs->DiemThi.tb12<<"||"<<setw(8)<<left<<hs->DiemThi.dkk<<"||"<<setw(8)<<left<<hs->DiemThi.dut<<"||"<<setw(11)<<left<<hs->DiemThi.dxtn<<"||"<<setw(18)<<left<<hs->DiaDiem.place<<"||"<<setw(15)<<left<<hs->check<<"||"<<"\n";

}

//xuat2
void outputhead()
{
	cout<<"=========================================================================================================================================================================================================\n";
	cout<<"||                                                                        BANG QUAN LY TOT NGHIEP TRUNG HOC PHO THONG                                                                                  ||\n";
	cout<<"=========================================================================================================================================================================================================\n";
	cout<<setw(5)<< left<<"||STT"<<setw(10)<< left<<"||  MSHS"<<setw(16)<<left<<"||Ho va"<<setw(10)<<left<<"Ten"<<setw(11)<<left<<"||Gioi tinh"<<setw(12)<<left<<"||Ngay sinh"<<setw(10)<<left<<"||Diem Van"<<setw(12) << left<< "||Diem Toan"<<setw(10) << left<<"||Diem AV"<<setw(10)<<left<<"|| To Hop" <<setw(13) << left<<"||Diem To Hop"<<setw(10)<<left<<"||  Tb 12"<<setw(10)<<left<<"||Diem KK"<<setw(10)<<left<<"||Diem UT"<<setw(13)<<left<<"||Diem Xet TN"<<setw(20)<<left<<"||      Noi Thi"<<setw(17)<<left<<"||   Tinh Trang"<<"||"<<"\n";
	cout<<"=========================================================================================================================================================================================================\n";
}

//in list
void PrintList(SingleList *list)
{	
	int i=1;
	outputhead();
	Node *pTmp=list->pHead;
    if(pTmp==NULL)
    {
        cout<<"Danh sach rong";
        return;
    }
    while(pTmp!=NULL)
    {
        ThongTin *hs=pTmp->data;
		outputTT(hs,i);
        pTmp=pTmp->pNext;
        i++;
    }
	cout<<"=========================================================================================================================================================================================================\n";
}

//them vao cuoi danh sach
void InsertLast(SingleList *&list,ThongTin *hs)
{
    Node *pNode=CreateNode(hs);
    if(list->pHead==NULL)
    {
        list->pHead=pNode;
    }
    else
    {
        Node *pTmp=list->pHead;
         
        while(pTmp->pNext!=NULL)
        {
            pTmp=pTmp->pNext;
        }
        pTmp->pNext=pNode;
    }
    cout<<"Them hoc sinh thanh cong !!"<<endl;
}

//them node vao dau danh sach
void InsertFirst(SingleList *&list,ThongTin *hs)
{
	Node *pNode=CreateNode(hs);
	pNode->pNext=list->pHead;
	list->pHead=pNode;
	cout<<"Them hoc sinh thanh cong !!"<<endl;
}

//them vao vi tri bat kì
void InsertAt(SingleList *&list, ThongTin *hs){
	Node *pNode=CreateNode(hs);
	int n;
	cout<<"\nNhap vi tri can them: ";
	cin>>n;	
	n--;
    if(n == 0 || list->pHead == NULL){
     	pNode->pNext=list->pHead;
		list->pHead=pNode; 
    }else{
        int k = 1;
        Node *p = list->pHead;
        while(p != NULL && k != n){
            p = p->pNext;
            ++k;}
 
        if(k != n){
            if(list->pHead==NULL)
   				{list->pHead=pNode;}
    		else
    			{Node *pTmp=list->pHead;
        			while(pTmp->pNext!=NULL)
        			{pTmp=pTmp->pNext;}
        				pTmp->pNext=pNode;
    			}
        }else{
            Node *temp = CreateNode(hs);
            temp->pNext = p->pNext;
            p->pNext = temp;
        }
    }
    cout<<"Them hoc sinh thanh cong!!"<<endl;
}

//xoa dau
void deleteHead(SingleList *&list){
	Node *pDel=list->pHead;
    if(pDel==NULL)
    {
        cout<<"Danh sach rong!";
        return;
    }
    list->pHead=list->pHead->pNext;
    pDel->pNext=NULL;
    delete pDel;
    pDel=NULL;
    cout<<"Da xoa hoc sinh ra khoi danh sach!!"<<"\n";
}

//xoa vi tri cuoi
void deleteTail(SingleList *&list){
   Node *pDel=list->pHead;
    if(pDel==NULL)
    {
        cout<<"Danh sach rong!\n";
        return;
    }
	while(pDel->pNext->pNext != NULL){
		pDel=pDel->pNext;
	}
	delete(pDel->pNext);
	pDel->pNext=NULL;
	cout<<"Da xoa hoc sinh ra khoi danh sach!!"<<"\n";
}

//xoa tai vi tri bat ki
void deleteAt(SingleList *&list){
	int k;
	cout<<"Xoa vi tri thu: ";
	cin>>k;
	Node *pDel = list->pHead;
	if(k<1)
	{
		cout<<"Vi tri sai!!"<<endl;
		return;
	}
	else if(k==1)
	{
		deleteHead(list);
		return;
	}
	else{
		if(pDel==NULL)
	    {
	        cout<<"Danh sach rong!\n";
	        return;
	    }
		for (int i = 0; i < k-2; i++){
			pDel = pDel->pNext;
			if(pDel==NULL)
			{	cout<<"Khong co vi tri trong danh sach!!"<<endl;
				return;}
		}
		Node *temp = pDel->pNext;
		pDel->pNext = pDel->pNext->pNext;
		delete(temp);
		cout<<"Da xoa hoc sinh ra khoi danh sach!!"<<"\n";
	}
}

//xoa mshs
void RemoveMSHS(SingleList *&list){
    cout<<"\nBan muon xoa hoc sinh co MSHS la: ";
    int mshs;
    cin>>mshs;
    Node *pDel=list->pHead;
    if(pDel==NULL)
    {
        cout<<"Danh sach rong!"<<"\n";
        return ;
    }
    else
    {
        Node *pPre=NULL;
        while(pDel!=NULL)
        {
            ThongTin *hs=pDel->data;
            if(hs->MSHS==mshs)
                break;
            pPre=pDel;
            pDel=pDel->pNext;
        }
        if(pDel==NULL)
        {
            cout<<"khong tim thay MSHS: "<<mshs<<"\n";
        }
        else
        {
            if(pDel==list->pHead)
            {
                deleteHead(list);
            }
            else
            {
                pPre->pNext=pDel->pNext;
                delete pDel;
                cout<<"Da xoa hoc sinh ra khoi danh sach!!"<<"\n";
            }
        }
    }
}
	
//tim hs theo MSHS
void FindMSHS(SingleList *list)
{
	Node* p;
	int k;
	do{
    cout<<"\nNhap MSHS can tim(8 so): ";
 	cin>>k;
 	if(k >=100000000 ||k <=9999999)
 		cout<<"\nMSHS khong hop le!!";
 	}while(k >=100000000 || k <=9999999);
	int dem=1;	
	p= list->pHead;
	while(p!=NULL)
	{
		if(p->data->MSHS==k)
		{
			outputTT(p->data,dem);
			dem++;
		}
		p=p->pNext;
	}
	if(dem==1)
	{
		cout<<"Khong co hoc sinh can tim!!"<<endl;
	}
}
//check ten
bool SoSanh(string s1, string s2)
{

	for (unsigned int i = 0; i < s1.size(); i++){
		if(s1[i] >= 'a' && s1[i] <= 'z'){
			s1[i] -= 32;}
	}

	for (unsigned int i = 0; i < s2.size(); i++){
		if(s2[i] >= 'a' && s2[i] <= 'z'){
			s2[i] -= 32;}
	}

	if (s1.compare(s2) == 0)
		return true;
	return false;
}

//tim hs theo ten
void FindName(SingleList *list)
{
	Node* p;
	string k;
	cout<<"Nhap ten hoc sinh can tim: ";
	cin>>k;
	checkName(k);
	int dem=1;
	p= list->pHead;
	outputhead();
	while(p!=NULL)
	{
		if(SoSanh(p->data->Ten,k))
		{
			outputTT(p->data,dem);
			dem++;
		}
		p=p->pNext;
	}
	if(dem==1)
	{
		cout<<"Khong co hoc sinh can tim!!"<<endl;
	}
}

//hoan doi thong tin
void swapinfo(Node* hsTmp2, Node* hsTmp)
{
	Node* Temp= CreateNode(hsTmp2->data);
	hsTmp2->data=hsTmp->data;
	hsTmp->data=Temp->data;
}

//sap xep theo MSHS
void SortMSHS(SingleList *&list)
{
    for(Node *pTmp=list->pHead;pTmp!=NULL;pTmp=pTmp->pNext)
    {
        for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext)
        {   
            if(pTmp2->data->MSHS<pTmp->data->MSHS)
            {
                swapinfo(pTmp2,pTmp);
            }
        }   
    }
    cout<<"Danh sach da duoc sap xep!!"<<endl;
}

//sap xep theo Diem tot nghiep
void SortGPA1(SingleList *&list)
{
    for(Node *pTmp=list->pHead;pTmp!=NULL;pTmp=pTmp->pNext)
    {
        for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext)
        {   
            if(pTmp2->data->DiemThi.dxtn<pTmp->data->DiemThi.dxtn)
           {
                swapinfo(pTmp2,pTmp);
            }
        }   
    }
    cout<<"Danh sach da duoc sap xep!!"<<endl;
}

void SortGPA2(SingleList *&list)
{
    for(Node *pTmp=list->pHead;pTmp!=NULL;pTmp=pTmp->pNext)
    {
        for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext)
       {   
            if(pTmp2->data->DiemThi.dxtn>pTmp->data->DiemThi.dxtn)
            {
				swapinfo(pTmp2,pTmp);
            }
        }   
    }
    cout<<"Danh sach da duoc sap xep!!"<<endl;
}

//sap xep theo ten
void SortName(SingleList *&list)
{
    for(Node *pTmp=list->pHead;pTmp!=NULL;pTmp=pTmp->pNext)
    {
        for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext)
        {   
            if(strcmp(pTmp2->data->Ten.c_str(),pTmp->data->Ten.c_str())<0)
            {
                swapinfo(pTmp2,pTmp);
            }
        }   
    }
    cout<<"Danh sach da duoc sap xep!!"<<endl;
}

//chinh sua thong tin hoc sinh
void EditInfor(SingleList *&list)
{
	Node* p;
	int k,edit=-1;
	do{
    cout<<"\nNhap MSHS can tim(8 so): ";
 	cin>>k;
 	if(k >=100000000 ||k <=9999999)
 		cout<<"\nMSHS khong hop le!!";
 	}while(k >=100000000 || k <=9999999);
	int dem=1;	
	p= list->pHead;
	while(p!=NULL)
	{
		if(p->data->MSHS==k)
		{
		ThongTin *hs=p->data;
		cout<<"\nMa so hoc sinh: "<<hs->MSHS<<endl;
		cout<<"Ho va ten: "<<hs->Ho<<" "<<hs->Ten<<endl;
		cout<<"Ngay sinh: "<<hs->Birth.ngay<<"/"<<hs->Birth.thang<<"/"<<hs->Birth.nam<<endl;
		cout<<"Diem Van: "<<hs->DiemThi.dVan<<endl;
		cout<<"Diem Toan: "<<hs->DiemThi.dToan<<endl;
		cout<<"Diem Anh Van: "<<hs->DiemThi.dAv<<endl;
		cout<<"Diem Su: "<<hs->DiemThi.dSu<<endl;
		cout<<"Diem Dia: "<<hs->DiemThi.dDia<<endl;
		cout<<"Diem GDCD: "<<hs->DiemThi.dGDCD<<endl;
		cout<<"Diem Ly: "<<hs->DiemThi.dLy<<endl;
		cout<<"Diem Hoa: "<<hs->DiemThi.dHoa<<endl;
		cout<<"Diem Sinh: "<<hs->DiemThi.dSinh<<endl;
		cout<<"Diem trung binh 12: "<<hs->DiemThi.tb12<<endl;
		cout<<"Diem uu tien: "<<hs->DiemThi.dut<<endl;
		cout<<"Diem khuyen khich: "<<hs->DiemThi.dkk<<endl;
		cout<<"Khu vuc thi so: "<<hs->DiaDiem.place1<<endl;
		while(edit!=0 && edit!=1){
			cout<<"\nBan co muon tiep tuc chinh sua ? (0:Co\t 1:Khong): ";
			cin>>edit;
		}
		if(edit==1)
			return;
		else{
			p->data=NhapThongTin();
			cout<<"\nCap nhat thong tin thanh cong!!"<<endl;
		}	
		dem++;
		}
		p=p->pNext;
	}
	if(dem==1)
	{
		cout<<"Khong co sinh vien can tim!!"<<endl;
		return;
	}
}

//in danh sach hoc sinh tn/chua tn
void TN(SingleList *list){
	string TN="Tot Nghiep";
	Node* p;
	int dem=1;
	p= list->pHead;
	outputhead();
	while(p!=NULL)
	{
		if(SoSanh(p->data->check,TN))
		{
			outputTT(p->data,dem);
			dem++;
		}
		p=p->pNext;
	}
	if(dem==1)
	{
		cout<<"Khong co hoc sinh tot nghiep!!";
	}
	
}

void CTN(SingleList *list){
	string CTN="Chua Tot Nghiep";
	Node* p;
	int dem=1;
	p= list->pHead;
	outputhead();
	while(p!=NULL)
	{
		if(SoSanh(p->data->check,CTN))
		{
			outputTT(p->data,dem);
			dem++;
		}
		p=p->pNext;
	}
	if(dem==1)
	{
		cout<<"Khong co hoc sinh chua tot nghiep!!";
	}	
}

//in danh sach hoc sach theo ban
void TuNhien(SingleList *list){
	string Tn="Tu nhien";
	Node* p;
	int i=1;
	p= list->pHead;
	cout<<"===========================================================================================================================================================================================\n";
	cout<<"||                                                                 BANG QUAN LY TOT NGHIEP TRUNG HOC PHO THONG                                                                           ||\n";
	cout<<"===========================================================================================================================================================================================\n";
	cout<<setw(5)<< left<<"||STT"<<setw(10)<< left<<"||  MSHS"<<setw(16)<<left<<"||Ho va"<<setw(10)<<left<<"Ten"<<setw(11)<<left<<"||Gioi tinh"<<setw(12)<<left<<"||Ngay sinh"<<setw(10)<<left<<"||Diem Van"<<setw(12) << left<< "||Diem Toan"<<setw(10) << left<<"||Diem AV"<<setw(10)<<left<<"||Diem Ly"<<setw(11)<<left<<"||Diem Hoa"<<setw(12)<<left<<"||Diem Sinh" <<setw(13) << left<<"||Diem To Hop"<<setw(10)<<left<<"||  Tb 12"<<setw(10)<<left<<"||Diem KK"<<setw(10)<<left<<"||Diem UT"<<setw(13)<<left<<"||Diem Xet TN"<<"||"<<endl;
	cout<<"===========================================================================================================================================================================================\n";

	while(p!=NULL)
	{
		if(SoSanh(p->data->DiemThi.tohop,Tn))
		{
		ThongTin *hs=p->data;
		cout<<"||"<<setw(3)<<left<<i<<"||"<<setw(8)<< left<<hs->MSHS<<"||";
		cout<<setw(14)<<hs->Ho<<setw(10)<<hs->Ten;
		cout<<"||"<<setw(9)<<left<<hs->Sex<<"||"<<setw(2)<<left<<hs->Birth.ngay<<"/"<<setw(2)<<left<<hs->Birth.thang<<"/"<<setw(4)<<left<<hs->Birth.nam<<"||"<<setw(8)<<left<<hs->DiemThi.dVan<<"||"<<setw(10) << left<< hs->DiemThi.dToan<<"||"<<setw(8) << left<<hs->DiemThi.dAv<<"||" <<setw(8)<<left<<hs->DiemThi.dLy<<"||"<<setw(9)<<left<<hs->DiemThi.dHoa<<"||"<<setw(10)<<left<<hs->DiemThi.dSinh <<"||"<<setw(11) << left<<hs->DiemThi.tbth<<"||"<<setw(8)<<left<<hs->DiemThi.tb12<<"||"<<setw(8)<<left<<hs->DiemThi.dkk<<"||"<<setw(8)<<left<<hs->DiemThi.dut<<"||"<<setw(11)<<left<<hs->DiemThi.dxtn<<"||"<<endl;
			i++;
		}
		p=p->pNext;
	}
	if(i==1)
	{
		cout<<"Khong co hoc sinh thi ban Tu Nhien!!"<<endl;
	}
}

void XaHoi(SingleList *list){
	string Xh="Xa hoi";
	Node* p;
	int i=1;
	p= list->pHead;
	cout<<"===========================================================================================================================================================================================\n";
	cout<<"||                                                                 BANG QUAN LY TOT NGHIEP TRUNG HOC PHO THONG                                                                           ||\n";
	cout<<"===========================================================================================================================================================================================\n";
	cout<<setw(5)<< left<<"||STT"<<setw(10)<< left<<"||  MSHS"<<setw(16)<<left<<"||Ho va"<<setw(10)<<left<<"Ten"<<setw(11)<<left<<"||Gioi tinh"<<setw(12)<<left<<"||Ngay sinh"<<setw(10)<<left<<"||Diem Van"<<setw(12) << left<< "||Diem Toan"<<setw(10) << left<<"||Diem AV"<<setw(10)<<left<<"||Diem Su"<<setw(11)<<left<<"||Diem Dia"<<setw(12)<<left<<"||Diem GDCD" <<setw(13) << left<<"||Diem To Hop"<<setw(10)<<left<<"||  Tb 12"<<setw(10)<<left<<"||Diem KK"<<setw(10)<<left<<"||Diem UT"<<setw(13)<<left<<"||Diem Xet TN"<<"||"<<endl;
	cout<<"===========================================================================================================================================================================================\n";

	while(p!=NULL)
	{
		if(SoSanh(p->data->DiemThi.tohop,Xh))
		{
		ThongTin *hs=p->data;
		cout<<"||"<<setw(3)<<left<<i<<"||"<<setw(8)<< left<<hs->MSHS<<"||";
		cout<<setw(14)<<hs->Ho<<setw(10)<<hs->Ten;
		cout<<"||"<<setw(9)<<left<<hs->Sex<<"||"<<setw(2)<<left<<hs->Birth.ngay<<"/"<<setw(2)<<left<<hs->Birth.thang<<"/"<<setw(4)<<left<<hs->Birth.nam<<"||"<<setw(8)<<left<<hs->DiemThi.dVan<<"||"<<setw(10) << left<< hs->DiemThi.dToan<<"||"<<setw(8) << left<<hs->DiemThi.dAv<<"||" <<setw(8)<<left<<hs->DiemThi.dSu<<"||"<<setw(9)<<left<<hs->DiemThi.dDia<<"||"<<setw(10)<<left<<hs->DiemThi.dGDCD <<"||"<<setw(11) << left<<hs->DiemThi.tbth<<"||"<<setw(8)<<left<<hs->DiemThi.tb12<<"||"<<setw(8)<<left<<hs->DiemThi.dkk<<"||"<<setw(8)<<left<<hs->DiemThi.dut<<"||"<<setw(11)<<left<<hs->DiemThi.dxtn<<"||"<<endl;
			i++;
		}
		p=p->pNext;
	}
	if(i==1)
	{
		cout<<"Khong co hoc sinh thi ban Xa hoi!!"<<endl;
	}
}

//in danh sach theo khu vuc
void KhuVuc(SingleList *list){
	Node* p;
	int DiaDiem=0;
	while(DiaDiem<1 || DiaDiem>30)
	{
	cout<<"\nNhap dia diem thi muon tim(1-30): ";
	cin>>DiaDiem;
	}
	int i=1;
	p= list->pHead;
	outputhead();
	while(p!=NULL)
	{
		if(p->data->DiaDiem.place1==DiaDiem)
		{
		ThongTin *hs=p->data;
		outputTT(hs,i);
		i++;
		}
		p=p->pNext;
	}
	if(i==1)
	{
		cout<<"Khong co hoc sinh thi tai dia diem nay!!"<<endl;
	}
}


//menu chính
void Printmenu()
{
	cout<< "\n=======================CHON MENU====================="<<endl;
	cout<< "||"<<setw(49)<<left<<"A. Them 1 hoc sinh"<<"||"<<endl;
	cout<< "||"<<setw(49)<<left<<"B. Them nhieu hoc sinh"<<"||"<<endl;
	cout<< "||"<<setw(49)<<left<<"C. Xoa 1 hoc sinh"<<"||"<<endl;
	cout<< "||"<<setw(49)<<left<<"D. Tim hoc sinh"<<"||"<<endl;
	cout<< "||"<<setw(49)<<left<<"E. In danh sach"<<"||"<<endl;
	cout<< "||"<<setw(49)<<left<<"F. Sap xep danh sach"<<"||"<<endl;
	cout<< "||"<<setw(49)<<left<<"G. Danh sach tot nghiep/chua tot nghiep"<<"||"<<endl;
	cout<< "||"<<setw(49)<<left<<"H. Kiem tra diem thanh phan theo to hop thi"<<"||"<<endl;
	cout<< "||"<<setw(49)<<left<<"I. Danh sach thi theo khu vuc"<<"||"<<endl;
	cout<< "||"<<setw(49)<<left<<"J. Chinh sua thong tin hoc sinh"<<"||"<<endl;
	cout<< "||"<<setw(49)<<left<<"K. Doc file"<<"||"<<endl;
	cout<< "||"<<setw(49)<<left<<"M. Xuat file"<<"||"<<endl;
	cout<< "||"<<setw(49)<<left<<"Q. Thoat"<<"||"<<endl;
	cout<< "====================================================="<<endl;
}

//danh sach cac menu con
void menucheckban()
{
	cout<< "\n=======MENU KIEM TRA DIEM THANH PHAN THEO BAN======="<<endl;
	cout<< "||"<<setw(48)<<left<<"1. Tu nhien"<<"||"<<endl;
	cout<< "||"<<setw(48)<<left<<"2. Xa hoi"<<"||"<<endl;
	cout<< "||"<<setw(48)<<left<<"0. Tro ve menu chinh"<<"||"<<endl;
	cout<< "====================================================\n";
}

void CheckBan(SingleList *list)
{
	int c;
	while(true){
		menucheckban();
		cout<<"Nhap lua chon: ";
		cin>>c;
		if (c==1){			system("cls");
			TuNhien(list);		break;
		}
		else if(c==2){		system("cls");
			XaHoi(list);		break;
		}
		else if(c==0){		system("cls");
			break;
		}
		else{				system("cls");
		cout<<"Khong co lua chon!!\n";}
	}
}

void menuchecktn()
{
	cout<< "\n==========MENU KIEM TRA TOT NGHIEP=========="<<endl;
	cout<< "||"<<setw(40)<<left<<"1. Tot nghiep"<<"||"<<endl;
	cout<< "||"<<setw(40)<<left<<"2. Chua tot nghiep"<<"||"<<endl;
	cout<< "||"<<setw(40)<<left<<"0. Tro ve menu chinh"<<"||"<<endl;
	cout<< "============================================\n";
}

void CheckTN(SingleList *list)
{
	int c;
	while(true){
		menuchecktn();
		cout<<"Nhap lua chon: ";
		cin>>c;
		if (c==1){			system("cls");
			TN(list);		break;
		}
		else if(c==2){		system("cls");
			CTN(list);		break;
		}
		else if(c==0){		system("cls");
			break;
		}
		else{				system("cls");
		cout<<"Khong co lua chon!!\n";}
	}
}

void menusort()
{
	cout<< "\n==========MENU SAP XEP DANH SACH=========="<<endl;
	cout<< "||"<<setw(38)<<left<<"1. Ma so hoc sinh"<<"||"<<endl;
	cout<< "||"<<setw(38)<<left<<"2. Diem xet tot nghiep tang dan"<<"||"<<endl;
	cout<< "||"<<setw(38)<<left<<"3. Diem xet tot nghiep giam dan"<<"||"<<endl;
	cout<< "||"<<setw(38)<<left<<"4. Ten(Alphabet)"<<"||"<<endl;
	cout<< "||"<<setw(38)<<left<<"0. Tro ve menu chinh"<<"||"<<endl;
	cout<< "==========================================\n";
}

void Sort(SingleList *&list)
{
	int c;
	while(true){
		menusort();
		cout<<"Nhap lua chon: ";
		cin>>c;
		if (c==1){			system("cls");
			SortMSHS(list);		break;
		}
		else if(c==2){		system("cls");
			SortGPA1(list);		break;
		}
		else if(c==3){		system("cls");
			SortGPA2(list);		break;
		}
		else if(c==4){		system("cls");
			SortName(list);		break;
		}
		else if(c==0){		system("cls");
			break;
		}
		else{				system("cls");
		cout<<"Khong co lua chon!!\n";}
	}
}

void menuadd()
{
	cout<< "\n============MENU THEM HOC SINH============\n";
	cout<< "||"<<setw(38)<<left<<"1. Them vao dau danh sach"<<"||"<<endl;
	cout<< "||"<<setw(38)<<left<<"2. Them vao cuoi danh sach"<<"||"<<endl;
	cout<< "||"<<setw(38)<<left<<"3. Them vao vi tri thu p cua danh sach"<<"||"<<endl;
	cout<< "||"<<setw(38)<<left<<"0. Tro ve menu chinh"<<"||"<<endl;
	cout<< "==========================================\n";
}

void Add(SingleList *&list,ThongTin *hs)
{
	int c;
	while(true){
		menuadd();
		cout<<"Nhap lua chon: ";
		cin>>c;
		if (c==1){			system("cls");
			InsertFirst(list,hs);	break;
		}
		else if(c==2){		system("cls");
			InsertLast(list,hs);	break;
		}
		else if(c==3){		system("cls");
			InsertAt(list,hs);		break;
		}
		else if(c==0){		system("cls");
			break;
		}
		else{				system("cls");
		cout<<"Khong co lua chon!!\n";}
	}
}

void menufind()
{
	cout<< "\n============MENU TIM HOC SINH============\n";
	cout<< "||"<<setw(37)<<left<<"1. Tim theo ma so hoc sinh"<<"||"<<endl;
	cout<< "||"<<setw(37)<<left<<"2. Theo ten hoc sinh"<<"||"<<endl;
	cout<< "||"<<setw(37)<<left<<"0. Tro ve menu chinh"<<"||"<<endl;
	cout<< "=========================================\n";
}

void Find(SingleList *list)
{
	int c;
	while(true){
		menufind();
		cout<<"Nhap lua chon: ";
		cin>>c;
		if (c==1){			system("cls");
			FindMSHS(list);	break;
		}
		else if(c==2){		system("cls");
			FindName(list);	break;
		}
		else if(c==0){		system("cls");
			break;
		}
		else{				system("cls");
		cout<<"Khong co lua chon!!\n";}
	}
}

void menuremove()
{
	cout<< "\n============MENU XOA HOC SINH============\n";
	cout<< "||"<<setw(37)<<left<<"1. Xoa hoc sinh dau danh sach"<<"||"<<endl;
	cout<< "||"<<setw(37)<<left<<"2. Xoa hoc sinh cuoi danh sach "<<"||"<<endl;
	cout<< "||"<<setw(37)<<left<<"3. Xoa tai vi tri p cua danh sach"<<"||"<<endl;
	cout<< "||"<<setw(37)<<left<<"4. Xoa theo ma so hoc sinh"<<"||"<<endl;
	cout<< "||"<<setw(37)<<left<<"0. Tro ve menu chinh"<<"||"<<endl;
	cout<< "=========================================\n";
}

void Remove(SingleList *&list)
{
		int c;
	while(true){
		menuremove();
		cout<<"Nhap lua chon: ";
		cin>>c;
		if (c==1){			system("cls");
			deleteHead(list);	break;
		}
		else if(c==2){		system("cls");
			deleteTail(list);	break;
		}
		else if(c==3){		system("cls");
			deleteAt(list);		break;
		}
		else if(c==4){		system("cls");
			RemoveMSHS(list); 	break;
		}
		else if(c==0){		system("cls");
								break;
		}
		else{				system("cls");
		cout<<"Khong co lua chon!!\n";}
	}
}


//doc file
ThongTin *doc(ifstream& file,int n)
{
		cout<<"Doc file cua Hoc sinh thu "<<n<<" :"<<endl;
		ThongTin *a=new ThongTin();
		string tmp;
		int check,check1;
		file>>a->MSHS;
 		while(a->MSHS >=100000000 || a->MSHS <=9999999){
 		cout<<"\nNhap MSHS(8 so): ";
 		cin>>a->MSHS;
 		if(a->MSHS >=100000000 || a->MSHS <=9999999)
 		cout<<"\nMSHS khong hop le!!";}
		cout<<"MSHS: "<<a->MSHS<<endl;
		getline(file,tmp,';');
		getline(file,a->Ho,';');
		checkName(a->Ho);
		cout<<"Ho va ten lot: "<<a->Ho<<endl;
		getline(file,a->Ten,';');
		cout<<"Ten: ";
		checkName(a->Ten);
		cout<<a->Ten<<endl;
		file>>check;
		char sex1[]="Nam";
		char sex2[]="Nu";
		if(check==0)
			a->Sex.replace(0,3,sex1);
		else if(check==1)
			a->Sex.replace(0,3,sex2);
		while(check!=0 && check!=1){
    	cout<<"\nNhap gioi tinh(0:Nam/1:Nu): ";
    	cin>>check1;
    	if(check1==0)
    	{
    		a->Sex.replace(0,3,sex1);
    		break;
		}
		else if(check1==1)
		{
			a->Sex.replace(0,3,sex2);
			break;
		}
		else
		cout<<"\nNhap sai!!Nhap lai!!";  
		}			
		cout<<"Gioi tinh: "<<a->Sex<<endl;
		getline(file,tmp,';');
		file>>a->Birth.ngay;
		file>>a->Birth.thang;
		file>>a->Birth.nam;	
		while(checkday(a->Birth.ngay, a->Birth.thang, a->Birth.nam)==false){
    	cout<<"\nNhap ngay thang nam sinh(dd mm yyyy): ";
		cin>>a->Birth.ngay>>a->Birth.thang>>a->Birth.nam;
			if (checkday(a->Birth.ngay, a->Birth.thang, a->Birth.nam))
				break;
			else
				cout << "Ngay sinh khong hop le!! Vui long nhap lai!!\n"; }		
		getline(file,tmp,';');
		file>>a->DiemThi.dVan;
		file>>a->DiemThi.dToan;
		file>>a->DiemThi.dAv;
		getline(file,tmp,';');
		file>>check;
		while(check!=1 && check!=2){
			cout << "\nNhap To hop mon thi(1:Tu nhien / 2:Xa hoi): ";
			cin>>check;
		}
		if(check==1)
		{
			a->DiemThi.tohop="Tu nhien";
			file>>a->DiemThi.dLy;
			file>>a->DiemThi.dHoa;
			file>>a->DiemThi.dSinh;
			a->DiemThi.tbth=( a->DiemThi.dLy + a->DiemThi.dHoa + a->DiemThi.dSinh ) / 3;
			a->DiemThi.dSu=a->DiemThi.dDia=a->DiemThi.dGDCD=-1;
			
		}
		else if(check==2)
		{
			a->DiemThi.tohop="Xa hoi";
			file>>a->DiemThi.dSu;
			file>>a->DiemThi.dDia;
			file>>a->DiemThi.dGDCD;
			a->DiemThi.tbth=( a->DiemThi.dSu+ a->DiemThi.dDia + a->DiemThi.dGDCD ) / 3;
			a->DiemThi.dLy=a->DiemThi.dHoa=a->DiemThi.dSinh=-1;
		}
		file>>a->DiemThi.tb12;
		getline(file,tmp,';');
		file>>a->DiemThi.dkk;
		file>>a->DiemThi.dut;
		a->DiemThi.dxtn=((((a->DiemThi.dVan+a->DiemThi.dToan+a->DiemThi.dAv+a->DiemThi.tbth+a->DiemThi.dkk)/4) * 7) + (a->DiemThi.tb12 * 3)) / 10 + a->DiemThi.dut;
		if(check==1)
		{
			if(a->DiemThi.dxtn>=4.995 && a->DiemThi.dVan >=1.00 && a->DiemThi.dToan>1.00 && a->DiemThi.dAv>=1.00 && a->DiemThi.dLy>=1.00 && a->DiemThi.dHoa>=1.00 && a->DiemThi.dSinh>=1.00)
				a->check.replace(0,20,"Tot Nghiep");
			else
				a->check.replace(0,20,"Chua Tot Nghiep");}
		else if(check==2){
			if(a->DiemThi.dxtn>=4.995 && a->DiemThi.dVan >=1.00 && a->DiemThi.dToan>1.00 && a->DiemThi.dAv>=1.00 && a->DiemThi.dSu>=1.00 && a->DiemThi.dDia>=1.00 && a->DiemThi.dGDCD>=1.00)
					a->check.replace(0,20,"Tot Nghiep");
			else
					a->check.replace(0,20,"Chua Tot Nghiep");}
	//dia diem thi
		file>>a->DiaDiem.place1;
		while(a->DiaDiem.place1<1 || a->DiaDiem.place1>30){
		cout<<"\nDia diem thi so (1-30): ";
		cin>>a->DiaDiem.place1;
		if(a->DiaDiem.place1 < 1 || a->DiaDiem.place1 > 30)
			cout<<"\nKhong co dia diem thi nay!!";}
		ostringstream place;
		place<<a->DiaDiem.place1;
		a->DiaDiem.place="Dia diem thi so " + place.str();
		return a;
}

void docfile(SingleList *&list,ifstream& file)
{
	int n=0;
	while(!file.eof())
	{
		system("cls");
		n++;
		ThongTin *a=doc(file,n);
		InsertLast(list,a);
		system("cls");
	}
	if(n!=0){
	cout<< "So luong hoc sinh co trong file: "<< n << endl; }
	else{
	cout<<"File trong!! Khong co hoc sinh trong file!!";}
	cout<< "\nDoc file thanh cong!!\n";
}

//xuatfile
void xuat(ThongTin *hs,ofstream& fileout){
	string tmp;
	fileout<<hs->MSHS<<";"<<hs->Ho<<";"<<hs->Ten<<";";
	if(SoSanh(hs->Sex,"Nam"))
		fileout<<0<<";";
	else
		fileout<<1<<";";
	fileout<<hs->Birth.ngay<<" "<<hs->Birth.thang<<" "<<hs->Birth.nam<<";"<<hs->DiemThi.dVan<<" "<<hs->DiemThi.dToan<<" "<<hs->DiemThi.dAv<<";";
	if(SoSanh(hs->DiemThi.tohop,"Tu Nhien")){
		fileout<<1<<" ";
		fileout<<hs->DiemThi.dLy<<" "<<hs->DiemThi.dHoa<<" "<<hs->DiemThi.dSinh<<" ";}
	else{
		fileout<<2<<" ";
		fileout<<hs->DiemThi.dSu<<" "<<hs->DiemThi.dDia<<" "<<hs->DiemThi.dGDCD<<" ";}
	fileout<<hs->DiemThi.tb12<<";"<<hs->DiemThi.dkk<<" "<<hs->DiemThi.dut<<" "<<hs->DiaDiem.place1;
}

void xuatfile(SingleList *&list,ofstream& fileout,char filename[])
{
   Node *pTmp=list->pHead;
    if(pTmp==NULL)
    {
        fileout<<"Danh sach rong";
        cout<<"Danh sach rong"<<endl;
        return;
    }
    while(pTmp!=NULL)
    {
        ThongTin *hs=pTmp->data;
        xuat(hs,fileout);
        pTmp=pTmp->pNext;
        if(pTmp!=NULL)
        	fileout<<"\n";     	
    }
    cout<<"\nDa xuat file "<<filename<<" !!!\n";
}

void xuattable(SingleList *&list,ofstream& fileout,char filetable[])
{
	int i=1;
	fileout<<"=========================================================================================================================================================================================================\n";
	fileout<<"||                                                                        BANG QUAN LY TOT NGHIEP TRUNG HOC PHO THONG                                                                                  ||\n";
	fileout<<"=========================================================================================================================================================================================================\n";
	fileout<<setw(5)<< left<<"||STT"<<setw(10)<< left<<"||  MSHS"<<setw(16)<<left<<"||Ho va"<<setw(10)<<left<<"Ten"<<setw(11)<<left<<"||Gioi tinh"<<setw(12)<<left<<"||Ngay sinh"<<setw(10)<<left<<"||Diem Van"<<setw(12) << left<< "||Diem Toan"<<setw(10) << left<<"||Diem AV"<<setw(10)<<left<<"|| To Hop" <<setw(13) << left<<"||Diem To Hop"<<setw(10)<<left<<"||  Tb 12"<<setw(10)<<left<<"||Diem KK"<<setw(10)<<left<<"||Diem UT"<<setw(13)<<left<<"||Diem Xet TN"<<setw(20)<<left<<"||      Noi Thi"<<setw(17)<<left<<"||   Tinh Trang"<<"||"<<"\n";
	fileout<<"=========================================================================================================================================================================================================\n";
    Node *pTmp=list->pHead;
    if(pTmp==NULL)
    {
        fileout<<"Danh sach rong";
        return;
    }
    while(pTmp!=NULL)
    {
        ThongTin *hs=pTmp->data;   
        fileout<<"||"<<setw(3)<<left<<i<<"||"<<setw(8)<< left<<hs->MSHS<<"||";
		fileout<<setw(14)<<hs->Ho<<setw(10)<<hs->Ten;
		fileout<<"||"<<setw(9)<<left<<hs->Sex<<"||"<<setw(2)<<left<<hs->Birth.ngay<<"/"<<setw(2)<<left<<hs->Birth.thang<<"/"<<setw(4)<<left<<hs->Birth.nam<<"||"<<setw(8)<<left<<hs->DiemThi.dVan<<"||"<<setw(10) << left<< hs->DiemThi.dToan<<"||"<<setw(8) << left<<hs->DiemThi.dAv<<"||" << setw(8)<<left<<hs->DiemThi.tohop<<"||"<<setw(11) << left<<hs->DiemThi.tbth<<"||"<<setw(8)<<left<<hs->DiemThi.tb12<<"||"<<setw(8)<<left<<hs->DiemThi.dkk<<"||"<<setw(8)<<left<<hs->DiemThi.dut<<"||"<<setw(11)<<left<<hs->DiemThi.dxtn<<"||"<<setw(18)<<left<<hs->DiaDiem.place<<"||"<<setw(15)<<left<<hs->check<<"||"<<"\n";
        pTmp=pTmp->pNext;
        i++;
    }
	fileout<<"=========================================================================================================================================================================================================\n";
    cout<<"\nDa xuat file dang bang "<<filetable<<" !!!\n";
}


int main(int argc, char** argv) {
    SingleList *list;
    Initialize(list);
	
	char c;
	do{

		Printmenu()	;
		cout<<"Nhap lua chon cua ban: ";
		cin>>c;
		if(c=='a' or c=='A'){				system("cls");
	 		ThongTin *a=NhapThongTin();	Add(list,a);}
	 	else if(c=='b' or c=='B'){			system("cls");
		cout<<"Nhap so hoc sinh can them: ";
		int add;
		cin>>add;
		for(int i=0;i<add;i++){
		cout<<"\nNhap thong tin thi sinh thu "<<i+1<<": ";			
    	ThongTin *a=NhapThongTin();
		Add(list,a);
		system("cls");}}
		else if(c=='c' or c=='C'){			system("cls");
		Remove(list);}
		else if(c=='d' or c=='D'){			system("cls");
		Find(list);}
		else if(c=='e' or c=='E'){			system("cls");
		PrintList(list);}
		else if(c=='f' or c=='F'){			system("cls");	
		Sort(list);}
		else if(c=='g' or c=='G'){			system("cls");
		CheckTN(list);}
		else if(c=='h' or c=='H'){			system("cls");
			CheckBan(list);
		}
		else if(c=='i' or c=='I'){			system("cls");
			KhuVuc(list);
		}
		else if(c=='j' or c=='J'){			system("cls");
			EditInfor(list);
		}
		else if(c=='k' or c=='K'){
			std::ifstream file;
			char filename[100];
			cout<<"Ten file ban muon doc: ";
			cin>>filename;
			file.open(filename, ios_base::in);
			if(file.fail()==true)
			{	
				cout<<"\nFile khong ton tai hoac sai duong dan!!\n";
			}
			else{
			docfile(list,file);}
			file.close();}
		else if(c=='m' or c=='M'){			system("cls");
			std::ofstream fileout;
			char filename[100];
			char filetable[100];
			cout<<"Nhap ten file de xuat: ";
			cin>>filename;
			strcpy(filetable,filename);
			strcat(filetable,"table.txt");
			strcat(filename,".txt");
			fileout.open(filename,ios_base::out);
			xuatfile(list,fileout,filename);
			fileout.close();
			fileout.open(filetable,ios_base::out);
			xuattable(list,fileout,filetable);
			fileout.close();}
		else if(c=='q' or c=='Q'){ 			system("cls");
			int save;
			while(save!=0 && save!=1)
			{
				cout<<"\nBan co muon luu chuong trinh truoc khi thoat ? (0:Co\t1:Khong)";
				cin>>save;
				if(save!=0 && save!=1)
					cout<<"Vui long chon lai!!";}
			if(save==0){
				std::ofstream fileout;
				char filename[100];
				char filetable[100];
				cout<<"Nhap ten file de xuat: ";
				cin>>filename;
				strcpy(filetable,filename);
				strcat(filetable,"table.txt");
				strcat(filename,".txt");
				fileout.open(filename,ios_base::out);
				xuatfile(list,fileout,filename);
				fileout.close();
				fileout.open(filetable,ios_base::out);
				xuattable(list,fileout,filetable);
				fileout.close();}
		cout<<"Da thoat chuong trinh!!";	break;}
		else{					system("cls");
			cout<<"Khong co lua chon!! Nhap lai!!";}

	}while(true);
	
}
