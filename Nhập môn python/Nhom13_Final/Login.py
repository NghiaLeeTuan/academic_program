# -*- coding: utf-8 -*-
#%%
"""
Created on Tue Apr 20 14:11:56 2021

@author: Administrator
"""
from docbienso import *
from PyQt5.uic import  loadUi
from PyQt5 import uic,QtGui
from PyQt5 import QtWidgets
from PyQt5.QtWidgets import *
from PyQt5.QtCore import QPropertyAnimation,QRect,Qt
import sys
import os
from VeBieuDo import * 
from DataProvider import *
import pyodbc
import datetime as datetime
import docbienso
import FormQLNV


class Login(QMainWindow):
    def __init__(self):
        super(Login,self).__init__()
        loadUi("FormLogin.ui",self) #Load UI từ file LoginForm.ui
      #  self.setWindowFlags(Qt.FramelessWindowHint)
       # self.setAttribute(Qt.WA_TranslucentBackground)
        self.pushButtonLogin.clicked.connect(self.pushButtonLogin_Clicked)
    
    def pushButtonLogin_Clicked(self):#Chức năng login
        dp=DataProvider() #Lớp DataProvider để thực hiện các query
        query="select * from login where username='"+self.lineEditUsername.text()+"' and password='"+self.lineEditPassword.text()+"'"
        if self.radioButtonNhanVien.isChecked(): #Kiểm tra RadioButton Nhân viên có check hay không
            query = query+ " and position=2" #Phân quyền đăng nhập nhân viên
        else:
            query = query+ " and position=1" #Phân quyền đăng nhập quản lý
        parameter=()#bộ parameter truyền vào Query, ở đây không truyền vào nên để rỗng
        
        result=dp.ExecuteNonQuery(query,parameter)
        if result>0 and self.radioButtonNhanVien.isChecked(): #Mở form cho nhân viên
            main=CheckInOutForm(self)
            main.show()
        elif result>0 : #Mở form cho quản lý
             main=FormQLNV(self)
             main.show()
        else:
            self.ShowMessageBox("Sai mật khẩu hoặc tên đăng nhập!")
            
    def Close(self):#Thao tác đóng
        self.Close()
        
    def ShowMessageBox(self,error): #Tạo MessageBox thông báo lỗi
        msg=QMessageBox()
        msg.setWindowTitle("Login Error")
        msg.setText(error)
        msg.setIcon(QMessageBox.Information)
        x=msg.exec_()
            
               
