#include <iostream>
#include <queue>
typedef priority_queue<int, vector<int>, greater<int> > MINHEAP

using namespace std;

void printPriorityQueue(MINHEAP pq)
{
    MINHEAP dummy = pq;
    
    while(!dummy.empty())
    {
        cout<<"\t"<<dummy.top();
        dummy.pop();
    }
    cout<<"\n";
}
int main() {
	MINHEAP pq;
	
	pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(1);
  
    cout << "The priority queue pq is : ";
    printPriorityQueue(pq);
  
    cout << "\npq.size() : " << pq.size();
    cout << "\npq.top() : " << pq.top();
  
    cout << "\npq.pop() : ";
    pq.pop();
    printPriorityQueue(pq);
  
    return 0;
	return 0;
}
