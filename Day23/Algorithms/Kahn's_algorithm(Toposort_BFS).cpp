#include <bits/stdc++.h>
using namespace std;
// Kahn's algorithm
vector<int> toposort(int n, vector<int> adj[])
{
    // Vector for containing output
    vector<int> op;
    // Making indegree vector
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto e : adj[i])
        {
            indeg[e]++;
        }
    }
    // Making queue
    queue<int> q;
    // Pushing those elments into queue whose indegree is 0
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    // Doing BFS traversal
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        op.push_back(node);
        // Travsering adjacent nodes
        for (auto e : adj[node])
        {
            // Decrementing indegree
            indeg[e]--;
            // If indegree is zero push into queue
            if (indeg[e] == 0)
            {
                q.push(e);
            }
        }
    }
    cout << "Topological sort is: ";
    for (auto e : op)
        cout << e << " ";
    return op;
}

int main()
{
    printf("Hello World");
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<int> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cout << "Enter node: ";
        cin >> u;
        cout << "Enter adjacent node: ";
        cin >> v;
        adj[u].push_back(v);
    }
    for (int i = 0; i < n; i++)
    {
        cout << "node is: " << i << " adj are: ";
        for (auto e : adj[i])
            cout << e << " ";
        cout << endl;
    }
    toposort(n, adj);
    return 0;
}
