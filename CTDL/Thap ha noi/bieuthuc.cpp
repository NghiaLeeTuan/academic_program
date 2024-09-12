#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<fstream>
#include<conio.h>
using namespace std;

int precedence(char op){ 
    if(op == '+'||op == '-') 
        return 1; 
    if(op == '*'||op == '/') 
        return 2; 
    return 0; 
} 
  
int applyOp(int a, int b, char op){ 
    switch(op){ 
        case '+': 
            return a + b; 
        case '-': 
            return a - b; 
        case '*': 
            return a * b; 
        case '/': 
            return a / b; 
    } 
} 
  
int evaluate(string a){ 
    int i; 
     //khoi tao stack chua cac phan tu la so 
    stack <int> values; 
      //khoi tao stack chua cac phan tu la cac toan tu
    stack <char> ops; 
      
    for(i = 0; i < a.length(); i++){ 
          
        if(a[i] == ' ') 
            continue; 
          
        else if(a[i] == '('){ 
            ops.push(a[i]); 
        } 
          
        else if(isdigit(a[i])){ 
            int val = 0; 
              
            while(i < a.length() && isdigit(a[i])){ 
                val = (val*10) + (a[i]-'0'); 
                i++; 
            } 
              
            values.push(val); 
        } 
          
        else if(a[i] == ')'){ 
            
            while(!ops.empty() && ops.top() != '('){ 
                int val2 = values.top(); 
                values.pop(); 
                  
                int val1 = values.top(); 
                values.pop(); 
                  
                char op = ops.top(); 
                ops.pop(); 
                  
                values.push(applyOp(val1, val2, op)); 
            } 
              
            if(!ops.empty()) 
               ops.pop(); 
        } 
          
        else{ 
            while(!ops.empty() && precedence(ops.top()) >= precedence(a[i])){ 
                int val2 = values.top(); 
                values.pop(); 
                  
                int val1 = values.top(); 
                values.pop(); 
                  
                char op = ops.top(); 
                ops.pop(); 
                  
                values.push(applyOp(val1, val2, op)); 
            } 
              
            ops.push(a[i]); 
        } 
    } 
      
    while(!ops.empty()){ 
        int val2 = values.top(); 
        values.pop(); 
                  
        int val1 = values.top(); 
        values.pop(); 
                  
        char op = ops.top(); 
        ops.pop(); 
                  
        values.push(applyOp(val1, val2, op)); 
    } 
      
    return values.top(); 
} 

int main(){
	
	cout<<"Nhap bieu thuc can tinh: "<<endl;
    string a;
    std::ifstream file;
	file.open("input.txt", ios_base::in);
    if(file.fail()==true)
		{	
			cout<<"\nFile khong ton tai hoac sai duong dan!!\n";
		}
    getline(file,a);
	cout << a;
    cout << evaluate(a) << endl; 
    file.close();
    return 0; 
}
