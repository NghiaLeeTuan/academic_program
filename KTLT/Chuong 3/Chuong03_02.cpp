#include<iostream>
using namespace std;

int nhap(int a[])
{
    int n;
    cout<<"so phan tu trong mang: ";
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    return n;
}
void xuat(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}
void sapxep(int a[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
            if(a[i]<a[j])
            {temp=a[i];
            a[i]=a[j];
            a[j]=temp;}    
    }
    xuat(a,n);
}
void chen(int a[],int n)
{
    int x;
    cout<<"nhap phan tu can chen: ";
    cin>>x;
    for(int i=0;i<n;i++)
    {
        if(a[i]>x && a[i+1]<x)
        {
            n++;
            for(int j=n-1;j>i;j--)
            {
                a[j]=a[j-1];
            }
            a[i+1]=x;
        }
    }
    xuat(a,n);
}

int main()
{
    int a[100];
    int n=nhap(a);
    sapxep(a,n);
    chen(a,n);
    return 0;
}