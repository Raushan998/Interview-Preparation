// { Driver Code Starts
#include <bits/stdc++.h>
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
void printPostOrder(Node* root){
    stack<Node*>s1;
    stack<Node*>s2;
    s1.push(root);
    while(!s1.empty()){
        auto node=s1.top();
        s1.pop();
        s2.push(node);
        if(node->left)
           s1.push(node->left);
        if(node->right)
           s1.push(node->right);
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
    return;
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right=new Node(3);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->left->left->right=new Node(8);
    printPostOrder(root);
    return 0;
}