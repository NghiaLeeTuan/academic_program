#include<stdio.h>
#include<conio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#define MAX 1000
using namespace std;
// T?o c?u trúc Student
struct Ngaysinh {
int ngay;
int thang;
int nam;
};
struct SinhVien {
int id;
char ten[30];
char gtinh[5];
int tuoi;
float dToan;
float dLy;
float dHoa;
float dTB = 0;
char xLoai[10] = "-";
};
struct ArrList
{
SinhVien stud[MAX];
int len=0;
int maxLen=MAX;
};



int keyPress(int Clear);
void printLine(int n);
bool isEmpty(ArrList &dsSV);
bool isFull(ArrList &dsSV);
void tinhDTB(SinhVien &ItemSV);
void xeploai(SinhVien &ItemSV);
void capNhatThongTinSV(SinhVien &ItemSV);
void nhapThongTinSV(ArrList &dsSV, int id);
void nhapSV(ArrList &dsSV);
void capNhatSV(ArrList &dsSV, int id);
int xoaTheoID(ArrList &dsSV, int id);
void timKiemTheoTen(ArrList &dsSV, char ten[]);
void sapxepTheoDTB(ArrList &dsSV);
void sapXepTheoTen(ArrList &dsSV);
void showStudent(ArrList &dsSV);
void docFile(ArrList &dsSV, char fileName[]);
void ghiFile(ArrList &dsSV, char fileName[]);


int main() {
int key;
char fileName[] = "sinhvien.txt";
ArrList dsSV;
while(true) {
cout << " INFORMATION STUDENT MANAGEMENT \n";
cout << "======================MENU==================\n";
cout << "|| 1. Read student from file              ||\n";
cout << "|| 2. Add a student.                      ||\n";
cout << "|| 3. Update student information using ID ||\n";
cout << "|| 4. Delete student using ID.            ||\n";
cout << "|| 5. Find student using Name.            ||\n";
cout << "|| 6. Sort student list using GPA.        ||\n";
cout << "|| 7. Sort student list using name        ||\n";
cout << "|| 8. Print student list.                 ||\n";
cout << "|| 9. Write student list to file.         ||\n";
cout << "|| 0. Thoat ||\n";
cout << "======================END====================\n";
// cout << "Press a key ";
// cin >> key;
key=keyPress(1);
switch(key){
case 1:
docFile(dsSV, fileName);
if(!isEmpty(dsSV)){
printf("\nDoc danh sach Student tu file %s thanh cong!", fileName);
}
else {
printf("\nDoc danh sach Student tu file %s khong thanh cong!", fileName);
}
//keyPress(1);
break;
case 2:
if(!isFull(dsSV)) {
cout << "\nAdd a student.";
nhapSV(dsSV);
printf("\nSuccessfuly!");
}else{
cout << "\nDanh sach Student Full, khong them duoc!";
}
//keyPress(1);
break;
case 3:
if(!isEmpty(dsSV)) {
int id;
cout << "\nUpdate student information using ID. ";
cout << "\nNhap ID: "; cin >> id;
capNhatSV(dsSV, id);


}else{
cout << "\nDanh sach Student empty!";
}
//keyPress(1);
break;
case 4:
if(!isEmpty(dsSV)) {
int id;
cout << "\nXoa Student .";
cout << "\nNhap ID: "; cin >> id;
if (xoaTheoID(dsSV, id) == 1) {
printf("\nStudent co id = %d da bi xoa.", &id);
}
}else{
cout << "\nDanh sach Student trong!";
}
//keyPress(1);
break;
case 5:
if(!isEmpty(dsSV)) {
cout << "\nTim kiem Student theo ten.";
char strTen[30];
cout << "\nNhap ten de tim kiem: "; fflush(stdin); gets(strTen);
timKiemTheoTen(dsSV, strTen);
}else{
cout << "\nDanh sach Student empty!";
}
//keyPress(1);
break;
case 6:
if(!isEmpty(dsSV)) {
cout << "\nSap xep Student theo diem trung binh (GPA).";
sapxepTheoDTB(dsSV);
showStudent(dsSV);
}else{
cout << "\nDanh sach Student empty!";
}
//keyPress(1);
break;
case 7:
if(!isEmpty(dsSV)) {
cout << "\nSap xep Student theo ten.";
sapXepTheoTen(dsSV);
showStudent(dsSV);
} else {
cout << "\nDanh sach Student empty!";
}
//keyPress(1);
break;
case 8:


if(!isEmpty(dsSV)){
cout << "\nHien thi danh sach Student .";
showStudent(dsSV);
}else{
cout << "\nDanh sach Student empty!";
}
//keyPress(1);
break;
case 9:
if(!isEmpty(dsSV)){
cout << "\nGhi danh sach Student vao file.";
ghiFile(dsSV, fileName);
}else{
cout << "\nDanh sach Student empty!";
}
printf("\nGhi danh sach Student vao file %s thanh cong!", fileName);
//keyPress(1);
break;
case 0:
cout << "\n Da thoat chuong trinh!";
return 0;
default:
cout << "\nKhong co chuc nang nay!\nChon chuc nang trong menu.";
//keyPress(1);
break;
}
keyPress(0);
}
return 0;
}

