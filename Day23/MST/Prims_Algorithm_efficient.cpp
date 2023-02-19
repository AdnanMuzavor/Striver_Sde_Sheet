/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// Finding minimum distance in undirected graph(Dijkstra's algorithm)
#include <bits/stdc++.h>
using namespace std;
// O(NLogN)+O(N+N+N)
void MinSpanTree(vector<pair<int, int>> adj[], int n, int src)
{
    cout << "Taking " << src << " as spurce node: ";
    // Making keys array,helps in comparing weights
    vector<int> keys(n, INT_MAX);
    // Making pr array to tell parent nodes
    vector<int> pr(n, -1);
    // Making mst arrat, help us in knwing visisted arrs
    vector<bool> mst(n, false);
    // starting from zero so making key[0]=0;
    keys[src] = 0;
    // Making priority queue
    //{weight,node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Pushing node with which we are starting i.e 0
    pq.push({0, 0});

    // As we have N nodes, we have N-1 edges so we'll iterate N-1 times
    for (int i = 0; i < n - 1; i++)
    {
        // Part taking N time
        //  int mini=INT_MAX,node=0;
        //  //Finding minimum value in keys
        //  //and updating node with it's index
        //  for(int i=0;i<n;i++){
        //      if(mst[i]==false && keys[i]<mini){
        //          mini=keys[i];
        //          node=i;
        //      }
        //  }

        // Part which noe takes LogN times
        int node = pq.top().second;
        
        pq.pop();
        // Since I got nodea nd I am processing it
        // I'll make it's mst
        mst[node] = true;
        // Now checking for adjacent nodes of this nodes
        for (auto e : adj[node])
        {
            int adjnode = e.first;
            int wt = e.second;
            // If node is not in mst i.e allowed to visist
            // And weight is lesser thn prev weight as specified by keys array
            // We update the keys value and corresponding parent
            if (mst[adjnode] == false && wt < keys[adjnode])
            {
                pq.push({keys[adjnode], adjnode});
                keys[adjnode] = wt;
                pr[adjnode] = node;
            }
        }
    }
    // Displaying parent for each of node
    for (int i = 0; i < n; i++)
    {
        cout << i << " - " << pr[i] << endl;
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
        MinSpanTree(adj, n, i);
        cout << endl;
    }
    return 0;
}