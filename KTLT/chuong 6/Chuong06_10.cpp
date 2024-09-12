#include<stdio.h>
#include<string.h>


int main()
{
	char a[100];
	char b[100];
	fflush(stdin);
	gets(a);
	int n=strlen(a);
	int c=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=' ' && a[i]!= NULL)
		{
			b[c]=a[i];
			c++;
		}
		if(a[i]==' ' )
		{
			b[c]=NULL;
			printf("%s ", strrev(b));
			c=0;
		}
		if(i==n-1)
		{
			b[c]=NULL;
			printf("%s", strrev(b));
			c=0;
		}
		
	}
	return 0;
}
