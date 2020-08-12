#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
       int data;
       Node* left;
       Node* right;
       Node(int data){
           this->data=data;
           left=nullptr;
           right=nullptr;
       } 
};
int kthsmallestElement(Node* root,int k){
    int count=0,val=0;
    while(root){
        if(root->left==NULL){
            count++;
            if(count==k){
                val=root->data;
            }
            root=root->right;
        }
        else{
            Node* leftptr=root->left;
            Node* temp=root->left;
            while(temp && temp->right){
                temp=temp->right;
            }
            temp->right=root;
            root->left=NULL;
            root=leftptr;
        }
    }
    return val;
}
int main(){
    Node* root=new Node(20);
    root->left=new Node(8);
    root->left->left=new Node(4);
    root->left->right=new Node(12);
    root->left->right->left=new Node(10);
    root->left->right->right=new Node(14);
    root->right=new Node(22);
    cout<<kthsmallestElement(root,5)<<endl;
    return 0;
}