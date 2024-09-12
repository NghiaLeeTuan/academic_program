#include<stdio.h>
#include<math.h>

void nhap(int a[],int &n)
{
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
int ktra(int a)
{
   int count = 0;
    for(int i = 2; i < a; i++){
        if(a % i == 0){
            count++;
        }
    }
    if(count == 0){
        return 1;
    }else{
        return 0;
    }
}

int tim(int a[],int n)
{
	int b[100];
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(ktra(a[i])==1 && a[i] > 1)
		{
			b[j]=a[i];
			j++;
		}
	}
	int min=b[0];
	for(int e=1;e<j;e++)
	{
		if (b[e]<min)
		min=b[e];
	}
	return min;
}

void xuat(int x)
{
	printf("%d",x);
}


int main()
{
	int a[100],n;
	nhap(a,n);
	int x=tim(a,n);
	xuat(x);
	return 0;
}
