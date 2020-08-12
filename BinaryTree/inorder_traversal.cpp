#include<bits/stdc++.h>
using namespace std;
class Node{
     public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data=data;
            left=NULL;
            right=NULL;
        }
};
void Inorder(Node* root){
    Node* current=root;
    while(current!=NULL){
        if(current->left!=NULL){
            Node* temp=current->left;
            Node* leftPtr=current->left;
            while(temp->right!=nullptr){
                temp=temp->right;
            }
            
            temp->right=current;
            current->left=NULL;
            current=leftPtr;
        }
        else{
            cout<<current->data<<" ";
            current=current->right;
        }
    }
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right=new Node(3);
    Inorder(root);
    return 0;
}