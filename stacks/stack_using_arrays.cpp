#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

class Stack{
    int top;
    
public:
    int a[MAX];
    
    Stack(){top=-1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    
};

bool Stack::push(int x){
    if(top >=(MAX-1)){
        cout<<"stack overflow";
        return false;
    }
    else{
        a[++top]=x;
        cout<<x<<" pushed into stack\n";
        return true;
    }
}

int Stack::pop(){
    if(top < 0){
        cout<<"stack underflow\n";
        return 0;
    }
    else{
        int x=a[top--];
        cout<<x<<" popped out of stack\n";
        //return x;
    }
}

bool Stack::isEmpty(){
    return (top<0);
}

int main() {
	// your code goes here
	class Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.pop();
	return 0;
}
