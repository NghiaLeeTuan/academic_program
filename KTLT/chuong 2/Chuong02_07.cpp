#include<stdio.h>
#include<string.h>

void nhap(char a[])
{
	fflush(stdin);
	gets(a);
}
void xuat(char a[])
{
	puts(a);
}

void charge(char a[])
{
	a[0]=a[0]-32;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]==' ')
		{
			a[i+1]=a[i+1]-32;
		}
	}
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]==' ')
		{
			for(int j=i;j<strlen(a);j++)
			a[j]=a[j+1];
		}
	}
}

int main()
{
	char a[100];
	nhap(a);
	charge(a);
	xuat(a);
	return 0;
}
