#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<time.h>
#include<stdlib.h>
#define N 100

void checkinput(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%5d",a[i]);
	}
}

int r(int min, int max){return min + rand() % (max + 1 - min);}

void Printmenu()
{
	printf ("\n+------------CHON MENU---------+");
	printf ("\n|  0.Kiem tra lai du lieu vao  |");
	printf ("\n|        1.Selection sort      |");
	printf ("\n|        2.Insertion sort      |");
	printf ("\n|         3.Bubble sort        |");
	printf ("\n|         4.Merger sort        |");
	printf ("\n|         5.Quick sort         |");
	printf ("\n|       Nhap 'h' de thoat      |");
	printf ("\n================================");
}

void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
//selection sort
void SELECTION(int a[],int n)
{
	int i,j,min;
	bool temp=false;
	printf("\nTang dan theo SECLECTION SORT: \n");
	for(i=0;i<n;i++)
	{
		temp=false;
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
				{min=j;
				temp=true;}
		}
		swap(a[i],a[min]);
		checkinput(a,n);
		printf("\n");
		if(temp==false)
		{	break;}
	}
}
//Insertion sort
void INSERT(int a[], int n)
{
   int i, j;
   printf("\nGiam dan theo INSERTION SORT: \n");
for(int i = 0; i<n-1; i++)
   {
      for(int j = i+1; j>0; j--)
      if(a[j] > a[j-1])
        {swap(a[j],a[j-1]);}
       checkinput(a,n);
       printf("\n");
   }
}
//Merge sort
void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {    L[i] = a[l + i];		printf("%5d",L[i]);}
    printf("\n");
    for (j = 0; j < n2; j++)
    {    R[j] = a[m + 1+ j];	printf("%5d",R[j]);}
	printf("\n");	
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void MERGE(int a[], int l, int r)
{

    if (l < r)
    {
        int m = l+(r-l)/2;

        MERGE(a, l, m);
        MERGE(a, m+1, r);
 
        merge(a, l, m, r);
            
    	checkinput(a,r+1);
		printf("\n");
	}
}

//bubble sort
void BUBBLE(int a[], int n)
{
	printf("\nTang dan Bubble sort: \n");
    int i, j;
    bool temp = false;
    for (i = 0; i < n-1; i++){
        temp = false;
        for (j = 0; j < n-i-1; j++){
            if (a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                temp = true; 
            }
        }
        checkinput(a,n);
		printf("\n");
        if(temp == false)
            break;
    }
}

// Quick sort
int partition (int a[], int low, int high)
{
    int temp = a[high];    
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && a[left] < temp) left++;
        while(right >= left && a[right] > temp) right--;
        checkinput(a,high+1);
		printf("\n");
        if (left >= right) break;
        swap(a[left], a[right]);

        left++;
        right--;
    }
    swap(a[left], a[high]);
        checkinput(a,high+1);
		printf("\n");
    return left;
}

void QUICK(int a[], int low, int high)
{
    if (low < high)
    {

        int temp = partition(a, low, high);

        QUICK(a, low, temp - 1);

        QUICK(a, temp + 1, high);

    }

}




int main()
{
	int n;
	int a[N],b[N];
	char c;
	// gia tri khoi tao ngau nhien tu -50->50
	
	printf("Enter n: ");
	scanf("%d",&n);
	srand ( time(NULL) );
	for(int i=0;i<n;i++)
	{a[i]=r(-50,50);}
	checkinput(a,n);
	for(int i=0;i<n;i++)
	{b[i]=a[i];}
	scanf("%c",&c);


do{
		Printmenu()	;
		printf("\nNhap lua chon cua ban: ");
		scanf("%c",&c);

		if(c=='0'){	printf("\nDu lieu ban dau: \n");
		for(int i=0;i<n;i++)	printf("%5d",b[i]);}
		else if(c=='1'){		system("cls");
	 		SELECTION(a,n);}
	 	else if(c=='2'){		system("cls");
			INSERT(a,n);}
		else if(c=='3'){		system("cls");
			BUBBLE(a,n);}
		else if(c=='4'){		system("cls");		printf("\nGiam dan theo MERGE SORT: \n");
			MERGE(a,0,n-1);}
		else if(c=='5'){		system("cls");
			QUICK(a,0,n-1);	}
		else if(c=='h'){	printf("\nAn phim bat ky de thoat!!\n");
			break;}
		else {	system("cls");
		printf("\nKHONG CO LUA CHON, VUI LONG NHAP LAI!!\n");}
		scanf("%c",&c);

	}while(true);

	
	
	return 0;
}
