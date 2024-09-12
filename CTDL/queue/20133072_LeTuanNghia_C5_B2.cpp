#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *next;
    int data;
};

struct Queue{
    Node *head, *tail;
};

//khoi tao Queue
void Init( Queue &q ){
    q.head = q.tail = NULL;
}

//khoi tao node
Node *createNode( int x ){
    Node *p = new Node;
    if(p==NULL){
		return p;}
    p->next = NULL;
    p->data = x;
    return p;
}

int isEmpty(Queue q){
	if(q.head == NULL)
		return 1;
	else 
		return 0;
}

//them vao cuoi hang doi
void Push(Queue &q, Node *p ){
    if(!q.head) 
		q.head = q.tail = p;
    else{
        q.tail->next = p;
        q.tail = p;
    }
}

// xoa phan tu dau hang doi
int Pop(Queue &q ){
	if(isEmpty(q))	cout<<"Hang doi trong!!";
    if(q.head){
        Node *p = q.head;
        q.head = q.head->next;
        return p->data;
        delete p;
    }
    return 0;
}

//nhap 1 gia tri them vao cuoi
void nhap1(Queue &q ){
    int x;
 	cout<<"Nhap so phan tu can dua vao Queue: ";
    cin>> x;
    Node *p = createNode(x);
    Push(q,p);

}

//nhap gia tri ban dau
void nhap(Queue &q ){
    int n, x;
 	cout<<"Nhap so phan tu cua Queue: ";
    cin>> n;
    for (int i=0; i<n; i++)
    {
    	cout<<"\nNhap phan tu thu "<< i+1 <<" : ";
    	cin>>x;
        Node *p = createNode(x);
        Push(q,p);
    }

}

void xuat(Queue q ){
    Node *p = q.head;
    if(isEmpty(q)) cout<<"Hang doi trong!!";
    while(p){
        cout<<p->data << "\t";
        p = p->next;
    }
    cout<< endl;
}

void menu(Queue q){
  int lc;
  do{

        cout << "\n\t1. Xuat Queue";
        cout << "\n\t2. Them phan tu cuoi trong Queue";
        cout << "\n\t3. Xoa phan tu dau trong Queue";
        cout << "\n\t4. Kiem tra Queue rong";
        cout << "\n\t0. Thoat";
   		cout << "\nBan chon: ";
        cin>> lc;
        switch(lc){
            case 0: break;
            case 1:  		system("cls");
				xuat(q); 
              
              break;
            case 2:  		system("cls");
              nhap1(q);
              break;
            case 3:  		system("cls");
              Pop(q);
              break;
            case 4:  		system("cls");
            	if(isEmpty(q)) cout << "\nQueue rong!!\n";
            	else cout<<"\nQueue khong rong!!\n";
            	break;
            default: cout<<"\nNhap sai, vui long nhap lai!";
        }
    } while(lc);
}
int main(){
    Queue q;
    Init(q);
    nhap(q);
  	menu(q);
}
