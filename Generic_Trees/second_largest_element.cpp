#include<bits/stdc++.h>
using namespace std;
class Tree{
    public:
       int data;
       vector<Tree*>children;
       Tree(int data){
           this->data=data; root->children.push_back(new Tree(2));
    root->children.push_back(new Tree(3));
       }
};
int SeconLargest(Tree* root){
    int max_element=INT_MIN,second_max=INT_MIN;
    queue<Tree*>q;
    q.push(root);
    while(!q.empty()){
        auto temp=q.front();
        if(max_element<temp->data || second_max<temp->data){
             if(max_element<temp->data){
                second_max=max_element;
                max_element=temp->data;
             }
             else{
                 second_max=temp->data;
             }
        }
        q.pop();
        for(int i=0;i<temp->children.size();i++){
            q.push(temp->children[i]);
        }
    }
    return second_max;
}
Tree* InputlevelWise(){
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
    Tree* root;
    root=InputlevelWise();
    cout<<SeconLargest(root)<<endl;
    return 0;
}