#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
      int data;
      Node* left;
      Node* right;
      Node(int data){
          this->data=data;
          this->left=NULL;
          this->right=NULL;
      }
};
void Inorder(Node* root){
    stack<Node*>s;
    auto current=root;
    while(current!=NULL || !s.empty()){
        while(current!=NULL){
            s.push(current);
            current=current->left;
        }
        current=s.top();
        cout<<s.top()->data<<" ";
        s.pop();
        current=current->right;
       // cout<<current->data<<" ";
    }
}
int main(){
   Node* head=new Node(1);
   head->left=new Node(2);
   head->right=new Node(3);
   head->left->left=new Node(4);
   head->left->right=new Node(5);
   Inorder(head);
   return  0;
}