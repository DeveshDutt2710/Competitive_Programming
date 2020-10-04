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

struct Node* detectLoop(struct Node* list){
    struct Node *slowP=list, *fastP=list;
    
    while(slowP && fastP && fastP->next){
        slowP=slowP->next;
        fastP=fastP->next->next;
        if(slowP==fastP){
            break;
        }
    }
    if(slowP!=fastP){
        return NULL;
    }
    
    slowP=list;
    while(slowP!=fastP){
        slowP=slowP->next;
        fastP=fastP->next;
    }
    return slowP;
}

int main() 
{ 
    /* Start with the empty list */
    Node* head = NULL; 
  
    push(&head, 10); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 20); 
    push(&head, 50);
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
    Node* res=detectLoop(head);
    if (res==NULL) 
        cout << "Loop doesnt exist\n"; 
    else
        cout << "Loop starting node is "<<res->data; 
    return 0; 
} 
 