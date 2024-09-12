#include<stdio.h> 


void xetsutang(int A[],int n);
void xuat (int B[],int nB);

int main()
{
	int A[100],n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
	xetsutang(A,n);
	return 0;
}
int tinhtong(int B[],int nB)
{
	int tong=0;
	for (int i=0;i<nB;i++)
		tong+=B[i];
	return tong;
}
void xetsutang(int A[],int n)
{
	int B[100]={0};
	int C[100]={0};
	int nB=0;
	int max=0;
	bool a=false;
	int t,nC;
	for (int i=0;i<n;i++)
	{
		t=A[i];
		if (t<A[i+1])
		{
			if (a==false)
			{
				a=true;
				B[nB++]=t;
			}
			else
				B[nB++]=t;
		}
		else
		{
			if (a==true)
			{
				B[nB++]=t;
				a=false;
				int tong=tinhtong(B,nB);
				if (tong>max)
				{
					max=tong;
					nC=0;
					for (int j=0;j<nB;j++)
						C[nC++]=B[j];
				}
				nB=0;
			}
		}
	}
	xuat(C,nC);
}
void xuat (int B[],int nB)
{
	for (int i=0;i<nB;i++)
		printf("%d ",B[i]);
	printf("\n");
}
