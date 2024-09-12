#include<stdio.h>
#include<math.h>
struct diem{
	float x;
	float y;
};
typedef struct diem DIEM;

void nhap(DIEM &A, DIEM &B){
	printf("\n\n\t\tNhap diem thu nhat: ");
	printf("\nNhap x: ");
	scanf("%f", &A.x);
	printf("Nhap y: ");
	scanf("%f", &A.y);
	
	printf("\n\n\t\tNhap diem thu 2: ");
	printf("\nNhap x: ");
	scanf("%f", &B.x);
	printf("Nhap y: ");
	scanf("%f", &B.y);
}

void xuat_diem_doi(DIEM A, DIEM B){
	printf("\n\n\t\tCac diem doi xung diem thu nhat: ");
	printf("\nQua truc tung: ");
	printf("(%g; %g)", (-A.x), A.y);
	printf("\nQua truc hoanh: ");
	printf("(%g; %g)", A.x, (-A.y));
	printf("\nQua tam: ");
	printf("(%g; %g)", -A.x, -A.y);
	
	printf("\n\n\t\tCac diem doi xung diem thu 2: ");
	printf("\nQua truc tung: ");
	printf("(%g; %g)", -B.x, B.y);
	printf("\nQua truc hoanh: ");
	printf("(%g; %g)", B.x, -B.y);
	printf("\nQua tam: ");
	printf("(%g; %g)", -B.x, -B.y);
}

float khoang_cach(DIEM A, DIEM B){
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

void tinh_toan(DIEM A, DIEM B){
	printf("\n\n\t\tTINH TOAN");
	printf("\nToa do tong 2 diem: ");
	printf("(%g; %g)", A.x+B.x, A.y+B.y);
	
	printf("\nToa do hieu 2 diem: ");
	printf("(%g; %g)", A.x-B.x, A.y-B.y);
	
	printf("\nToa do tich 2 diem: ");
	printf("(%g; %g)", A.x*B.x, A.y*B.y);
	
	float d = khoang_cach(A, B);
	printf("\nKhoang cach 2 diem: ");
	printf("%g", d);
}

int main(){
	DIEM A, B;
	nhap(A, B);
	xuat_diem_doi(A, B);
	tinh_toan(A, B);
return 0;	
}


