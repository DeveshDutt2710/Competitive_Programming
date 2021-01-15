//as soon as both fast and slow pointer meet, stop the fast pointer 
//and keep on moving slow pointer inside the loop until it meets faster pointer again
//keep a count side by side to find the length of the loop  [time complexity : O(n) ; space complexity : O(1)]

//time complexity : O(n)
//space complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data){
    struct Node* new_node=new Node();
    new_node->data=new_data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

int detectLoop(struct Node* list){
    struct Node *slowP=list, *fastP=list;
    
    while(slowP && fastP && fastP->next){
        slowP=slowP->next;
        fastP=fastP->next->next;
        if(slowP==fastP){
            return 1;//(if wanna find length of the loop)call a method here that would return number of nodes inside the loop
        }
    }
    return 0;
}

int main() 
{ 
    Node* head = NULL; 
  
    push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 10); 
  
    head->next->next->next->next = head; 
    if (detectLoop(head)) 
        cout << "Loop found"; 
    else
        cout << "No Loop"; 
    return 0; 
} 
 
