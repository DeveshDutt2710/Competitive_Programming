/*
Design a stack with the following operations.

a) push(Stack s, x): Adds an item x to stack s 
b) pop(Stack s): Removes the top item from stack s 
c) merge(Stack s1, Stack s2): Merge contents of s2 into s1.

Time Complexity of all above operations should be O(1).


*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct myStack{
    Node *head=NULL;
    Node *tail=NULL;
};

void push(int data, myStack *ms)
{
    Node *temp=new Node();
    temp->data=data;
    temp->next=ms->head;
    if(ms->head==NULL){
        ms->tail=temp;
    }
    ms->head=temp;
}

int pop(myStack *ms)
{
    if(ms->head==NULL)
    {
        cout<<"stack underflow"<<endl;
    }
    else{
        Node *temp=ms->head;
        ms->head=ms->head->next;
        int popped =temp->data;
        free(temp);
        return popped;
    }
    return 0;
}

void merge(myStack *ms1, myStack *ms2)
{
    if(ms1->head==NULL)
    {
        ms1->head=ms2->head;
        ms1->tail=ms2->tail;
        return ;
    }
    ms1->tail->next=ms2->head;
    ms1->tail=ms2->tail;
}

void display(myStack* ms) 
{ 
    Node* temp = ms->head; 
    while (temp != NULL) { 
        cout << temp->data << " "; 
        temp = temp->next; 
    } 
} 



int main() 
{ 
    myStack* ms1 = new myStack(); 
    myStack* ms2 = new myStack(); 
 
    push(6, ms1); 
    push(5, ms1); 
    push(4, ms1); 
    push(9, ms2); 
    push(8, ms2); 
    push(7, ms2); 
    merge(ms1, ms2); 
    display(ms1); 
}