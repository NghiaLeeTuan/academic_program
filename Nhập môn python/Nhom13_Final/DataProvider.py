#%%
import pyodbc 
import pandas as pd
import  datetime
class DataProvider:
    def __init__(self):
        server = "LAPTOP-MGUBVM0I\\SQLEXPRESS"
        database = "QLNX"       
       # self.cnxn = pyodbc.connect('DRIVER={ODBC Driver 17 for SQL Server}; SERVER='+server+'; DATABASE='+database+';')
        username="mylan"
        password="123456"
        self.cnxn = pyodbc.connect("DRIVER={ODBC Driver 17 for SQL Server};SERVER="+server+";DATABASE="+database+";UID="+username+";PWD="+ password)
       # cursor = cnxn.cursor()  
    def ExecuteQuery(self,query):
        cursor=self.cnxn.cursor()
        cursor.execute(query)
        return cursor
    
    def GetTable(self,query,parameter):
        cursor=self.cnxn.cursor()
        cursor.execute(query,parameter)
        return cursor
    
    def ExecuteNonQuery(self,query,parameter):
        cursor=self.cnxn.cursor()
        cursor.execute(query,parameter)
        return len(cursor.fetchall())
        
    def AddQuery(self,query,parameter):
        try:
            cursor=self.cnxn.cursor()
            cursor.execute(query,parameter)
            cursor.commit()
            return True
        except:
            return False
    def DeleteQuery(self,query,parameter):
        try:
            cursor=self.cnxn.cursor()
            cursor.execute(query,parameter)
            cursor.commit()
            return True
        except:
            return False
print("hgefhwjkdwl")
# %%
