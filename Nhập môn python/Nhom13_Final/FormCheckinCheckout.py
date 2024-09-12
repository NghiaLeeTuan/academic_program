import sys
from PyQt5 import QtWidgets, uic
from PyQt5.uic import  loadUi
from PyQt5.QtWidgets import *

class CheckinCheckout(QMainWindow):
    def __init__(self):
        super(CheckinCheckout, self).__init__() 
        loadUi("FormCheckinCheckout.ui", self)  #Load UI từ file LoginForm.ui

        self.pushButtonOpenIn.clicked.connect(self.pushButtonOpenIn_Clicked)
        self.pushButtonOpenOut.clicked.connect(self.pushButtonOpenOut_Clicked)
        self.pushButtonCheckIn.clicked.connect(self.pushButtonCheckIn_Clicked)
        self.pushButtonCheckOut.clicked.connect(self.pushButtonCheckOut_Clicked)
        self.pushButtonChangePassword.clicked.connect(self.pushButtonChangePassword_Clicked)
        self.pushButtonExit.clicked.connect(self.pushButtonExit_Clicked)
        self.pushButtonLogin.clicked.connect(self.pushButtonLogin_Clicked)


    def pushButtonOpenIn_Clicked(self):
        self.a = "dkkd"

    ### Load ảnh Checkout
    def pushButtonOpenOut_Clicked(self):
        print("slsll")

    def pushButtonCheckIn_Clicked(self):
        print("slsll")

    def pushButtonCheckOut_Clicked(self):
        print("slsll")

    def pushButtonChangePassword_Clicked(self):
        from FormChangePassword import ChangePassword
        self.mainwindow = ChangePassword()
        self.mainwindow.show()
    
    def pushButtonExit_Clicked(self):
        self.reply = QMessageBox.question(self, "Window Close", "Are you sure you want to close the window?", QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if self.reply == QMessageBox.Yes:
            self.close()

    def pushButtonLogin_Clicked(self):
        import Login
        self.mainwindow = Login()
        self.mainwindow.show()

        self.close()