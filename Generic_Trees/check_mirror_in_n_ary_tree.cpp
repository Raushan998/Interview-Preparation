#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    map<int, vector<int>> adjList;
    Graph()
    {
    }
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }
};
bool isMirror(Graph* g1, Graph* g2)
{
    queue<int> q1, q2;
    map<int, bool> visited1;
    map<int, bool> visited2;
    q1.push(1);
    q2.push(1);
    visited1[1] = true;
    visited2[1] = true;
    while (!q1.empty() && !q2.empty())
    {
        int node1 = q1.front();
        int node2 = q2.front();
        q1.pop();
        q2.pop();
        if (node1 != node2)
            return false;
        for (auto neighbour : g1->adjList[node1])
        {
            if (!visited1[neighbour])
            {
                q1.push(neighbour);
                visited1[neighbour] = true;
            }
        }
        for (int i = g2->adjList[node2].size() - 1; i >= 0; i--)
        {
            int neighbour = g2->adjList[node2][i];
            if (!visited2[neighbour])
            {
                q2.push(neighbour);
                visited2[neighbour] = true;
            }
        }
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Graph* g1=new Graph();
        Graph* g2=new Graph();
        int node, edge;
        cin >> node >> edge;
        for (int i = 0; i < edge; i++)
        {
            int vertex, node;
            cin >> vertex >> node;
            g1->addEdge(vertex, node);
        }
        for (int i = 0; i < edge; i++)
        {
            int vertex, node;
            cin >> vertex >> node;
            g2->addEdge(vertex, node);
        }
        cout << isMirror(g1, g2) << endl;
    }
}