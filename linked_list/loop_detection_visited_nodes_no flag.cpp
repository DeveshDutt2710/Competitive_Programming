//Marking visited nodes without modifying the linked list data structure (THIS METHOD IMPLEMENTED BELOW)
//other method is by adding flag to the original linked list data structure
//time complexity : O(1)
//space complexity : O(1)


//another method : 2 temp nodes, 1 fixed at head and other moving. calculate distance between the 2 nodes after every move.
//distance increases initially then decreases suddenly. point at which current distance is smaller than previous
//one is the starting point of the loop
//time complexity : O(n*n)
//space complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *new_node(int value){
    Node *temp=new Node;
    temp->data=value;
    temp->next=NULL;
    return temp;
}

int DetectLoop(Node *head){
    Node *temp=new Node;
    Node *nex=new Node;
    if(head==NULL){
        cout<<"list is empty";
        return 0;
    }
    while(head->next){
        if(head->next != temp){
            nex=head->next;
            head->next=temp;
            head=nex;
        }
        else if(head->next==temp){
            cout<<"loop found";
            return 1;
        }
        
    }
    cout<<"loop not found";
    return 0;
}


int main(){
    Node *head=NULL;
    
    head = new_node(5);
    head->next = new_node(9);
    head->next->next = new_node(3);
    head->next->next->next = new_node(4);
    head->next->next->next->next = new_node(7);
    
    head->next->next->next->next->next = head->next->next;
    
    DetectLoop(head);
}
