#include<bits/stdc++.h>
using namespace std;
class Tree{
    public:
      int data;
      Tree* left;
      Tree* right;
      Tree(int data){
          this->data=data;
          left=NULL;
          right=NULL;
      }
};
void printDiagonal(Tree* root,int h,map<int,vector<int>>&m){
    queue<pair<Tree*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto node=q.front();
        q.pop();
        m[node.second].push_back(node.first->data);
        if(node.first->left){
            q.push({node.first->left,node.second+1});
        }
        if(node.first->right){
            q.push({node.first->right,node.second});
        }
    }
} 
int main(){
    Tree* root =  new Tree(8); 
    root->left =  new Tree(3); 
    root->right =  new Tree(10); 
    root->left->left =  new Tree(1); 
    root->left->right =  new Tree(6); 
    root->right->right =  new Tree(14); 
    root->right->right->left =  new Tree(13); 
    root->left->right->left =  new Tree(4); 
    root->left->right->right =  new Tree(7); 
    map<int,vector<int>>m;
    printDiagonal(root,0,m);
    for(auto it:m){
        for(auto x:it.second)
           cout<<x<<" ";
        cout<<endl;
    }
}