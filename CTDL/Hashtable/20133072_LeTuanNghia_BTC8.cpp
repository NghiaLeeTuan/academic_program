#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<string>
#define MAX 100000
using namespace std;
struct Date
{
	int day, month, year;
};

struct Cityzen
{
	string CMND;// key
	string Name;
	Date Birthday;
	string BirthPlace;
	string ThuongTru;
	string TamTru;
	string CongViec;
	string TrinhDo;
	
};

struct CityzenNode
{
	Cityzen data;
	CityzenNode *pNext;
};

void Init(CityzenNode *HashTable[])
{
	for(int i=0; i<MAX; i++)
	{
		HashTable[i]= NULL;
	}
}

CityzenNode *CreateNode(Cityzen c)
{
	CityzenNode *p= new CityzenNode();
	p->data= c;
	p->pNext= NULL;
}


int HashFunction(string CMND)
{
	int l =CMND.length();
	int ind= 0;
	for(int i=0; i<l;i++)
	{
		ind= (ind + (CMND[i]-'0' ))%MAX;
	}
	return ind;
}



bool Check(CityzenNode *HashTable[], string CMND)
{
	CityzenNode *p;
	int l= CMND.length();
	for(int i=0; i<l;i++)
	{
		if(!(CMND[i]>='0' && CMND[i]<='9'))
		{
			return false;
		}
	}
	
	for(int i=0; i<MAX; i++)
	{
		p= HashTable[i];
		for(p;p!=NULL; p=p->pNext)
		{
			if(p->data.CMND== CMND)
			{
				return false;
				break;
			}
		}
	}
	return true;
}

bool Nhuan(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	else
		return false;
}
int NgayHopLe(Date kt)
{
	if (kt.day < 0 || kt.month <= 0 || kt.month >12 || kt.year <=0)
	{
		return 0;
	}
	switch (kt.month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if (kt.day <= 0 || kt.day > 31)
			return 0;
		else
			return 1;
		break;
	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		if (kt.day <= 0 || kt.day > 30)
			return 0;
		else
			return 1;
		break;
	}
	case 2:
		if (Nhuan(kt.year == 1))
		{
			if (kt.day <= 0 || kt.day > 29)
				return 0;
			else
				return 1;
		}
		else
		{
			if (kt.day <= 0 || kt.day > 28)
				return 0;
			else return 1;
		}
	}
}

void ChuanHoa(string &name)
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



void Input(CityzenNode *HashTable[], Cityzen &c)
{
	cout<<"Nhap thong tin cong dan "<<endl;
	cout<<"So CMND/CCCD: ";
	cin.ignore();
	getline(cin,c.CMND);
	while(Check(HashTable,c.CMND)==false)
	{
		cout<<"So CMND/CCCD vua nhap da ton tai hoac co chua cac ki tu khong hop le. Moi nhap lai: ";
		getline(cin,c.CMND);
	}
	cout<<"Ho va ten: ";
	getline(cin,c.Name);
	ChuanHoa(c.Name);
	cout<<"Ngay thang nam sinh(dd mm yyyy): ";
	cin>>c.Birthday.day>>c.Birthday.month>>c.Birthday.year;
	while(NgayHopLe(c.Birthday)==0)
	{
		cout<<"Ngay thag nam vua nhap khong hop le. Moi nhap lai: ";
		cin>>c.Birthday.day>>c.Birthday.month>>c.Birthday.year;
	}
	cout<<"Noi sinh: ";
	cin.ignore();
	getline(cin,c.BirthPlace);
	ChuanHoa(c.BirthPlace);
	cout<<"Dia chi thuong tru: ";
	getline(cin,c.ThuongTru);
	ChuanHoa(c.ThuongTru);
	cout<<"Dia chi tam tru: ";
	getline(cin,c.TamTru);
	ChuanHoa(c.TamTru);
	cout<<"Nghe nghiep: ";
	getline(cin,c.CongViec);
	cout<<"Trinh do chuyen mon: ";
	getline(cin,c.TrinhDo);
	
	cout<<"Da them thanh cong!!"<<endl;
	
}

CityzenNode *Search(CityzenNode *HashTable[], string CMND)
{
	int ind = HashFunction(CMND);
	if(HashTable[ind]!=NULL)
	{
		for(CityzenNode *i= HashTable[ind]; i!= NULL; i=i->pNext)
		{
			if(i->data.CMND == CMND)
				return i;
		}
	}
	else	return NULL;
}

