#%%
import sys
from PyQt5.uic import  loadUi
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import *

class QuanLy(QMainWindow):

    def __init__(self):
        super(QuanLy, self).__init__() 
        loadUi("FormQuanLy.ui", self)  #Load UI từ file LoginForm.ui

        self.pushButtonQLNV.clicked.connect(self.pushButtonQLNV_Clicked)
        self.pushButtonChangePassword.clicked.connect(self.pushButtonChangePassword_Clicked)
        self.pushButtonExit.clicked.connect(self.pushButtonExit_Clicked)
        self.pushButtonLogin.clicked.connect(self.pushButtonLogin_Clicked)

    def pushButtonQLNV_Clicked(self):
        from FormQLNV import QLNV
        self.mainwindow = QLNV()
        self.mainwindow.show()

    def pushButtonChangePassword_Clicked(self):
        from FormChangePassword import ChangePassword
        self.mainwindow = ChangePassword()
        self.mainwindow.show()

    def pushButtonExit_Clicked(self):
        self.reply = QMessageBox.question(self, "Window Close", "Are you sure you want to close the window?", QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if self.reply == QMessageBox.Yes:
            self.close()
    
    def pushButtonLogin_Clicked(self):
        from Login import Login
        self.mainwindow = Login()
        self.mainwindow.show()

        self.close()
# %%
