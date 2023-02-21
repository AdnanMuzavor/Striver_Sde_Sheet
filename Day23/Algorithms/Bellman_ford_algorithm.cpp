#include <bits/stdc++.h>
using namespace std;

// Time complxity O((n-1)*E) n->Nodes,E->edges

typedef struct node
{
    int from;
    int to;
    int wt;
    node(int u, int v, int weight)
    {
        from = u;
        to = v;
        wt = weight;
        cout << "wt: " << wt << endl;
    }
} node;
void BellManFord(int n, vector<node> adj, int src)
{
    // Declare distance Array
    vector<int> dist(n, 100000);
    // Make distance of source node=0
    dist[src] = 0;
    // As procedure relax n-1 times
    for (int i = 1; i <= n - 1; i++)
    {
        // Relaxation part
        for (auto e : adj)
        {
            if (dist[e.to] > dist[e.from] + e.wt)
            {
                dist[e.to] = dist[e.from] + e.wt;
            }
            cout << "Dist after i: " << i << " th relaxation" << endl;
            for (auto e : dist)
                cout << e << " ";
            cout << endl;
        }
        //   cout<<"Dist after i: "<<i<<" th relaxation"<<endl;
        //   for(auto e:dist) cout<<e<<" ";
        //   cout<<endl;
    }
    // You will have your minimum distance in distr array
    for (auto e : dist)
    {
        cout << e << " ";
    }
    // Verifu for negative cycle
    // I.e if it is possible to reduce distanec even more
    // That case negtaive cycle exists
    for (int i = 1; i < 2; i++)
    {
        for (auto e : adj)
        {
            if (dist[e.to] > dist[e.from] + e.wt)
            {
                cout << "Negative cycle exists" << endl;
                break;
            }
        }
    }
}

int main()
{
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<node> adj;
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cout << "Enter node: ";
        cin >> u;
        cout << "Enter adjacent node: ";
        cin >> v;
        cout << "Enter weight of edge: ";
        cin >> wt;
        adj.push_back(node(u, v, wt));
    }
    for (auto e : adj)
    {
        cout << e.from << " ---- " << e.to << " wt: " << e.wt << endl;
    }
    // Assume 0 as source
    BellManFord(n, adj, 0);
    cout << endl;

    return 0;
}