#include<bits/stdc++.h>
#include<iostream>
#define N 100
using namespace std;

int cal(int n, int a, int k)
{
	int A[N];
	A[1]=1;
	for(int i=2;i<=n;i++)
	{
		if (i%2==1)
			A[i]=pow(i,k);	
		else
		A[i]=a*A[i/2] + pow(i,k);
	}
	return A[n];
}

int main()
{
	int n;
	int a,k;
	cout << "Nhap n: ";
	cin >> n;
	 cout << "Nhap a: ";
	 cin >> a;
	 cout << "Nhap k: ";
	 cin >> k;
	int T =cal(n,k,a);
	 
	 cout << "T(n)= " << T;
}
