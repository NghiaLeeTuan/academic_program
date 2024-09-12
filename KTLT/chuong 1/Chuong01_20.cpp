#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define sz 10412

bool x_chua_xh(int *arr, int n, int x) {
	for(int i = 0; i < n; i++) {
		if(arr[i] == x) {
			return false;
		}
	}
	return true;
}

void nhap(int *arr, int *n){ 
	*n = 10000;
	
	int i=0;
	srand((int) time(0));
	while(i < *n){
		int x = rand();
		if(x_chua_xh(arr, i, x)){
			arr[i++] = x;
		}
	}
}

void xuat(int *arr, int n){
	FILE *fo;
	fo = fopen("SONGUYEN.INP","wt");
	if(fo == NULL){
		printf("KHONG GHI DUOC FILE");
		exit(0);
	}
	if(fo == NULL){
		printf("KHONG GHI DUOC FILE");
		exit(0);
	}
	
	for(int i=0; i<n; i++){
		fprintf(fo, "%d ", arr[i]);	
	}
	fclose(fo);
}

int main() {
	int n;
	int arr[sz];
	nhap(arr, &n);
	xuat(arr, n);
return 0;
}
