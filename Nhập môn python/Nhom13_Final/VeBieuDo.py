#%%
from datetime import datetime
import pyodbc
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from DataProvider import *
def getData(datefrom,dateto):
    #server = '(localdb)\MSSQLLocalDB' 
    #server='.\SQLEXPRESS'
    #database = 'QLNX'    #self.cnxn = pyodbc.connect(r'Driver=ODBC Driver 17 for SQL Server;'r'Server=.\SQLEXPRESS;'r'Database=QLNX;'r'Trusted_Connection=yes;')
    #conn = pyodbc.connect('DRIVER={ODBC Driver 17 for SQL Server};SERVER='+server+';DATABASE='+database+';')
    dp=DataProvider()
    strquery="SELECT FORMAT(checkin,'dd-MM-yy') as Ngay, Count(checkin) as SoLuong from customer where checkin>=? and checkin<=? group by FORMAT(checkin,'dd-MM-yy')"
    para=(datefrom,dateto)
    data = dp.GetTable(strquery,para)
    return data
def Show(datefrom,dateto):
    data = getData(datefrom,dateto)
    #data.info()
    #data.head()
    #data.describe()
    #print(data)

    fig = plt.figure()
    ax = fig.add_subplot(111)
    x=[]
    y=[]
    for row in data:
        x.append(row.Ngay)
        y.append(row.SoLuong)
    #x = data["Ngay"]
    #y = data["SoLuong"]
    doanhThu =0;
    for sl in y:
        doanhThu +=sl
    doanhThu = doanhThu*10000

    tx = "Doanh thu: "+str(doanhThu) 

    plt.plot(x,y, label=tx)
    plt.xlabel('Ngày')
    plt.ylabel('Số lượng xe')
    plt.title('Thống kê')
    plt.legend()
    plt.grid()
    plt.show()

# %%
