// Finding minimum distance in undirected graph(Dijkstra's algorithm)
#include <bits/stdc++.h>
using namespace std;
//TC => O((n+e)*n)=>O(n^2) if no PtyQueue
//TC => O((n+e)*LOGn) with PtyQueue
//SC= > O(N+N) N for vis array and N for distance
void findDistInWeighted(vector<pair<int, int>> adj[], int n, int src)
{
    // Taking distance array
    vector<int> dist(n + 1, INT_MAX);
    // Marking distance of source
    dist[src] = 0;
    // Making min heap/prority queue ->(dist,node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Pushing source node in to queue
    pq.push({0, src});
    // Traversing other nodes and checking for minimum distance
    while (!pq.empty())
    {
        int node = pq.top().second;
        int distfromsrc = pq.top().first;
        pq.pop();
        // For each of adjacent node if distance of current node from source
        //+ edge weight is lesser thn distance of that node from source
        // Thn we shall update it as we want shorter distance
        for (auto e : adj[node])
        {
            int adjnode = e.first;
            int wt = e.second;
            if (distfromsrc + wt < dist[adjnode])
            {
                dist[adjnode] = distfromsrc + wt;
                pq.push({distfromsrc + wt, adjnode});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Shortest distance of" << i << " from source is: " << dist[i] << " " << endl;
    }
}

int main()
{
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cout << "Enter node: ";
        cin >> u;
        cout << "Enter adjacent node: ";
        cin >> v;
        cout << "Enter weight of edge: ";
        cin >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Node is: " << i << endl;
        for (auto e : adj[i])
        {
            cout << "Adjacent node is: " << e.first << " at distance of: " << e.second << endl;
        }
    }
    for (int i = 0; i < n; i++)
    {
        findDistInWeighted(adj, n, i);
        cout << endl;
    }
    return 0;
}