class CheckInOutForm(QDialog):
    def __init__(self,parent=None):
        super(QDialog,self).__init__(parent)
        loadUi("FormCheckinCheckout.ui",self)
        self.pushButtonOpenIn.clicked.connect(self.getImageIn)
        self.pushButtonOpenOut.clicked.connect(self.getImageOut)
        self.pushButtonCheckIn.clicked.connect(self.CheckIn)
        self.pushButtonCheckOut.clicked.connect(self.CheckOut)
        self.pushButtonChangePassword.clicked.connect(self.ChangePassword)
        

    def getImageIn(self):         #Load ảnh checkin
        fname = QFileDialog.getOpenFileName(self, 'Open file',r"<Default dir>", "Image files (*.jpg)")
        strrv = list(reversed(str(fname[0]).split("/")))
        imagePath = strrv[0]
        print(imagePath)     #tên ảnh ex: "bs17.jbg"
        print(docbienso.GetLicense(imagePath))
        self.lineEditLicensePlateIn.setText((docbienso.GetLicense(imagePath)))
        scene = QtWidgets.QGraphicsScene(self)
        pixmap = QtGui.QPixmap(imagePath)
        pixmap = pixmap.scaled(200, 200, Qt.KeepAspectRatio)  # tọa độ ảnh
        item = QtWidgets.QGraphicsPixmapItem(pixmap)
        scene.addItem(item)
        self.graphicsViewCameraIn.setScene(scene)
        self.GetIDCard()
        
    def getImageOut(self):#Load ảnh Checkout
        fname = QFileDialog.getOpenFileName(self, 'Open file',r"<Default dir>", "Image files (*.jpg)")
        strrv = list(reversed(str(fname[0]).split("/")))
        imagePath = strrv[0]
        self.lineEditlineEditLicensePlateOut.setText(docbienso.GetLicense(imagePath))
        scene = QtWidgets.QGraphicsScene(self)
        pixmap = QtGui.QPixmap(imagePath)
        pixmap = pixmap.scaled(200, 200, Qt.KeepAspectRatio)      #250 200
        item = QtWidgets.QGraphicsPixmapItem(pixmap)
        scene.addItem(item)
        self.graphicsViewCameraOut.setScene(scene)
        
    def GetIDCard(self):
        dp=DataProvider()
        query="select min(id) as id from card where license='0'"
        para=()
        data=dp.ExecuteQuery(query)
        for row in data.fetchall():
            self.labelShowIDCard.setText(str(row.id))    #textboxIDCard
        
    def CheckIn(self):
        dp=DataProvider()
        query="insert into card (id, license,checkin,status) values (?,?,?,?)"
        checkin= datetime.datetime.now()
        self.labelShowTimeIn.setText(datetime.datetime.now().__str__())
        para=(int(self.labelShowIDCard.text()),self.lineEditLicensePlateIn.text(),checkin,1) #textboxIDCard
        dp.AddQuery(query,para)
        self.ShowMessageBox("Đã checkin")
        
    def CheckOut(self):
        dp=DataProvider()
        query="select checkin from card where license=? and id=?"
        para=(self.lineEditlineEditLicensePlateOut.text(),int(self.labelShowIDCard.text()))
        data=dp.GetTable(query,para)
        checkin=datetime.datetime.now()
        i=True
        for row in data.fetchall():
            i=False
            checkin=row.checkin
            self.labelShowTimeIn.setText(row.checkin.__str__())
        if i:
            self.ShowMessageBox("Sai thẻ xe")
            return
        query="insert into customer (checkin,checkout,license) values (?,?,?)"
        checkout= datetime.datetime.now()
        self.labelShowPaymentFees.setText(str(self.CalTime(checkin,checkout)))
        self.labelShowTimeOut.setText(checkout.__str__())
        para=(checkin,checkout,self.lineEditlineEditLicensePlateOut.text())
        dp.AddQuery(query,para)
        query="update card set license=?,status=0 where id=?"
        para=(0,self.labelShowIDCard.text())
        dp.AddQuery(query,para)
        
        
        self.ShowMessageBox("Đã checkout")
    def CalTime(self,checkin,checkout):#Tính tiền
        diff=checkin-checkout
        if(checkin.day!=checkout.day):
            return 15000
        date1=datetime.datetime(checkout.year,checkout.month,checkout.day,6,0,0)
        date2=datetime.datetime(checkout.year,checkout.month,checkout.day,18,30,0)
        date3=datetime.datetime(checkout.year,checkout.month,checkout.day,21,30,0)
        
        if((checkin-date1).total_seconds()>0 and (date2-checkout).total_seconds()>0):
            return 4000
        if((checkin-date2).total_seconds()>0 and (date2-checkout).total_seconds()>0):
            return 5000
        return 10000
    
    def ChangePassword(self):
        main=FormChangePW(self)
        main.show()
    
    def ShowMessageBox(self,error): #Tạo MessageBox thông báo lỗi
        msg=QMessageBox()
        msg.setWindowTitle("Checkin Checkout Error")
        msg.setText(error)
        msg.setIcon(QMessageBox.Information)
        x=msg.exec_()
        
    
        
