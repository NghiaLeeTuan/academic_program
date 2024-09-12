#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int checksnt(int n)
{	int i;
    int dem = 0;
    
    if(n!=1)
    {
    	for( i= 1; i <= n; i++)
    	{
        if( n % i == 0)
            dem++;
    	}
    	if(dem == 2)
        	return 1;
	}
	else 
    	return 0;
}
int checksdx(int n)
{
	int r,sum=0,temp;
    for( temp=n ; n!=0 ; n=n/10){
         r=n%10;
         sum=sum*10+r;
    }
    if(temp==sum)
         return 1;
    else
         return 0;
}


int main()
{
	int n,i,temp,r;
	int sum=0;
	cout << "Nhap N: ";
	cin>>n;
	
	for(int i = 1; i <= n ;i++)
    {
        if((checksnt(i)==1) && (checksdx(i)==1))
            cout << i << " ";
    }
}
