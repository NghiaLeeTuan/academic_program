#%% Bai 01 
from matplotlib import cm
import matplotlib.pyplot as ppt
import numpy as np
x=np.linspace(-2,2,20)
y=np.linspace(-2,2,20)
#e=np.exp(1) #co so e
x,y=np.meshgrid(x,y)
#z=x*e**(-x*x-y*y)     
fg=ppt.figure()
dt=fg.gca(projection='3d')  
dt.plot_surface(x,y,cmap=cm.inferno)  #tao bieu do
dt.set_xlabel('Ox') #nhan cot Ox
dt.set_ylabel('Oy') #nhan cot Oy
#dt.set_zlabel('Oz') #nhan cot oz
#dt.set_title('z(x,y)=x*e^(-x^2-y^2)')   #ten bieu do``
ppt.show()
# %% Cau 4
import sympy as sp
from sympy.abc import x, y, z, u, v
print("pt1: ",sp.solveset(sp.Eq(5*x**2+6*2-37)))
print("pt2: ",sp.solveset(sp.Eq(2*x**3-x)))
print("pt3 theo x: ",sp.solveset(sp.Eq(u*x**2+v*x),x))
print("pt3 theo u: ",sp.solveset(sp.Eq(u*x**2+v*x),u))
print("pt3 theo v: ",sp.solveset(sp.Eq(u*x**2+v*x),v))

# %% Cau 6
import sympy as sp
print("Dao ham theo x: ",sp.diff(sp.sin(u*x)*sp.cos(v*x),x))
print("Dao ham theo bac 2 x: ",sp.diff(sp.sin(u*x)*sp.cos(v*x),x,x))
print("Dao ham theo u: ",sp.diff(sp.sin(u*x)*sp.cos(v*x),u))
# %%
import pandas as pd
data = pd.read_csv('D:\AI_Example.csv')
print('DATA INFO')
print(data.info())
#%%head()
print('DATA HEAD')
print(data.head(5))
#%% describe()
print('DATA DESCRIBE')
print(data.describe())
#%% iloc()
print(data.iloc[:,:1]) #collumn
print(data.iloc[[0]]) #row
print(data.loc[[1],['Units']])
# %%
data['UnitCost'].plot()
