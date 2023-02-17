/*
To detect cycle in undirected graph using BFS
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool detectCycleBFS(int prev,int node,vector<int> &vis,vector<int> adj[]){
    // MAKE QUEUE
    queue<pair<int,int>> q;
    q.push({node,prev});
    //START WITH CURRENT NODE BY MARKING IT VISITED
    vis[node]=1;
    while(!q.empty()){
        //GET THE PUSHED ELEMENT
        auto p=q.front();
        q.pop();
        int prev=p.second;
        int node=p.first;
        //CHECK FOR ADJACENT
        for(auto adjn:adj[node]){
            // IF VISISTED IT SHOULD BE PREV OTHERISE CYCLE EXISTS
            if(vis[adjn] && adjn!=prev) return true;
            //IF NODE, CHECK FOR ADJ' ADJACENT NODES BY TAKING CURRENT NODE AS IT'S PREV
            else if(!vis[adjn]){
                vis[adjn]=1;
                q.push({adjn,node});
            }
        }
    }
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
        adj[to].push_back(from); //As undirected graph it is
    }
    cout<<"Graph is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<" node: "<<i<<" ";
        for(auto e:adj[i]){
            cout<<" | "<<e<<" | ";
        }
        cout<<endl;
    }
    vector<int> vis(n,0);
    if(detectCycleBFS(-1,0,vis,adj)){
        cout<<"Cycle exists in given graph"<<endl;
    }
    else{
        cout<<" No cycle in the graph"<<endl;
    }
    return 0;
}