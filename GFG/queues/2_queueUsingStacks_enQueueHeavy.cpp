//queue using stack making enQueue heavy

//time complexity : push : (O(n)) , pop : (O(1))
//space complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

struct Queue{
    stack<int> s1,s2 ;
    
    void enQueue(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    void deQueue(){
        if(s1.empty()){
            cout<<"\nqueue is empty";
        }
        else{
            cout<<"\ndequeued element : "<<s1.top();
            s1.pop();
        }
    }
};

int main() 
{ 
    Queue q; 
    q.enQueue(1); 
    q.enQueue(2); 
    q.enQueue(3); 
  
    q.deQueue(); 
    q.deQueue(); 
    q.deQueue(); 
  
    return 0; 
}
