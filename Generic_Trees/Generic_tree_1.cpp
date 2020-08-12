#include<bits/stdc++.h>
using namespace std;
class Tree{
    public:
      map<int,vector<int>>adjList;
      void addEdge(int u,int v){
          adjList[u].push_back(v);
      }
      int TotalNodeHaveChildGreaterThanParent(){
          int node=1,count=0;
          queue<int>q;
          q.push(node);
          while(!q.empty()){
              node=q.front();
              q.pop();
              for(auto neighbour:adjList[node]){
                  if(adjList[neighbour].size()>adjList[node].size())
                    count++;
                  q.push(neighbour); 
              }
          }
          return count; 
      }
};
int main(){
    Tree g;
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(2,5);
    g.addEdge(2,6);
    g.addEdge(5,7);
    g.addEdge(5,8);
    g.addEdge(3,9);
    g.addEdge(5,10);
    g.addEdge(5,12);
    g.addEdge(3,15);
    g.addEdge(3,18);
    cout<<g.TotalNodeHaveChildGreaterThanParent()<<endl;
    return 0;
}