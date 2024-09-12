import sys
from PyQt5 import QtWidgets, uic
from PyQt5.uic import  loadUi
from PyQt5.QtWidgets import *

class ChangePassword(QMainWindow):
    def __init__(self):
        super(ChangePassword, self).__init__() 
        loadUi("FormChangePassword.ui", self)  #Load UI từ file LoginForm.ui

        self.pushButtonSubmit.clicked.connect(self.pushButtonSubmit_Clicked)
    
    def pushButtonSubmit_Clicked(self):
        if (self.lineEditCMND.text() == "123456") and (self.lineEditCurrentPassword.text() == "123456"):
            if self.lineEditNewPassword.text() == self.lineEditConfirmPassword.text():
                print("Thay đổi mk vào data base")
                self.showInformation("Change password successfully!!!")
                self.close()
            else:
                self.showError("Confirmation password is not correct!!!")
                self.lineEditConfirmPassword.setText("")
        else:
            self.showError("CMND/CCCN does not exist or Password does not exist!!!")
            self.lineEditCMND.setText("")
            self.lineEditCurrentPassword.setText("")

    def showInformation(self, information):
        self.msg = QMessageBox()
        self.msg.setIcon(QMessageBox.Information)

        self.msg.setText(information)
        self.msg.setWindowTitle("Thông báo!")
        self.msg.setStandardButtons(QMessageBox.Ok)
        retval = self.msg.exec_()

    def showError(self, error):
        self.msg = QMessageBox()
        self.msg.setIcon(QMessageBox.Warning)

        self.msg.setText(error)
        self.msg.setWindowTitle("Thông báo!")
        self.msg.setStandardButtons(QMessageBox.Yes)
        retval = self.msg.exec_()