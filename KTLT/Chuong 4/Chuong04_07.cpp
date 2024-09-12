#include<stdio.h>
#include<string.h>

int tinh(char a[])
{
	int d=0;
	int b=strlen(a);	
	for(int i=0;i<b;i++)
	{
		if(a[i]>=48 && a[i]<=57)
		{	int c=0;
			c=c+(a[i]-48);
			a[i]-=a[i];
			int j=i+1;
			while(a[j]>=48 && a[j]<=57)
			{
				c=c*10+(a[j]-48);
				a[j]-=a[j];
				j++;
			}
			d+=c;
		}
	}
	return d;
}

int main()
{
	char a[100];
	fflush(stdin);
	gets(a);
	int kq=tinh(a);
	printf("%d",kq);
	return 0;
}