class FormQLNV(QMainWindow): #Class mở form quản lý
    def __init__(self,parent=None):
        super(FormQLNV,self).__init__(parent)
        loadUi("FormQLNV.ui",self) #Load UI từ file FormQL.ui
        self.LoadData() #Load data nhân viên
        self.pushButtonReset.clicked.connect(self.LoadData) #Gán sự kiện click Refresh
        self.pushButtonAdd.clicked.connect(self.LoadAdd) #Gán sự kiện thêm nhân viên
        self.pushButtonRemove.clicked.connect(self.Remove) #Gán sự kiện Xoá nhân viên
        self.pushButtonUpdate.clicked.connect(self.Edit) #Gán sự kiện Sửa nhân viên
        self.frameGioiTinh.addItems(["Tất cả", "Nam", "Nữ"])
        self.frameChucVu.addItems(["Tất cả","Quản lý","Nhân viên","Bảo vệ"])#combobox chức vụ
        self.frameGioiTinh.currentIndexChanged.connect(self.selectionchange)#gán sự kiện khi thay đổi lựa chọ trong combo box
        self.frameChucVu.currentIndexChanged.connect(self.selectionchange)
      #  self.btnShowGraph.clicked.connect(self.ShowGraph)
    
    def ShowGraph(self):
        datefrom = datetime.datetime.strptime(self.dateEditFrom.date().toString("yyyy-MM-dd"),'%Y-%m-%d')
        dateto = datetime.datetime.strptime(self.dateEditTo.date().toString("yyyy-MM-dd"),'%Y-%m-%d')
        Show(datefrom,dateto)#Show đồ thị
    def selectionchange(self,i):#Xử lý sự kiện thay đổi lự chọn combobox
        gt=self.frameGioiTinh.currentIndex()           #comboBoxGT
        cv=self.frameChucVu.currentIndex()
        
        query2=""
        para=()
        if gt!=0:
            query2="gender=? "
            para=(gt)
        if cv!=0:
            if query2!="":
                para=(gt,cv)
                query2=query2+"and position=? "
            else:
                query2="position=?"
                para=(cv)
                
        
        if query2!="":
            query='''select name,case when gender=1 then N'Nam' else N'Nữ' end,address,cmnd,bdate,luongCB,phone,email,
                case when position=1 then N'Quản lý' else case when position=2 then N'Nhân viên' else N'Bảo vê' end end
                from employees''' +" where "+query2
        else:
            query='''select name,case when gender=1 then N'Nam' else N'Nữ' end,address,cmnd,bdate,luongCB,phone,email,
                case when position=1 then N'Quản lý' else case when position=2 then N'Nhân viên' else N'Bảo vê' end end
                from employees'''
        dp=DataProvider()
        data=dp.GetTable(query,para) #Lấy data từ SQL Server
        self.dgvNhanVien.setRowCount(0)
        for row,data_row in enumerate(data):
            self.dgvNhanVien.insertRow(row)
            for col,data_col in enumerate(data_row):
                self.dgvNhanVien.setItem(row,col,QTableWidgetItem(str(data_col)))
        
              
        
        
    def LoadAdd(self):  #Mở form thêm nhân viên
        formAdd=FormThemNhanVien(self)
        formAdd.show()
    
    def LoadData(self): #Load nhân viên vào data grid view
        dp=DataProvider()
        query='''select name,case when gender=1 then N'Nam' else N'Nữ' end,address,cmnd,bdate,luongCB,phone,email,
                case when position=1 then N'Quản lý' else case when position=2  then N'Nhân viên' else N'Bảo vê' end end
                from employees'''
        data=dp.ExecuteQuery(query) #Lấy data từ SQL Server
        self.dgvNhanVien.setRowCount(0)
        for row,data_row in enumerate(data):
            self.dgvNhanVien.insertRow(row)
            for col,data_col in enumerate(data_row):
                self.dgvNhanVien.setItem(row,col,QTableWidgetItem(str(data_col)))
                
    def Remove(self): #Xoá nhân viên
        try:
            row=self.dgvNhanVien.currentRow()  #Lấy index của row cần xoá
            item=self.dgvNhanVien.item(row,3).text()   #Lấy số CMND của nhân viên cần sa thải
            if self.ShowMessageBoxQuestion("Bạn có muốn sa thải nhân viên này"):
                dp=DataProvider()    #Khở tạo DataProvider để thực thi query
                query="delete from employees where cmnd=?"
                para=tuple(item)   #Parameter là CMND
                result=dp.DeleteQuery(query,item)
                if result:
                    self.LoadData() #Nếu thành công thì load lại data
                    self.ShowMessageBox("Xoá thành công")
                else:
                    self.ShowMessageBox("Xoá không thành công")
        except:
            self.ShowMessageBox("Xoá không thành công")
               
    def Edit(self):#Mở form Sửa thông tin nhân viên
        row=self.dgvNhanVien.selectedItems()
        EditForm=FormThemNhanVien(self,row[3].text())
        EditForm.show()
            
            
    def ShowMessageBoxQuestion(self,question):
        msg=QMessageBox()
        msg.setWindowTitle("FormQL Question")
        msg.question(self,'', question, msg.Yes | msg.No)
        if msg.Yes:
            return True
        return False
    def ShowMessageBox(self,info):
        msg=QMessageBox()
        msg.setWindowTitle("FormQL Question")
        msg.setText(info)
        

