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
int MaxImmediateValue(Tree* root){
    queue<Tree*>q;
    q.push(root);
    int node=-1;
    int max_val=INT_MIN,current_sum=0;
    while(!q.empty()){
        current_sum=0;
        auto temp=q.front();
        q.pop();
        for(int i=0;i<temp->children.size();i++){
           current_sum+=temp->children[i]->data;
           q.push(temp->children[i]);
        }
        if(max_val<current_sum){
            max_val=current_sum;
            node=temp->data;
        }
    }
    cout<<node<<" ";
    return max_val;
}
void PrintData(Tree* root){
    queue<Tree*>q;
    q.push(root);
    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        cout<<temp->data<<"->";
        for(int i=0;i<temp->children.size();i++){
        cout<<temp->children[i]->data<<",";
        q.push(temp->children[i]);
        }
        cout<<endl;
    }
}
Tree* insertTree(){
    queue<Tree*>q;
    int num;
    cin>>num;
    Tree* root=new Tree(num);
    q.push(root);
    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        int numchild;
        cin>>numchild;
        for(int i=0;i<numchild;i++){
            int childData;
            cin>>childData;
            Tree* child=new Tree(childData);
            temp->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}
int main(){
    Tree* root=insertTree();
    PrintData(root);
    cout<<MaxImmediateValue(root)<<endl;
}