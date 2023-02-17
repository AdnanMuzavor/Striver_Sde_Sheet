/******************************************************************************

Check if undirected graph is bipartite using BFS

Complexity: O(N+E) nd O(N+E) + O(N)+ O(N)
                      adj    queue  color

*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool BipartiteBFS(int node,int m,vector<int> &color,vector<int> adj[]){
       queue<pair<int,int>> q;
       //Color current node and save it's status
       q.push({node,m});
       color[node]=m;
       //Pop each node and chekc adjacent nodes
       while(!q.empty()){
           int curr=q.front().first;
           int colored=q.front().second;
           q.pop();
           for(auto adjn:adj[curr]){
               //If adjacent is uncolored, no issue just color with other color
               if(color[adjn]==-1){
                   q.push({adjn,!colored});
                   color[adjn]=!colored;
               }
               //if colored check if it's colored with same color
               else if(color[adjn]!=-1 && color[adjn]==color[curr]) return false;
           }
       }
       return true;
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
         adj[to].push_back(from); //As NOT an undirected graph it is
    }
    cout<<"Graph is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<" node: =>  "<<i<<" ";
        for(auto e:adj[i]){
            cout<<" | "<<e<<" | ";
        }
        cout<<endl;
    }
    vector<int> color(n,-1);
    if(BipartiteBFS(0,1,color,adj)){
        cout<<"Graph is Bipartite"<<endl;
    }
    else{
        cout<<"Graph is not bipartite"<<endl;
    }
    return 0;
}