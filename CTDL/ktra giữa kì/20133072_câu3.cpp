#include<bits/stdc++.h>
#include<iostream>

using namespace std;

struct arr
{
	int a;	
};

struct Node
{
    arr *data;
    Node *pNext;
};
struct SingleList
{
    Node *pHead;
};

void Initialize(SingleList *&list)
{
    list=new SingleList;
    list->pHead=NULL;
}

Node *CreateNode(arr *a)
{
    Node *pNode=new Node;
    if(pNode!=NULL)
    {
        pNode->data=a;
        pNode->pNext=NULL;
    }
    else
    {
        cout<<"cap phat bo nho that bai!!!";
    }
    return pNode;
}

void InsertLast(SingleList *&list,arr *a)
{
    Node *pNode=CreateNode(a);
    if(list->pHead==NULL)
    {
        list->pHead=pNode;
    }
    else
    {
        Node *pTmp=list->pHead;
         
        while(pTmp->pNext!=NULL)
        {
            pTmp=pTmp->pNext;
        }
        pTmp->pNext=pNode;
    }
}

void xuat(SingleList *list)
{
	Node *pTmp=list->pHead;
    if(pTmp==NULL)
    {
        return;
    }
    while(pTmp!=NULL)
    {
        arr *a=pTmp->data;
       	cout << a->a << "  ";
        pTmp=pTmp->pNext;
    }
}

int r(int min, int max){return min + rand() % (max + 1 - min);}

int main()
{
	SingleList *list1;
	SingleList *list2;
    Initialize(list1);
    Initialize(list2);
    
	arr *a;
	srand ( time(NULL) );
	for(int i=0;i<10;i++)
	{ a->a=r(1,99);
	InsertLast(list1,a);}
	for(int i =0;i<10;i++)
	{ a->a=r(1,99);
	InsertLast(list2,a);}
	
	
	xuat(list1);
	cout << endl;
	xuat(list2);
	
	
	
}
