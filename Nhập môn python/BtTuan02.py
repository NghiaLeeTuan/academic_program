#%% Bai 01:
print("Nhap N: ")
N=int(input())
print(N)
LaSNT = True
if(N<2):
    LaSNT = False
else:
    for i in range(2,N-1):
        if (N%i == 0):
            LaSNT = False
if(LaSNT):
    print("La so nguyen to!!")
else:
    print("Khong la so nguyen to!!")

# %% Bai 02:
print("Nhap A: ")
A=int(input())
print(A)
print("Nhap B: ")
B=int(input())
print(B)
LaSNT = True
for N in range (A,B):
    if(N<2):
        LaSNT = False
    else:
        for i in range(2,N-1):
            if (N%i == 0):
                LaSNT = False
    if(LaSNT):
        print(N)
    LaSNT=True

# %% Bai 03
print("Nhap A: ")
A=int(input())
print(A)
print("Nhap B: ")
B=int(input())
print(B)
TmpA=A
TmpB=B
while ( TmpA != TmpB):
    if (TmpA > TmpB):
        TmpA = TmpA - TmpB
    else:
        TmpB = TmpB - TmpA
print("UCLL:",TmpA)
print("BCNN:",A * B / TmpA)


# %%Bai 04:
A=int(input())
print(A)
while(A>=0):
    A=int(input())
    print(A)


# %%Bai 05
def UCLN(TmpA,TmpB):
    while ( TmpA != TmpB):
        if (TmpA > TmpB):
            TmpA = TmpA - TmpB
        else:
            TmpB = TmpB - TmpA
    return TmpA
def BCNN(TmpA,TmpB):
    Uoc=UCLN(TmpA,TmpB)
    Boi=TmpA * TmpB / Uoc
    return Boi
A=int(input())
print(A)
TmpU=TmpB=A
while(A>0):
    A=int(input())
    print(A)
    if(A<=0):
        print("BCNN:",Boi)
        print("UCLN:",Uoc)
    else:
        Uoc=(UCLN(TmpU,A))
        TmpU=Uoc
        Boi=BCNN(TmpB,A)
        TmpB=Boi


# %%Bai 06:
import math
print("Nhap A: ")
A=int(input())
print(A)
print("Nhap B: ")
B=int(input())
print(B)
print("Nhap C: ")
C=int(input())
print(C)
if(A==0):
    if(B==0):
        if(C==0):
            print("Phuong trinh vo so nghiem!!")
        else:
            print("Phuong trinh vo nghiem!!")
    else:
        print("Phuong trinh co nghiem x=",1.0*(-C/B))
else:
    delta=B*B-4*A*C
    if(delta<0):
        print("Phuong trinh vo nghiem!!")
    elif(delta==0):
        print("Phuong trinh co nghiem kep x1=x2=",1.0*(-B/(2*A)))
    else:
        print("Phuong trinh co nghiem x1=",((-B+math.sqrt(delta))/(2*A)))
        print("x2=",((-B-math.sqrt(delta))/(2*A)))
# %%Bai 05
TienVon=50000000
TienCanTichLuy=500000000
nam=0
while(TienVon<TienCanTichLuy):
    TienVon=TienVon+TienVon*0.053
    nam = nam +1
print("Tong so nam de tich luy 500 trieu: ",nam)  


# %%
