/******************************************************************************

Detect cycle in directed graph using BFS

Complexity: O(N+E) nd O(N+E) + O(N)+ O(N)
                      adj    stack  color

*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool detectCycleDFS(int node,vector<int> &vis,vector<int> &dfsvis,vector<int> adj[]){
    vis[node]=1;
    dfsvis[node]=1;
    for(auto adjn:adj[node]){
        if(dfsvis[adjn]) return true;
        else if(detectCycleDFS(adjn,vis,dfsvis,adj)) return true;
    }
    dfsvis[node]=0;
    return false;

}
int main()
{
    int n,e;
    cout<<"Enter number of nodes: "<<endl;
    cin>>n;
    cout<<"Enter number of edges: "<<endl;
    cin>>e;
    vector<int> adj[n];
    cout<<"Enter the edges: "<<endl;
    for(int i=0;i<e;i++){
        int from, to;
        cin>>from>>to;
        adj[from].push_back(to);
        // adj[to].push_back(from); //As NOT an undirected graph it is
    }
    cout<<"Graph is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<" node: =>  "<<i<<" ";
        for(auto e:adj[i]){
            cout<<" | "<<e<<" | ";
        }
        cout<<endl;
    }
    vector<int> vis(n,0);
    vector<int> dfsvis(n,0);
    if(detectCycleDFS(0,vis,dfsvis,adj)){
        cout<<"Cycle exists in given graph"<<endl;
    }
    else{
        cout<<" No cycle in the graph"<<endl;
    }
    return 0;
}