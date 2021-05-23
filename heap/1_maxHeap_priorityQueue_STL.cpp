#include <iostream>
#include <queue>

using namespace std;

void printPriorityQueue(priority_queue<int> pq)
{
    priority_queue<int> dummy = pq;
    
    while(!dummy.empty())
    {
        cout<<"\t"<<dummy.top();
        dummy.pop();
    }
    cout<<"\n";
}
int main() {
	priority_queue<int> pq;
	
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
