#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<time.h>
#include<stdlib.h>
#define N 100
/*
void checkinput(int a[][N], int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{printf("%5d",a[i][j]);}
		printf("\n");
	}
	printf("==================================================\n");
}
*/

int r(int min, int max){return min + rand() % (max + 1 - min);}

void printa(int a[][N], int Top, int Bot, int Left, int Right)
{
    for (int i = Top; i <= Bot; i++)
    {
        for (int j = Left; j <= Right; j++)
        {
            printf("%5d",a[i][j]);

        }
        printf("\n");
    }
}

int solve(int* arr, int* begin, int* end, int n)
{
    int sum = 0, maxSum = INT_MIN, i;
    *end = -1;
    int rebegin = 0;
    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            rebegin = i+1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *begin = rebegin;
            *end = i;
        }
    }

    if (*end != -1)
        return maxSum;

    maxSum = arr[0];
    *begin = *end = 0;

    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            *begin = *end = i;
        }
    }
    return maxSum;
}

void find(int a[][N],int n)
{
    int maxSum = INT_MIN, releft, reright, retop, rebot, left, right, i, t[N], sum, begin, end;

    for (left = 0; left < n; ++left) {
        memset(t, 0, sizeof(t));

        for (right = left; right < n; right++)
        {

            for (i = 0; i < n; i++)
                t[i] += a[i][right];

            sum = solve(t, &begin, &end, n);

            if (sum > maxSum)
            {
                maxSum = sum;
                releft = left;
                reright = right;
                retop = begin;
                rebot = end;
            }
        }
    }

    printa(a, retop, rebot, releft, reright);
}



int main()
{
	int n;
	int a[N][N];
	int min, max;
	
	// gia tri khoi tao ngau nhien tu min-->max
	
	printf("Enter n: ");
	scanf("%d",&n);
	srand ( time(NULL) );
	printf("Enter the value range(Example: 20 50): ");
	scanf("%d%d",&min,&max);
	for(int i=0;i<n;i++)
	{for(int j=0;j<n;j++)
	a[i][j]=r(min,max);}
	
		
//	checkinput(a,n);
	
	find(a,n);
	
	return 0;
}
