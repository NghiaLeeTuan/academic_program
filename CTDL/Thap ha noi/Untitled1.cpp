#include"stdio.h"
#include"conio.h"
#define MAX 10
typedef struct stack{
    int top;
    int len;
    char start;
    char mid;
    char end;
    int disk;
    stack *node[MAX];
}stack;
 
typedef struct{
    char c1;
    char c2;
    char c3;
    int k;
}info;
//Kiem tra ngn xep rong.
int isempty(stack *s){
    if(s->top == -1) return 1;
    else return 0;
}
 
//Kiem tra ngan xep day.
int isfull(stack *s){
    if(s->top == MAX-1) return 1;
    else return 0;
}
 
//nhap lieu cho ngan xep.
void pust(stack *s,info *x,int n){
    if(isfull(s)==1) printf("\n Stack full");
    else{
        s->top += 1;
        s->node[s->len = n];
        s->node[s->start = x->c1];
        s->node[s->mid = x->c2];
        s->node[s->end = x->c3];
        s->node[s->disk = x->k];
    }
}
 
//lay du lieu ra khoi gan xep->
int pop(stack *s){
    if(isempty(s) == 1) {
        printf("\n stack empty");
        return 0;
    }
    else  s->node[s->top--];
}
 
//chuyen dia tu coc nay sang coc kia.
void move(char c1,char c2){
    printf("\n Chuyen dia tu %c sang %c",c1,c2);
}
 
//chuyen vai tro giua cac coc.
void swap(char c1, char c2){
    char c;
    c = c1;
    c1 = c2;
    c2 = c;
}
//Thap Ha Noi
 
void THN(int n){
    stack *s;
    info *x;
    x->c1 = 'X';
    x->c2 = 'Y';
    x->c3 = 'C';
    x->k = 1;
    pust(s,x,n);
    do{
        while(n>0){
            x->k = 2;
            pust(s,x,n);
            n--;
            swap(x->c2,x->c3);
        }
        pop (s);
            if ( x->k!=1 ){
            move (x->c1,x->c3);
            n = n -1 ;
            swap (x->c1,x->c2);
            }
    }while(x->k = 1);
}
 
int main(){
    int n;
    printf("\n n = ");
    scanf("%d",&n);
   
    THN(n);
    getch();
    return 0;
}
