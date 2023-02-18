// Find shortest distance of each node from source node in undirectred graph
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void distance(int n, vector<pair<int,int>> adj[])
{
    vector<int> dist(n,INT_MAX);
    // => As we start from source distance of source from source itself is zero
    dist[0]=0;
    // => As we areb using BFS queue is must here
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        // Check for adjacent nodes
        for(auto e:adj[node]){
            //If only distance can be minimized update distamce 
            // => check if distance of adjacent node can be minimized
            // => If possible then only push it into the queue with minimized distance
            if(dist[node]+e.second < dist[e.first]){
                dist[e.first]=dist[node]+e.second;
                q.push(e.first);
            }
        }
    }
    cout<<" dist: "<<endl;
    for(auto e:dist) cout<<e<<" ";
}

int main()
{

    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<pair<int,int>> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        int u, v,wt;
        cout << "Enter node: ";
        cin >> u;
        cout << "Enter adjacent node: ";
        cin >> v;
        cout<<" Enter wt: ";
        cin>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

   distance(n, adj);
 
  
    return 0;
}
