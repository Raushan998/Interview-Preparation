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
void MorrisPreOrder(Node* head){
    Node* current=head;
    while(current!=NULL){
        cout<<current->data<<" ";
        Node* temp=current->right;
        if(current->left){
            Node* leftPtr=current->left;
            Node* left_=current->left;
            while(left_->right!=NULL)
               left_=left_->right;
            left_->right=temp;
            current=leftPtr;
        }
        else
           current=current->right;
    }
}
int main(){
        Node* root=new Node(25);
        root->left=new Node(15);
        root->right=new Node(50);
        root->left->left=new Node(10);
        root->left->right=new Node(22);
        root->left->left->left=new Node(4);
        root->left->left->right=new Node(12);
        root->left->right->left=new Node(18);
        root->left->right->right=new Node(24);
        root->right->left=new Node(35);
        root->right->right=new Node(70);
        root->right->left->left=new Node(31);
        root->right->left->right=new Node(44);
        root->right->right->left=new Node(66);
        root->right->right->right=new Node(90);
        MorrisPreOrder(root);
        return 0;
}