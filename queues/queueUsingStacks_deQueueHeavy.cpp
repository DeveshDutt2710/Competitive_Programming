//queue using stack making dequeue heavy

//this method better than enqueue heavy method since just empties stack just once!!

//time complexity : push : (O(1)) , pop : (O(n))
//space complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

struct Queue{
    stack<int> s1,s2 ;
    
    void enQueue(int x){
        s1.push(x);
        
    }
    void deQueue(){
        if(s1.empty()&& s2.empty()){
            cout<<"queue is empty";
        }
        else if(s2.empty())
        {
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        cout<<s2.top()<<endl;
        s2.pop();
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