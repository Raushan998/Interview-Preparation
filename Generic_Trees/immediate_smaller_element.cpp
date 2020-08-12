#include<bits/stdc++.h>
using namespace std;
class Graph{
     public:
       map<int,list<int>>adjList;
       void addEdge(int u,int v){
           adjList[u].push_back(v);
       }
       int findMinimumImediateElement(int element,int node){
            queue<int>q;
            q.push(node);
            int current_element=INT_MIN;
            map<int,bool>visited;
            while(!q.empty()){
                int temp=q.front();
                q.pop();
                if(element>temp){
                    current_element=max(current_element,temp);
                    //cout<<temp<<endl;
                }
                for(auto neighbour:adjList[node]){
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour]=true;
                    }
                }
            }
            return current_element;
       }

};
int main(){
    int n,element,node;
    cin>>n>>element;
    Graph g;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        if(i==0)
          node=u;
        g.addEdge(u,v);
    }
    cout<<g.findMinimumImediateElement(element,node)<<endl;
    return 0;
}