//implementing stack using ARRAY

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack{
    int top;
    
    public:
        int a[MAX];
        
        Stack(){
            top = -1;
        }
        
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};

bool Stack::push(int x)
{
    if(top>=(MAX-1)){
        cout<<"stack overflow";
        return false;
    }
    else{
        a[++top]=x;
        cout<<x<<"pushed into stack\n";
        return true;
    }
}

int Stack::peek()
{
    if(top<0)
    {
        cout<<"stack is empty";
        return 0;
    }
    else{
        int x=a[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

int Stack::pop()
{
    if(top<0){
        cout<<"Stack underflow";
        return 0;
    }
    int popped=a[top];
    top--;
    return popped;
}


int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";
 
    return 0;
}