CityzenNode *Findprev(CityzenNode *HashTable[], string CMND)
{
	int ind = HashFunction(CMND);
	CityzenNode *prev;
	prev= HashTable[ind];
	bool check =false;
	if(prev!=NULL)
	{
		while(check == false && prev->pNext!=NULL)
			if(prev->pNext->data.CMND== CMND)
				check = true;
			else
				prev=prev->pNext;
		if(check== false)
			prev= NULL;
	}	
	return prev;
}
void Delete(CityzenNode *HashTable[], string CMND)
{
	int ind= HashFunction(CMND);
	CityzenNode *p,*Prev;
	Prev= Findprev(HashTable,CMND);
	p= Search(HashTable, CMND);
	if(p!=NULL)
	{
		if(Prev!=NULL)
		{
			Prev->pNext=p->pNext;
			delete p;
		}
		else
			HashTable[ind]=p->pNext;
	}
}

void Add(CityzenNode *HashTable[], Cityzen c)
{
	int ind = HashFunction(c.CMND);
	
	CityzenNode *temp= CreateNode(c);
	
	temp->pNext= HashTable[ind];
	HashTable[ind]= temp;
}

void UpdateInput(CityzenNode *HashTable[], Cityzen &c)
{
	cout<<"Cap nhat so CMND/CCCD: ";
		cin.ignore();
		getline(cin,c.CMND);
		while(Check(HashTable,c.CMND)==false)
		{
			cout<<"So CMND/CCCD vua nhap da ton tai hoac chua cac ki tu khong hop le. Moi nhap lai: ";
			cin>>c.CMND;
		}
		cout<<"Ho va ten: ";
		getline(cin,c.Name);
		ChuanHoa(c.Name);
		cout<<"Ngay thang nam sinh(dd mm yyyy): ";
		cin>>c.Birthday.day>>c.Birthday.month>>c.Birthday.year;
		while(NgayHopLe(c.Birthday)==0)
		{
			cout<<"Ngay thag nam vua nhap khong hop le. Moi nhap lai: ";
			cin>>c.Birthday.day>>c.Birthday.month>>c.Birthday.year;
		}
		cout<<"Noi sinh: ";
		cin.ignore();
		getline(cin,c.BirthPlace);
		ChuanHoa(c.BirthPlace);
		cout<<"Dia chi thuong tru: ";
		getline(cin,c.ThuongTru);
		ChuanHoa(c.ThuongTru);
		cout<<"Dia chi tam tru: ";
		getline(cin,c.TamTru);
		ChuanHoa(c.TamTru);
		cout<<"Nghe nghiep: ";
		getline(cin,c.CongViec);
		cout<<"Trinh do chuyen mon: ";
		getline(cin,c.TrinhDo);
}

void Update(CityzenNode *HashTable[],string CMND)
{
	CityzenNode *p= Search(HashTable,CMND);
	Cityzen c;
	if(p!=NULL)
	{
		cout<<"DA TIM THAY. BAT DAU CAP NHAT:"<<endl;
		UpdateInput(HashTable,c);
		
		if(c.CMND != CMND)
		{
			Delete(HashTable,CMND);
			Add(HashTable,c);
		}
		else
		{
			p->data.Name= c.Name;
			p->data.BirthPlace= c.BirthPlace;
			p->data.ThuongTru=c.ThuongTru;
			p->data.TamTru= c.TamTru;
			p->data.CongViec= c.CongViec;
			p->data.TrinhDo=c.TrinhDo;
		}
		cout<<"CAP NHAT THANH CONG!"<<endl;
	}
	else
	{
		cout<<"KHONG TIM THAY NGUOI CAN CAP NHAT"<<endl;
	}
}

void DateOutput(Date d)	
{
	cout << setw(2) << d.day << "/"<< setw(2) << d.month << "/"<<left<<setw(4) << d.year << "||";
}

void Output1(Cityzen c)
{
	cout<<"||";
	cout<<setw(12)<<left<<c.CMND<<"||";
	cout<<setw(25)<<left<<c.Name<<"||";
	DateOutput(c.Birthday);
	cout<<setw(20)<<left<<c.BirthPlace<<"||";
	cout<<setw(20)<<left<<c.ThuongTru<<"||";
	cout<<setw(20)<<left<<c.TamTru<<"||";
	cout<<setw(15)<<left<<c.CongViec<<"||";
	cout<<setw(20)<<left<<c.TrinhDo<<"||";
	cout<<endl;
	cout<<"||============||=========================||==========||====================||====================||====================||===============||====================||"<<endl;
}
void Output(Cityzen c,int i)
{
	cout<<"||";
	cout<<setw(8)<<left<<i<<"||";
	cout<<setw(12)<<left<<c.CMND<<"||";
	cout<<setw(25)<<left<<c.Name<<"||";
	DateOutput(c.Birthday);
	cout<<setw(20)<<left<<c.BirthPlace<<"||";
	cout<<setw(20)<<left<<c.ThuongTru<<"||";
	cout<<setw(20)<<left<<c.TamTru<<"||";
	cout<<setw(15)<<left<<c.CongViec<<"||";
	cout<<setw(20)<<left<<c.TrinhDo<<"||";
	cout<<endl;
}

