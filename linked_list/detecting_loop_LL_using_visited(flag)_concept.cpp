//modified structure of LL
struct Node{
    int data;
    int flag;
    struct Node* next;
};

//modified detectLoop function
//make flag = 0 for each node of linked list
bool detectLoop(struct Node* h){
    while(h!= NULL){
        if(h->flag == 1){
            return true;
        }
        h->flag=1;
        h=h->next;
    }
    return false;
}
