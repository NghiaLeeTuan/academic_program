#include<stdio.h>
#include<conio.h>
void Nhap(int a[],int N){
   int i;
   for (i=0;i<N;i++){
      scanf("%d",&a[i]);
   }
}
void Xuat(int a[],int N){
   int i;
   for (i=0;i<N;i++)
      printf("%5d ",a[i]);
   printf("\n");
}

void Xoatrung(int a[],int *N){
   int i,j,k;
   for (i=0;i<(*N)-1;i++){
    j=i+1;
    while (j<*N)
      if (a[i]==a[j]){
         for (k=j;k<(*N)-1;k++) a[k]=a[k+1];
         *N=(*N)-1;
      }
      else j=j+1;
   }
}
int main(){
   int a[100], N;
   printf("Mang co bao nhieu phan tu ");scanf("%d",&N);
   Nhap(a,N);
   Xoatrung(a,&N);
   Xuat(a,N);
   return 0;
}