//======= Student information input function
// - This function is used to add new students to the student list.
// - With this function we will split into the following two functions:
// &ItemSV: enter student information sv. Use & reference, i.e. the information will be changed both inside and outside the function.
// dsSV: is a list of students.
// id: is the id (auto increment) of the student.
void nhapThongTinSV(ArrList &dsSV, int id) {
int Ind=dsSV.len;
dsSV.len++;
dsSV.stud[Ind].id = id;
cout << "\n Nhap ten: "; fflush(stdin); gets(dsSV.stud[Ind].ten);
cout << " Nhap gioi tinh: "; gets(dsSV.stud[Ind].gtinh);
cout << " Nhap tuoi: "; cin >> dsSV.stud[Ind].tuoi;
cout << " Nhap diem Toan: "; cin >> dsSV.stud[Ind].dToan;
cout << " Nhap diem Ly: "; cin >> dsSV.stud[Ind].dLy;
cout << " Nhap diem Hoa: "; cin >> dsSV.stud[Ind].dHoa;
tinhDTB(dsSV.stud[Ind]);
xeploai(dsSV.stud[Ind]);
}
void nhapSV(ArrList &dsSV) {
printLine(40);
printf("\n Nhap Student thu %d:", dsSV.len + 1);
nhapThongTinSV(dsSV, dsSV.len);
printLine(40);
}


void capNhatThongTinSV(SinhVien &ItemSV) {
cout << "\n Nhap ten: "; fflush(stdin); gets(ItemSV.ten);
cout << " Nhap gioi tinh: "; gets(ItemSV.gtinh);
cout << " Nhap tuoi: "; cin >> ItemSV.tuoi;
cout << " Nhap diem Toan: "; cin >> ItemSV.dToan;
cout << " Nhap diem Ly: "; cin >> ItemSV.dLy;
cout << " Nhap diem Hoa: "; cin >> ItemSV.dHoa;
tinhDTB(ItemSV);
xeploai(ItemSV);
}


void capNhatSV(ArrList &dsSV, int id) {
int found = 0;
for(int i = 0; i < dsSV.len; i++) {
if (dsSV.stud[i].id == id) {
found = 1;
printLine(40);
cout << "\n Cap nhat thong tin Student co ID = " << id;
capNhatThongTinSV(dsSV.stud[i]);
printLine(40);
break;}

}
if (found == 0) {
printf("\n Student co ID = %d khong ton tai.", id);
}
}
//function computes Average score and academic ranking
// dsSV: is a list of students.
void tinhDTB(SinhVien &sv) {
sv.dTB = (sv.dToan + sv.dLy + sv.dHoa) / 3;
}
void xeploai(SinhVien &sv) {
if(sv.dTB >= 8) strcpy(sv.xLoai, "Gioi");
else if(sv.dTB >= 6.5) strcpy(sv.xLoai, "Kha");
else if(sv.dTB >= 5) strcpy(sv.xLoai, "Trung binh");
else strcpy(sv.xLoai, "Yeu");
}

//======= Function to delete students by ID
// dsSV: is a list of students.
// id: is the id of the student to be deleted.
int xoaTheoID(ArrList &dsSV, int id) {
int found = 0;
for(int i = 0; i < dsSV.len; i++) {
if (dsSV.stud[i].id == id) {
found = 1;
dsSV.len--;
printLine(40);
for (int j = i; j < dsSV.len; j++) {
dsSV.stud[j] = dsSV.stud[j+1];
}
cout << "\n Da xoa SV co ID = " << id;
printLine(40);
break;
}
}
if (found == 0) {
printf("\n Student co ID = %d khong ton tai.", id);
return 0;
} else {
return 1;
}
}

//======= Student search function by name
// dsSV: is a list of students.
// ten[]: is the keyword to compare with the student's name.
void timKiemTheoTen(ArrList &dsSV, char ten[]) {
ArrList tempdsSV;
char tenSV[30];
for(int i = 0; i < dsSV.len; i++) {
strcpy(tenSV, dsSV.stud[i].ten);
if(strstr(strupr(tenSV), strupr(ten))) {
tempdsSV.stud[tempdsSV.len] = dsSV.stud[i];
tempdsSV.len++;
}
}
showStudent(tempdsSV);
}

