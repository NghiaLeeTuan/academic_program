#%%câu 1
import string
from tokenize import Name
DayOfMonth=[0,31,28,31,30,31,30,31,31,30,31,30,31]
def CheckYear(year):
    if(year%400 ==0 or (year%4==0 and year%100!=0)):
        return True
    return False
def CheckDayOfMonth(DayOfMonth,year):
    if CheckYear(year)==True:
        DayOfMonth[2]+=1
    return DayOfMonth[2]
def CheckBirth(day,month,year,DayOfMonth):
    if year > 0:
        CheckDayOfMonth(DayOfMonth,year)
        print(DayOfMonth[2])
        if(0< day<= DayOfMonth[month] and 0<month <13):
            return True
        else:
            print("Nhập sai ngày tháng năm,vui lòng nhập lại")
            return False
    else:
        print("Nhập sai ngày tháng năm,vui lòng nhập lại")
        return False
def Find_DATE(Name,day,month,year):
    if(CheckYear(year)):
        year+=100
        if(month==2 and day==29):
            day=1
            month=3
    else:
        year+=100
    print("Chào",Name,", ngày bạn tròn 100 tuổi là:",day,"/",month,"/",year)
print("Nhập họ và tên của bạn: ")
Name=input("Nhập họ và tên:")
# các hàm liên quan về ngày tháng năm
print("Nhập Ngày tháng năm sinh, cách nhau bằng khoảng trống")
Birth=(input("Ngày tháng năm sinh của bạn:").split())
day=int(Birth[0])
month=int(Birth[1])
year=int(Birth[2])
while(CheckBirth(day,month,year,DayOfMonth)==False):
    print("Nhập Ngày tháng năm sinh, cách nhau bằng khoảng trống")
    Birth=(input("Ngày tháng năm sinh của bạn:").split())
    day=int(Birth[0])
    month=int(Birth[1])
    year=int(Birth[2])
Find_DATE(Name,day,month,year)

# %%câu 2
def Xoamoiphantutrunglap(list1,length):
    list2=list()
    for i in range (0,length):
        if (list1.count(list1[i])<2):
            list2.append(list1[i])
    return list2
list1 = list(map(int, input("Nhập các phần tử của danh sách trên một dòng,cách nhau bằng khoảng trống: ").split()))
print("Chuỗi vừa nhập là:",list1)
length=len(list1)
list2=Xoamoiphantutrunglap(list1,length)
print("Chuỗi sau khi loại bỏ :",list2)

# %%câu 3
def Daochuoi(list1):
    tmpstr=""
    i=len(list1)-1
    while(i>=0):
        tmpstr=tmpstr+list1[i]
        if(i>0):
            tmpstr=tmpstr +' '
        i-=1
    return tmpstr
list1=input("nhap chuoi:").split()
i=0
tmpstr=""
while(i<len(list1)):
        tmpstr=tmpstr+list1[i]
        if(i>=0):
            tmpstr=tmpstr +' '
        i+=1
print("Chuoi vua nhap la:",tmpstr)
str=Daochuoi(list1)
print("Chuoi sau khi dao la:",str)
# %%Cau 4
def Kiemtraphantutrung(chuoi):
    tmpstr=[]
    tmp=[]
    for i in range(0,len(chuoi)):
        if(chuoi.count(chuoi[i])<2):
            tmpstr.append(chuoi[i])
        else:
            if(chuoi[i] not in tmp):
                tmp.append(chuoi[i])
    return tmpstr,tmp #trả về chuổi sau khi tách và các phần tử trùng
def Sapxep(chuoi):
    #interchange sort
    chuoi=' '.join(sorted(set(chuoi)))
    return chuoi
def Tachchuoi(chuoi):
    tmpstr,tmp=Kiemtraphantutrung(chuoi)
    tmpstr=Sapxep(tmpstr)
    return tmpstr,tmp
def Demphantutrung(tmp,chuoi):
    for i in range(0,len(tmp)):
        print(tmp[i],"=",chuoi.count(tmp[i]))
    return
list1 = input().split()
i=0
tmpstr=""
while(i<len(list1)):
    tmpstr=tmpstr+list1[i]
    if(i>=0):
        tmpstr=tmpstr +' '
    i+=1
print("Chuoi vua nhap la:",tmpstr)
str,tmp=Tachchuoi(list1)
print(str)
print("Đếm sô lượng các từ trùng: ")
Demphantutrung(tmp,list1)

# %%Câu 5
def Isdigit(char):
    for i in char:
        if(i>'9' or i<'0'):
            return False
    return True
def Isalpha(char):
    for i in char:
        if(i<'a' or i>'z') and (i<'A' or i>'Z'):
            return False
    return True
list1=input().split()
dic={"chuoiso":0,"chuoikitu":0}
j=0
str=""
while(j<len(list1)):
    str=str+list1[j]
    if(j>=0):
        str=str +' '
    j+=1
print("Chuoi vua nhap la:",str)
for i in list1:
    if(Isdigit(i)):
        dic["chuoiso"]+=1
    elif(Isalpha(i)):
        dic["chuoikitu"]+=1
    else:
        continue
print("Số chữ cái:",dic["chuoikitu"])
print("Số chữ số:",dic["chuoiso"])

# %%câu 6:
def Checkkitudacbiet(Password):
    kitu=['@','$','#']
    for i in Password:
        if(i in kitu ):
            return True
    return False
def Checkkituthuong(Password):
    for i in Password:
        if(i>='a' and i<='z'):
            return True
    return False
def Checkkituhoa(Password):
    for i in Password:
        if(i>='A' and i<='Z'):
            return True
    return False
def Checkkituso(Password):
    for i in Password:
        if(i>='0' or i<='9'):
            return True
    return False
def CheckPass(Password):
    if(Password==""):
        print("Vui lòng nhập mật khẩu")
        return False
    if(len(Password) < 6 or len(Password)>12):
        print("Mật khẩu không hợp lệ ,phải có ít nhất 6 kí tự hoặc độ dài mật khẩu lớn hơn 12 kí tự")
        return False
    if(Checkkituthuong(Password)==False):
        print("Mật khẩu không hợp lệ ,phải có ít nhất 1 chữ cái nằm trong [a...z]")
        return False
    if(Checkkituhoa(Password)==False):
        print("Mật khẩu không hợp lệ ,phải có ít nhất 1 chữ cái nằm trong [A...Z]")
        return False
    if(Checkkituso(Password)==False):
        print("Mật khẩu không hợp lệ ,phải có ít nhất 1 chữ cái nằm trong [0-9]")
        return False
    if (Checkkitudacbiet(Password)==False):
        print("Mật khẩu không hợp lệ ,phải có ít nhất 1 kí tự là $ hoặc # hoặc @")
        return False
    else:
        print("Mật khẩu hợp lệ")
        return True
User=input("Nhập tên người dùng:")
Password=input("Nhap mật khẩu:")
while(True):
    if(CheckPass(Password)==False):
        Password=input("Nhập lại mật khẩu:")
    else:
        print("Tên người dùng:",User)
        print("Mật khẩu:",Password)
        break


# %%
