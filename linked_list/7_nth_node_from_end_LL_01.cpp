#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Link list node
struct Node{
    int data;
    struct Node* next;
};

//Function to get the nth node from the last of a linked list
void printNthFromLast(struct Node* head, int n){
    int len=0,i;
    struct Node* temp=head;
    
    //count the number of nodes in linked list
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
        len++;
    }
    
    //check if value of n is not more than  length of linked list
    if(len<n){
        return;
    }
    temp=head;
    for (i = 1; i < len - n + 1; i++){ 
        temp = temp->next;
    }
    cout<<"\n"<<temp->data;
    return;
}

void push(struct Node** head_ref, int new_data){
    struct Node* new_node=new Node();
    new_node -> data=new_data;
    new_node -> next= (*head_ref);
    *head_ref=new_node;
}

int main() {
	// your code goes here 
	struct Node* head = NULL;
	
	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 35);
	
	printNthFromLast(head, 2);
	
	return 0;
}