class FormThemNhanVien(QMainWindow):#Form dùng chung cho 2 việc là Add và Edit
    def __init__(self,parent=None,item=None):
        super(FormThemNhanVien,self).__init__(parent)
        loadUi("FormAdd.ui",self)
        if item == None:#Nếu ko truyền vào item thì thực hiện chức năng Add
            self.pushButtonAdd.clicked.connect(self.Add)
        else:#nếu có truyền vào item thì thực hiện chức năng Edit
            self.pushButtonAdd.setText("Edit")
            self.pushButtonAdd.clicked.connect(self.Edit)
            self.setData(item)
    
    def setData(self,item):# điền sẵn các giá trị text box cho chức năng Edit
        dp=DataProvider()
        para=(item)
        query='''select * from employees where cmnd=?'''
        data=dp.GetTable(query,para) #Lấy data từ SQL Server
        data=data.fetchone()
        self.lineEditHoTen.setText(data.name)
        self.lineEditDiaChi.setText(data.address)
        self.lineEditCMND.setText(data.cmnd)
        self.dateEditNgaySinh.setDate(data.bdate)
        self.lineEditLuongCB.setText(str(data.luongCB))  
        self.lineEditSDT.setText(data.phone)
        self.lineEditEmail.setText(str.rstrip(data.email)[:-10])  
        if data.gender==2:
            self.radioButtonNu.setChecked(True)
        if data.position==2:
            self.radioButtonNhanVien.setChecked(True)
        elif data.position==3:
            self.radioButtonBaoVe.setChecked(True)
        
        self.lineEditCMND.setReadOnly(True)
        
    def Add(self): #Thao tác thêm nhân viên
        dp=DataProvider()
        
        gender=1
        if self.radioButtonNu.isChecked()==True:
            gender=2
        
        position=2
        if self.CheckField()==False:#Kiểm tra các trường nhập
            return       #Nếu các trường có sai thì ko thực hiện thao tác
        if self.radioButtonQuanLy.isChecked():
            position=1
        if self.radioButtonBaoVe.isChecked():
            position=3
        query="insert into employees(name,bdate,gender,address,cmnd,luongCB,phone,email,position) values(?,?,?,?,?,?,?,?,?)"
        import datetime
        starttime = datetime.datetime.strptime(self.dateEditNgaySinh.date().toString("yyyy-MM-dd"),'%Y-%m-%d')
        
        parameter=(self.lineEditHoTen.text(),starttime.date(),gender,self.lineEditDiaChi.text(),self.lineEditCMND.text(),
                   int(self.lineEditLuongCB.text()),self.lineEditSDT.text(),
                   self.lineEditEmail.text()+self.labelMailText.text(),position)   #labelMailText
        result=dp.AddQuery(query,parameter)
        
        if result:
            if position==3:
                self.ShowMessageBox("Thành công")
            else:
                parameter=(self.lineEditCMND.text(),"123456",position) #tạo tk với user=cmnd, pass=12345
                query="insert into login (username,password,position) values(?,?,?)"
                result=dp.AddQuery(query,parameter)
                if result:
                    self.ShowMessageBox("Thành công")
                else: 
                    self.ShowMessageBox("Thêm tài khoản không thành công")
        else:
            self.ShowMessageBox("Thất bại. Kiểm tra lại dữ liệu nhập vào")
            
    def Edit(self): #Thao tác update lại thông tin cho nhân viên
        dp=DataProvider()
        
        gender=1
        if self.radioButtonNu.isChecked()==True:
            gender=2
            
        position=2
        if self.CheckField()==False:#Kiểm tra các trường nhập trống/sai định dạng
            return
        if self.radioButtonQuanLy.isChecked():
            position=1
        if self.radioButtonBaoVe.isChecked():
            position=3
        query="update employees set name=?,gender==?,bdate=?,address=?,luongCB=?,phone=?,email=?,position=? where cmnd=?"
        import datetime
        starttime = datetime.datetime.strptime(self.dateEditNgaySinh.date().toString("yyyy-MM-dd"),'%Y-%m-%d')
        parameter=(self.lineEditHoTen.text(),starttime.date(),gender,self.lineEditDiaChi.text(),
                   int(self.lineEditLuongCB.text()),self.lineEditSDT.text(),
                   self.lineEditEmail.text()+self.labelMailText.text(),position,self.lineEditCMND.text())
        result=dp.AddQuery(query,parameter)
        
        if result:
            if position==3:
                query="delete from login where username=?"
                result=dp.AddQuery(query,tuple(self.lineEditCMND.text()))
                self.ShowMessageBox("Sửa thông tin nhân viên thành công")
            else:
                parameter=(position,self.lineEditCMND.text()) #tạo tk với user=cmnd, pass=12345
                query="update login set position=? where username=?"
                result=dp.AddQuery(query,parameter)
                if result:
                    self.ShowMessageBox("Sửa thông tin nhân viên thành công")
                else: 
                    self.ShowMessageBox("Sửa thông tin nhân viên không thành công")
        else:
            self.ShowMessageBox("Lỗi: Sửa thông tin nhân viên không thành công")
                
    def CheckField(self):
        if self.lineEditHoTen.text()=="" or self.lineEditDiaChi.text()=="" or self.lineEditCMND.text()=="" or self.lineEditLuongCB.text()=="" or self.lineEditSDT.text()=="" or self.lineEditEmail.text()=="":
            self.ShowMessageBox("Vui lòng điền đầy đủ thông tin")  
            return False
        
        starttime = datetime.datetime.strptime(self.dateEditNgaySinh.date().toString("yyyy-MM-dd"),'%Y-%m-%d')
        if((datetime.datetime.now()-starttime).days/365<18):
            self.ShowMessageBox("Không đủ tuổi làm việc. Vui lòng kiểm tra lại")
            return False
        if self.lineEditSDT.text().isdigit()==False:
            self.ShowMessageBox("Số điện thoại không được chứa kí tự. Vui lòng nhập lại")
            return False
        if self.lineEditCMND.text().isdigit()==False:
            self.ShowMessageBox("Số CMND không được chứa kí tự. Vui lòng nhập lại")
            return False
        return True
        
    def ShowMessageBox(self,error):
        msg=QMessageBox()
        msg.setWindowTitle("FormQL Error")
        msg.setText(error)
        msg.setIcon(QMessageBox.Information)
        x=msg.exec_()
            

