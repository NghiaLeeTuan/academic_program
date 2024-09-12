#%%
import sys
from PyQt5.uic import  loadUi
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import *

class QLNV(QMainWindow):

    def __init__(self):
        super(QLNV, self).__init__() 
        loadUi("FormQLNV.ui", self)  #Load UI từ file LoginForm.ui
        
# %%
