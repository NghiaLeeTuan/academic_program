#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    fflush(stdin);
    gets(s);
    int count[122] = {0};
    int n=strlen(s);
    for(int i=0;i<n;i++)
	{
    	if(!count[s[i]])
		{
	    count[s[i]]=1;
	    for(int j=i+1;j<n;j++)
		if(s[j]==s[i])
		    count[s[i]]++;
	    }
	}
    for(int i=65;i<122;i++)
        if(count[i])
            printf("%c %d\n",i,count[i]);
    return 0;
}
