#include <bits/stdc++.h>
using namespace std;

queue<int> q;
void push(int);
void pop();
int top();
bool empty();

void push(int val)
{
    q.push(val);
    int size=q.size();
    
    for(int i=0;i<size-1;i++)
    {
        q.push(q.front());
        q.pop();
    }
}

void pop()
{
    if(q.empty())
    {
        cout<<"no elements in queue\n";
    }
    else
    {
        q.pop();
    }
}

int top()
{
    return (q.empty())? -1 : q.front();
}

bool empty() 
{ 
    return (q.empty()); 
} 

int main()
{
    push(10);
    push(20);
    cout<<top()<<endl;
    pop();
    push(30);
    pop();
    cout<<top()<<endl;
    return 0;
}