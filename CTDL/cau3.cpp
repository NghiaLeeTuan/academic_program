#include<stdio.h>
#include<math.h>

struct sophuc
{
	int thuc;
	int ao;
};

void cal(sophuc a,sophuc b)
{
	printf("phan thuc a: ");
	scanf("%d",&a.thuc);
	printf("phan ao a: ");
	scanf("%d",&a.ao);
	printf("so phuc a : %d + %di \n",a.thuc,a.ao);
	printf("phan thuc b: ");
	scanf("%d",&b.thuc);
	printf("phan ao b: ");
	scanf("%d",&b.ao);
	printf("so phuc b : %d + %di \n",b.thuc,b.ao);
		//tinh tong
	sophuc c;
	c.ao=a.ao+b.ao;
	c.thuc= a.thuc+b.thuc ;
	printf("tong la: %d + %di\n",c.thuc,c.ao);
	
		//tinh hieu
	sophuc d;
	d.ao=a.ao-b.ao;
	d.thuc=a.thuc-b.thuc;
	printf("hieu la: %d + %di\n",d.thuc,d.ao);
		
		//tich
	sophuc e;
	e.thuc=a.thuc*b.thuc-a.ao*b.ao;
	e.ao=a.thuc*b.ao+b.thuc*a.ao;
	printf("tich la: %d + %di\n",e.thuc,e.ao);	
	
		//thuong
	float f,g;
	f=(float(a.thuc*b.thuc+a.ao*b.ao))/(a.thuc*a.thuc+a.ao*a.ao);
	g=(float(a.thuc*b.ao-b.thuc*a.ao))/(a.thuc*a.thuc+a.ao*a.ao);
	printf("thuong b/a la: %.2f + %.2fi\n",f,g);
	
		//binh phuong
	sophuc h; 
    h.thuc = pow(a.thuc,2) - pow(a.ao,2);
    h.ao = 2*a.thuc*a.ao;
    printf("Binh Phuong a: ");
    printf("%d + %di\n",h.thuc,h.ao);

    h.thuc = pow(b.thuc,2) - pow(b.ao,2);
    h.ao = 2*b.thuc*b.ao;
    printf("Binh Phuong b: ");
    printf("%d + %di\n",h.thuc,h.ao);
	
}

int main()
{	
	sophuc a,b;
	cal(a,b);
	return 0;
}
