#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define sz 100

void wfile(){
	FILE *fw;
	fw = fopen("SOCHAN.DAT", "w+");
	int x = 0;
	for (int i = 0; i <= 50; i++){
		fprintf(fw, "%d ", x);
		x += 2;
	}
	fclose (fw);
}

void rfile(){
	FILE *fw;
	fw = fopen("SOCHAN.DAT", "r+");
	int x;
	int d=0;
	int i = 0;
	while(x<100)	{
		d++; 
		fscanf(fw, "%d", &x);
		printf("%d ", x);
		if(d % 30 == 0)
		printf("\n");
		i++;
	}
	fclose (fw);		
}

int main(){
	wfile();
	rfile();
return 0;	
}
