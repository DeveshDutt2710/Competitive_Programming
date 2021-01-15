//Time Complexity:
//  Push operation : O(1)
//  Pop operation : O(1)
//Auxiliary Space :O(N).


#include <iostream>
#include <stdlib.h>

using namespace std;

class twoStack{
    int *arr;
    int size;
    int top1,top2;
    
    public:
        twoStack(int n)
        {
            size=n;
            arr=new int[n];
            top1=-1;
            top2=size;
        }
        
        void push1(int x){
            if(top1<top2-1){
                arr[++top1]=x;
            }
            else{
                cout<<"stack overflow\n";
            }
        }
        void push2(int x){
            if(top1<top2-1){
                arr[--top2]=x;
            }
            else{
                cout<<"stack overflow\n";
            }
        }
        void pop1(){
            if(top1>=0){
                cout<<"Popped element from stack1 is : "<<arr[top1--];
            }
            else{
                cout<<"\nstack underflow";
            }
        }
        void pop2(){
            if(top2>=size){
                cout<<"\nstack underflow";
            }
            else{
                cout<<"\nPopped element from stack1 is : "<<arr[top2++];
            }
        }
};

int main() 
{ 
    twoStack ts(5); 
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7); 
    ts.pop1(); 
    ts.push2(40); 
    ts.pop2(); 
    return 0; 
} 