class FormChangePW(QMainWindow):
    def __init__(self,parent=None):
        super(FormChangePW,self).__init__(parent)
        loadUi("FormChangePassword.ui",self)
        self.pushButtonSubmit.clicked.connect(self.Comfirm)
        
    def Comfirm(self):
        dp=DataProvider() #Lớp DataProvider để thực hiện các query       
        query="select * from login where username=? and password=?"
        
        parameter=(self.lineEditCMND.text(),self.lineEditCurrentPassword.text())
        result=dp.ExecuteNonQuery(query,parameter)
        if result>0 :
            query="update login set password=? where username=?"
            parameter=(self.lineEditLicensePlateIn.correlation.text(),self.lineEditCMND.text())
            result=dp.AddQuery(query,parameter)
            if result>0:
                self.ShowMessageBox("Đổi mật khẩu thành công")
            else:
                self.ShowMessageBox("Error")
        else:
            self.ShowMessageBox("Sai mật khẩu hoặc tên đăng nhập")
            
    def ShowMessageBox(self,mess):
        msg=QMessageBox()
        msg.setWindowTitle("Change PassWord")
        msg.setText(mess)
        msg.setIcon(QMessageBox.Information)
        x=msg.exec_()



app=QApplication(sys.argv)
mainwindow=Login()
mainwindow.show()
app.exec_()
# %%
