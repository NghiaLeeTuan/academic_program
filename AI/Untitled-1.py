#%%
def covariance(x, y):
    # Finding the mean of the series x and y
    mean_x = sum(x)/float(len(x))
    mean_y = sum(y)/float(len(y))
    # Subtracting mean from the individual elements
    sub_x = [i - mean_x for i in x]
    sub_y = [i - mean_y for i in y]
    numerator = sum([sub_x[i]*sub_y[i] for i in range(len(sub_x))])
    std_deviation_x = sum([sub_x[i]**2.0 for i in range(len(sub_x))])
    cov = numerator/std_deviation_x
    print('c=',mean_y-cov*mean_x)
    return cov

x=[10,15,10,15,20,5,10,15,20,15,15,10,5,12,22,14,16,18,30,14]
y=[70,65,66,60,50,72,67,60,55,60,70,72,75,70,52,54,52,50,45,60]
print('m=',covariance(x,y))

# %%

# %%
