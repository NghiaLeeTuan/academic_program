#include <bits/stdc++.h>
#include<queue> 
#define Max 5 
 
struct Queue
{
    int Front, Rear; //front: phan tu dau hang, rear: phan tu cuoi hang
    int Data[Max]; 
    int count; //so phan tu cua Queue
};

void Init (Queue &Q) //khoi tao Queue rong
{
    Q.Front = 0; 
    Q.Rear = -1; 
    Q.count = 0; 
}
 
int Isempty (Queue Q) //kiem tra Queue rong
{
    if (Q.count == 0) 
        return 1;
    return 0;
}
 
int Isfull (Queue Q) //kiem tra Queue day
{
    if (Q.count == Max)
        return 1;
    return 0;
}

void Enqueue(Queue &Q, int x) //them phan tu vao cuoi hang doi vong
{
    if (Isfull(Q)) printf("Hang doi day !");
    else
    {
        Q.Data[(++Q.Rear) % Max] = x; 
        Q.count++; //tang so phan tu len
    }
}
 
int Dequeue(Queue &Q) //Loai bo phan tu khoi dau hang doi vong
{
	int x;
    if (Isempty(Q)) printf("Hang doi rong !");
    else{
    x=Q.Data[Q.Front];
    Q.Data[Q.Front]=Q.Data[(Q.Front++)%Max];
    Q.Front=(Q.Front++) % Max;
	Q.count--;
    }
    return x;
}
 
 
void Input (Queue &Q) //nhap hang doi
{
    int n;
    int x;
    do
    {
        printf("Nhap so phan tu cua Queue (<=%d) :",Max);
        scanf("%d",&n);
    } while (n>Max || n<1);
    for (int i=0; i<n; i++)
    {
        printf("Nhap phan tu thu %d : ", i+1);
        scanf("%d",&x);
        Enqueue(Q,x);
    }
}
 
void Output(Queue Q)
{
    if (Isempty(Q)) 
		printf("Hang doi rong !");
    else
    {
        for (int i=Q.Front, j=0; j<Q.count; j++, i = i % Max) 
            {printf("%5d",Q.Data[i]);
				i++; }
        printf("\n");
    }
}
 
int main()
{
    Queue Q;
    Init(Q);
    Input(Q);
    Output(Q);
 
    int c;

    do
    {
    	printf("\n1: Kiem tra Queue rong");
    	printf("\n2: Kiem tra Queue day");
    	printf("\n3: Them phan tu vao Queue");
   		printf("\n4: Xoa phan tu trong Queue");
    	printf("\n5: Xuat Queue");
    	printf("\n6: Thoat");
        printf("\nBan chon: ");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
            {	  		system("cls");
                if (Isempty(Q)) printf("Queue rong !");
                else printf ("Queue khong rong !");
                break;
            }
            case 2:
            {	  		system("cls");
                if (Isfull(Q)) printf("Queue day !");
                else printf ("Queue chua day !");
                break;
            }
            case 3:
            {	  		system("cls");
                int x;
                printf ("Nhap phan tu can chen vao Queue: ");
                scanf("%d",&x);
                Enqueue(Q,x); 
                break;
            }
            case 4:
            {	  		system("cls");
                Dequeue(Q);
                break;
            }
            case 5: 
            {	  		system("cls");
                Output(Q);
                break;
            }
            case 6: break;
            default: printf("\nNhap sai, Vui long nhap lai !!");
        }
    }while (c !=6);
    return 0;
}
