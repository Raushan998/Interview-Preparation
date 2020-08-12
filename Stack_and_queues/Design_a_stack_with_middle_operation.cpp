#include<bits/stdc++.h>
using namespace std;
class DLLNode{
    public:
       DLLNode* prev;
       DLLNode* next;
       int data;
};
class Stack{
    public:
       DLLNode* head;
       DLLNode* mid;
       int count;
};
Stack* CreatemyStack(){
    Stack* ms=new Stack();
    ms->count=0;
    return ms;
}
int push(Stack* ms,int num){
    DLLNode* newNode=new DLLNode(num);
    newNode->prev=NULL;
    newNode->next=ms->head;
    ms->count+=1;
    if(ms->count==1){
        ms->mid=newNode;
    }
    else{
        ms->head->prev=newNode;
        if(!ms->count&1){
            ms->mid=ms->mid->prev;
        }
    }
    ms->head=newNode;
}
int pop(Stack* ms){
    if(ms->count==0)
       return -1;
    DLLNode* head=ms->head;
    int item=head->data;
    ms->head=head->next;
    if(ms->head!=NULL){
        ms->head->prev=NULL;
    }
    ms->count-=1;
    if(ms->count&1){
        ms->mid=ms->mid->next;
    }
    free(head);
    return item;
}
int findMiddle(Stack* ms){
    if(ms->count==0)
        return -1;
    return ms->mid->data;
}
int main(){
    Stack* ms=CreatemyStack();
    cout<<"Hello World!"<<endl;
    push(ms, 11);  
    push(ms, 22);  
    push(ms, 33);  
    push(ms, 44);  
    push(ms, 55);  
    push(ms, 66);  
    push(ms, 77);  
  
    cout << "Item popped is " << pop(ms) << endl;  
    cout << "Item popped is " << pop(ms) << endl;  
    cout << "Middle Element is " << findMiddle(ms) << endl;  
    return 0;
}