//=======Function to sort list of students by average score
// dsSV: is a list of students.
void sapxepTheoDTB(ArrList &dsSV) {
//Sap xep theo DTB tang dan
SinhVien tmp;
for(int i = 0;i < dsSV.len;i++){
for(int j = i+1; j < dsSV.len;j++){
if(dsSV.stud[i].dTB > dsSV.stud[j].dTB){
tmp = dsSV.stud[i];
dsSV.stud[i] = dsSV.stud[j];
dsSV.stud[j] = tmp;
}
}
}
}

//======= Function to sort the list of students by name
// dsSV: is a list of students.
void sapXepTheoTen(ArrList &dsSV) {
//Sap xep Student theo ten theo thu tu tang dan
SinhVien tmp;
char tenSV1[30];
char tenSV2[30];
for(int i = 0;i < dsSV.len; i++) {
strcpy(tenSV1, dsSV.stud[i].ten);
for(int j = i+1; j < dsSV.len; j++) {
strcpy(tenSV2, dsSV.stud[j].ten);
if(strcmp(strupr(tenSV1), strupr(tenSV2)) > 0) {
tmp = dsSV.stud[i];
dsSV.stud[i] = dsSV.stud[j];
dsSV.stud[j] = tmp;
}
}
}
}

//======= The function displays the list of students on the screen
// dsSV: is a list of students.
void showStudent(ArrList &dsSV) {
printLine(110);
cout <<"|TT\t ID\t\t ten \t\tGioi tinh\tTuoi\tToan\tLy\tHoa\tDiem TB\tXeploai";
for(int i = 0; i < dsSV.len; i++) {
// in Student thu i ra man hinh
printf("\n%-5d", i + 1);
printf("%-5d", dsSV.stud[i].id);
printf("%-30s", dsSV.stud[i].ten);
printf("%-5s", dsSV.stud[i].gtinh);
printf("\t\t%2d", dsSV.stud[i].tuoi);
printf("\t%.2f\t%.2f\t%.2f", dsSV.stud[i].dToan, dsSV.stud[i].dLy, dsSV.
stud[i].dHoa);
printf("\t%.2f", dsSV.stud[i].dTB);
printf("\t%-10s", dsSV.stud[i].xLoai);
}
printLine(110);
}


//======= The function reads the list of students from the fileName
void docFile(ArrList &dsSV, char fileName[]) {
FILE * fp;
int i = 0;
fp = fopen (fileName, "r");
cout << "Chuan bi doc file: "; puts(fileName);
// doc thong tin Student
while (fscanf(fp, "%5d %30s %5s %5d %5f %5f %5f %5f %10s\n", &dsSV.stud[i].id, &dsSV.stud[i].ten,&dsSV.stud[i].gtinh, &dsSV.stud[i].tuoi, &dsSV.stud[i].dToan, &dsSV.stud[i].dLy, &dsSV.stud[i].dHoa,&dsSV.stud[i].dTB, &dsSV.stud[i].xLoai) != EOF) {
i++;
dsSV.len=i;
}
cout << " So luong Student co san trong file la: " << i << endl;
cout << endl;
fclose (fp);
return ;
}
//======= The function writes the list of students to the fileName
void ghiFile(ArrList &dsSV, char fileName[]) {
FILE * fp;
fp = fopen (fileName,"w");
for(int i = 0;i <dsSV.len ;i++){
fprintf(fp, "%-5d %-30s %-5s %5d %2.2f %2.2f %2.2f %2.2f %-10s\n", dsSV.stud[i].id, dsSV.stud[i].ten,
dsSV.stud[i].gtinh, dsSV.stud[i].tuoi, dsSV.stud[i].dToan,
dsSV.stud[i].dLy,
dsSV.stud[i].dHoa, dsSV.stud[i].dTB, dsSV.stud[i].xLoai);
}
fclose (fp);
}
int keyPress(int Clear) {
if (Clear==0){
cout << "\n\nPress a key to continue....";
getch();
system("cls");
return 0;
} else{
cout << "\n\nPress a key to do a function:";
int keyp;
cin >> keyp;
return keyp;
}
}
// Print a line with "=" characters that will be printed to the screen.
void printLine(int n) {
cout << endl;
for (int i = 0; i < n; i++) {
cout << "=";
}
cout << endl;
}
bool isEmpty(ArrList &dsSV){
return dsSV.len==0;
}
bool isFull(ArrList &dsSV){
return dsSV.len==dsSV.maxLen;
}
