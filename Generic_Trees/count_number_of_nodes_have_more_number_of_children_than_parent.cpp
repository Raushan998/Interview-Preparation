#include<bits/stdc++.h>
using namespace std;
class Tree{
    public:
       int data;
       vector<Tree*>children;
       Tree(int data){
           this->data=data;
       }
};
void printNode(Tree* root){
    queue<Tree*>q;
    q.push(root);
    while(!q.empty()){
        auto temp=q.front();
        cout<<temp->data<<"->";
        q.pop();
        for(int i=0;i<temp->children.size();i++){
            q.push(temp->children[i]);
            cout<<temp->children[i]->data<<",";
        }
        cout<<endl;
    }
}
vector<int> CountNumberofNodes(Tree* root){
    queue<Tree*>q;
    q.push(root);
    vector<int>vect;
    while(!q.empty()){
        auto node=q.front();
        q.pop();
        for(int i=0;i<node->children.size();i++){
            if(node->children.size()<node->children[i]->children.size()){
                vect.push_back(node->children[i]->data);
            }
            q.push(node->children[i]);
        }
    }
    return vect;     
}
Tree* insertNode(){
    int data;
    cin>>data;
    Tree* root=new Tree(data);
    queue<Tree*>q;
    q.push(root);
    while(!q.empty()){
        auto node=q.front();
        q.pop();
        int numchild;
        cin>>numchild;
        for(int i=0;i<numchild;i++){
            int childData;
            cin>>childData;
            Tree* rootData=new Tree(childData);
            node->children.push_back(rootData);
            q.push(rootData);
        }
    }
    return root;
}
int main(){
    Tree* root=insertNode();
    // printNode(root);
    vector<int>res=CountNumberofNodes(root);
    for(auto it:res)
       cout<<it<<" ";
    return 0;
}