void TableHead()
{
	for(int i=1; i<=170;i++)
	{
		cout<<"=";
	}
	cout<<endl;
	cout<<"|| Vi tri || CMND/CCCD  ||        HO VA TEN        ||NGAY SINH ||      NOI SINH      || DIA CHI THUONG TRU ||  DIA CHI TAM TRU   ||  NGHE NGHIEP  ||TRINH DO CHUYEN MON ||"<<endl;
	cout<<"||========||============||=========================||==========||====================||====================||====================||===============||====================||"<<endl;
}
void OutputList(CityzenNode *HashTable[])
{
	CityzenNode *p;
	TableHead();
	for(int i=0; i<MAX; i++)
	{
		p=HashTable[i];
		while(p!=NULL)
		{
			Output(p->data,i);
			p=p->pNext;
		}
	}
	for(int i=1; i<=170;i++)
	{
		cout<<"=";
	}
	cout<<endl;
}
void ReadFromFile(CityzenNode *HashTable[])
{
	int n;
	ifstream file("Danhsachcongdan.txt");
	if(file.good())
	{
		file>>n;
		file.ignore();
		for(int i=1; i<=n; i++)
		{
			Cityzen c;
			getline(file,c.CMND);
			getline(file,c.Name);
			ChuanHoa(c.Name);
			file>>c.Birthday.day>>c.Birthday.month>>c.Birthday.year;
			file.ignore();
			getline(file,c.BirthPlace);
			ChuanHoa(c.BirthPlace);
			getline(file,c.ThuongTru);
			ChuanHoa(c.ThuongTru);
			getline(file,c.TamTru);
			ChuanHoa(c.TamTru);
			getline(file,c.CongViec);
			getline(file,c.TrinhDo);
			file.ignore();
			Add(HashTable,c);
		}
		file.close();
		cout<<"DOC FILE THANH CONG!!"<<endl;
	}
	else
	{
	cout<<"KHONG THE DOC FILE\n";
	return;
	}
}
int main()
{
	CityzenNode *HashTable[MAX];
	Init(HashTable);
	Cityzen Temp;
	CityzenNode *p;
	
	while (1)
	{
		int op;
		cout<<" ===========================MENU==========================="<<endl;
		cout<<" ||1. DOC DANH SACH CONG DAN TU FILE                     ||"<<endl;
		cout<<" ||2. THEM 1 CONG DAN                                    ||"<<endl;
		cout<<" ||3. XOA 1 CONG DAN                                     ||"<<endl;
		cout<<" ||4. CHINH SUA THONG TIN CONG DAN                       ||"<<endl;
		cout<<" ||5. TIM KIEM CONG DAN THEO SO CMND                     ||"<<endl;
		cout<<" ||6. XUAT DANH SACH CONG DAN                            ||"<<endl;
		cout<<" =========================================================="<<endl;
		cout<<"NHAP LUA CHON CUA BAN : ";
		cin>>op;
		cout<<endl;

		switch (op)
		{
		case 1:
			ReadFromFile(HashTable);
			break;
		case 2:
			Input(HashTable, Temp);
			Add(HashTable, Temp);
			break;
		case 3:
			cout<<"\nNhap so CMND cua cong dan can xoa: ";
			cin.ignore();
			cin>>Temp.CMND;
			Delete(HashTable,Temp.CMND);
			break;
		case 4:
			cout<<"Nhap so CMND/CCCD cua nguoi can chinh sua: ";
			cin>>Temp.CMND;
			Update(HashTable, Temp.CMND);
			break;
		case 5:
			cout<<"Nhap so CMND cua nguoi can tim: ";
			cin>>Temp.CMND;
			p=Search(HashTable,Temp.CMND);
			if(p!=NULL)
			{
				Output1(p->data);
			}
			else
				cout<<"KHONG TIM THAY NGUOI CO SO CMND "<<Temp.CMND<<endl;
			break;
		case 6:
			OutputList(HashTable);
			break;
		default:
			exit(1);
		}
	}
	return  0;
}
