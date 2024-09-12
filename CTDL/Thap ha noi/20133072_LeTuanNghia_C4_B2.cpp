#include <stdio.h> 
#include<math.h>
#include<iostream>

using namespace std;
typedef struct Stack 
{ 
   int size; 
   int top;  
   int *arr;
}Stack_Node; 

// khoi tao stack
Stack_Node* Create_stack(int size) 
    {
        Stack_Node* stack= new Stack;
        stack->size =size;
        stack->top =-1; 
        stack->arr = new int[size];
        return stack;
    }
// kiem tra stack co day hay khong
bool Check_Full(Stack_Node* stack) 
    { 
       if(stack->top == stack->size - 1)
          return true;
       else
         return false;
     }
     
// kiem tra stack co rong hay khong
bool Check_Empty(Stack_Node* stack) 
    { 
       if(stack->top == -1)
         return true;
      else
        return false; 
    }
    
// them phan tu vao dau
void push(Stack_Node* stack, int element) 
   { 
      if(Check_Full(stack)) 
         return; 

      stack->arr[++stack->top]= element; 
   }
   

int pop(Stack_Node* stack) 
   { 
        if(Check_Empty(stack)) 
           return -1;
           
        return(stack->arr[stack->top--]); 
    }

//in dia vua move
void Move_Disc(int disc, char from_Rod, char to_Rod) 
{   

       cout<<"Chuyen dia "<<disc<<" "<<"tu cot '"<<from_Rod<<"' den cot '"<<to_Rod<<"'"<<endl;


} 

void Move(Stack_Node* st1, Stack_Node* st2, char a, char b) 
   { 
      int top1=pop(st1); 
      int top2 =pop(st2); 
      if (top1 == -1) 
       { 
           push(st1,top2); 
           Move_Disc(top2, b, a); 
       } 
      else if (top2 ==-1) 

      { 
              push( st2,top1); 
              Move_Disc(top1, a, b); 
      } 
      else if (top1 >top2) 
      { 
              push(st1, top1);
              push(st1, top2); 
              Move_Disc(top2, b, a); 
       } 
      else
       { 
             push( st2,top2); 
             push( st2,top1); 
             Move_Disc(top1, a, b); 

       } 
 } 

void TowerOfHanoi(int n, Stack_Node*st1, Stack_Node*st2,Stack_Node *st3) 

    {  		
    		//3 que A B C 
            char a = 'A', b = 'B', c = 'C'; 
            
            if (n % 2== 0) 
            {
                char var =b;
                b =c;
                c =var; 
            } 

            int n2 =pow(2,n) - 1; 
            for (int i =n; i >= 1; i--) 
            {
                push(st1,i); 
            }
            
            // di chuyen dia 
            for (int i = 1; i <=n2; i++) 
            { 
                if (i % 3== 0)  
                      Move(st2, st3, b, c); 
               else if (i% 3 == 2) 
                      Move(st1,st2, a, b); 
               else if (i% 3 == 1) 
                      Move(st1,st3, a, c); 
            } 
    }  
    
int main() 
{ 
    int n;
    cout<<"Nhap so dia dau vao: ";
    cin>>n;
            
    Stack_Node* st1;
    Stack_Node* st2;
    Stack_Node* st3;
            
    // tao 3 ngan xep cho 3 que          
    st1 =Create_stack(n); 
    st2 =Create_stack(n); 
    st3 =Create_stack(n);   

    TowerOfHanoi(n,st1, st2, st3);
     
    // xoa ngan xep khoi bo nho
    delete st1;
    delete st2;
    delete st3;
    return 0; 
}
