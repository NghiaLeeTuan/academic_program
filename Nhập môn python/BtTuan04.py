#%%
from calendar import month
from cmath import sqrt
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
        if(0< day<= DayOfMonth[month] and 0<month <13):
            return True
        else:
            print("Nhập sai ngày tháng năm,vui lòng nhập lại")
            return False
    else:
        print("Nhập sai ngày tháng năm,vui lòng nhập lại")
        return False
def Outp(Name,day,month,year):
    if(CheckYear(year)):
        year+=100
    else:
        year+=100
    print("Chào",Name,", năm bạn tròn 100 tuổi là:",year)
def InputInfo():
    print("Nhập họ và tên của bạn: ")
    Name=input("Nhập họ và tên:")
    print(Name)
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
    print("Ngày tháng năm sinh:",day,"/",month,"/",year)
    Outp(Name,day,month,year)
#ham nhap
InputInfo()

# %%Cau 2:
n=int(input("Nhap N: "))
print("N vua nhap:",n)
def giaithua(n):
    tmp=1
    for i in range (1,n+1):
        tmp*=i
    return tmp
GT=giaithua(n)
print("Gia tri cua N giai thua:",GT)

# %%Cau 3:
def func(*args):
    print(args)
    return
func("abc", "bac")
func("a123", "b234", "c456", "d789")


# %%04
import os as folder
def Hien_thi_thong_tin():
    print("Folder hiện tại là: ", folder.getcwd())
    print("Các thư mục con và tập tin:", folder.listdir(folder.getcwd()))
def Chuyen_thu_muc(_link):
    try:
        folder.chdir(_link)
    except FileNotFoundError:
        print("Đường link không tồn tại")
        return
    print("Địa chỉ sau khi chuyển:", folder.getcwd())
Hien_thi_thong_tin()
Chuyen_thu_muc("D:\Môn học")


# %%
import datetime
yearBirth=int(input("Vui lòng nhập năm sinh:"))
def Age(yearBirth):
    ageNow=datetime.datetime.today().year - yearBirth
    return ageNow
print("Năm sinh của bạn:",yearBirth)
age=Age(yearBirth)
print("Tuổi hiện tại của bạn là:",Age(yearBirth))

# %%
import math
import numpy
import datetime
#tính căn bậc 2 của 1 số
n=int(input("Nhap n:"))
def BinhPhuong(n):
    BP=math.sqrt(n)
    print("Căn bậc 2 của N: ",BP)
    return
BinhPhuong(n)
#tìm max trong mảng 2 chiều
A=numpy.array([[1,2,3],[9,6,5]])
print("Số lớn nhất trong mảng:",A.max())
#In ngày giờ hiện tại
print("Giờ hiện tại là:", datetime.datetime.now())

# %%
