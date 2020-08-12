#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
       int data;
       TreeNode* left;
       TreeNode* right;
       TreeNode(int data){
           this->data=data;
           this->left=NULL;
           this->right=NULL;
       }
};
void printTree(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
         auto temp=q.front();
         q.pop();
         if(temp==NULL){
             cout<<endl;
             if(!q.empty())
                q.push(NULL);
         }
         else
         {
             cout << temp->data << " ";
         }
         if(temp && temp->left){
             q.push(temp->left);
         }
         if(temp && temp->right){
             q.push(temp->right);
         } 
    }
}
TreeNode* ConstructTree(TreeNode* root,int val){
    if(root==NULL){
        root=new TreeNode(val);
        return root;
    }
    if(val>root->data){
        root->right=ConstructTree(root->right,val);
    } 
    else{
        root->left=ConstructTree(root->left,val);
    }
    return root;   
}
int main(){
    int n;
    cin>>n;
    int* preorder=new int[n];
    for(int i=0;i<n;i++){
        cin>>preorder[i];
    }
    TreeNode* root=new TreeNode(preorder[0]);
    for(int i=1;i<n;i++){
        if(preorder[i]>root->data){
            root->right=ConstructTree(root->right,preorder[i]);
        }
        else{
            root->left=ConstructTree(root->left,preorder[i]);
        }
    }
    printTree(root);
    return 0;
}