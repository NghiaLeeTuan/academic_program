#%%Bai01:Cho numpy array có các phần tử: [-2 6 3 10 15 48], viết lệnh (không sử dụng vòng lặp) để lấy ra các bộ phần tử: [3 15], [6 10 48], [10 15 48], [48 15 10]. Gợi ý: slicing Python.
from re import X
from xmlrpc.client import Boolean
import numpy as np
np.array= [-2,6,3,10,15,48]
print(np.array[2::2])
print(np.array[1::2])
print(np.array[3:])
print(np.array[-1:-4:-1])

#%%Bai02:Tạo một 2D numpy array và thử dùng các hàm max(), max(0), max(1) để để thấy sự khác biệt. Cú pháp: ten_mang.max().
import numpy as np
arr=np.array([[1,2,3],[4,5,6]])
print(arr)
print(arr.max())
print(arr.max(0))
print(arr.max(1))
# %%Viết hàm giải phương trình bậc 1 và bậc 2. Các hệ số của phương trình là tham số của hàm. 
import math
while(True):
    print("1.Ptrinh bac 1 ax+b=0")
    print("2.Ptrinh bac 2 ax^2+bx+c=0")
    print("0.Thoat")
    print("Lua chon: ")
    choose=int(input())
    if(choose==0):
        break
    if(choose==1):
        print("Nhap a: ")
        a=int(input())
        print("nhap b: ")
        b=int(input())
        if(a==0):
            print("Ptr vo nghiem!!")
        else:
            x=1.0*(-b/a)
            print("x= ",x)
    if(choose==2):
        print("Nhap a: ")
        a=int(input())
        print("Nhap b: ")
        b=int(input())
        print("Nhap c: ")
        c=int(input())
        if(b*b-4*a*c<0):
            print("Ptr vo nghiem!!")
        elif(b*b-4*a*c==0):
            x=1.0*(-b/2*a)
        elif(b*b-4*a*c>0):
            x1=1.0*((-b+math.sqrt(b*b-4*a*c))/(2*a))
            x2=1.0*((-b-math.sqrt(b*b-4*a*c))/(2*a))
            print("x1= ",x1)
            print("x2= ",x2)                
# %%Viết hàm có tham số là một mảng số bất kỳ và sắp xếp mảng tăng dần. Yêu cầu: dùng vòng lặp for sắp xếp mảng, dùng list để chứa mảng.
mang=[2,29,3,8,25,82,11]
length=len(mang)
for i in range(0,length-1):
    index=i
    for j in range(i+1,length):
        if mang[j] < mang[index]:
            index=j
    temp=mang[i]
    mang[i]=mang[index]
    mang[index]=temp
print(mang)

# %%Viết hàm có hai tham số là một mảng số bất kỳ và một tham số boolean tên SapXepTang. Nếu tham số SapXepTang có giá trị True thì sắp xếp mảng tăng dần, có giá trị False thì sắp giảm dần. Yêu cầu: dùng for sắp xếp mảng, dùng numpy array để chứa mảng. Nếu người dùng không nhập SapXepTang thì mặc định là sắp tăng dần.

import numpy as np
mang=np.array([4,3,5,6,1])
Size=mang.size
lc=int(input("True:0/False:1: "))
if(lc==1):
    SapXepTang=False
else:
    SapXepTang=True
if (SapXepTang):
    for i in range(0,Size-1):
        index=i
        for j in range(i+1,Size):
            if mang[j] < mang[index]:
                index=j
        temp=mang[i]
        mang[i]=mang[index]
        mang[index]=temp
else:
    for i in range(0,Size-1):
        index=i
        for j in range(i+1,Size):
            if mang[j] > mang[index]:
                index=j
        temp=mang[i]
        mang[i]=mang[index]
        mang[index]=temp
print(mang)

# %%
