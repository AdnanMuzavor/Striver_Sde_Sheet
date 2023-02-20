
// Krukal's algorithm to find minimum spanning tree
#include <bits/stdc++.h>
using namespace std;
// O(NLOGN+N) N for finding ele and NLOGN for sorting
// Creating node for grah it'll have  node u and node v and wt of edge between u and V
struct node
{
    int u, v, wt;
    node(int a, int b, int w)
    {
        u = a;
        v = b;
        wt = w;
    }
};

// Compare fn which will be used to sort the array of nodes based on weights
bool comp(node a, node b)
{
    return a.wt < b.wt;
}

// Function find pr
int findpr(int node, vector<int> &par)
{
    if (par[node] == node)
        return node;
    return findpr(par[node], par);
}

// Union functio to union nodes/to create spanning tree
void unionfn(int u, int v, vector<int> &pr, vector<int> &rank)
{
    // Find parent of both te nodes
    u = findpr(u, pr);
    v = findpr(v, pr);
    // Attach one with max rank to one with min rank
    // This will help in reducing tree height
    if (rank[u] < rank[v])
    {
        pr[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        pr[v] = u;
    }
    else
    {
        pr[u] = v;
        rank[u]++;
    }
}
int main()
{

    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    // Making vector of nodes
    vector<node> edges;
    // based on number of edges taking nodes as input
    // and creating graph
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cout << "Enter node 1: ";
        cin >> u;
        cout << "Enter node 2: ";
        cin >> v;
        cout << "Enter wt of edge between nodes: ";
        cin >> wt;
        edges.push_back(node(u, v, wt));
    }
    cout << "Array before sorting: \n";
    for (int i = 0; i < e; i++)
    {
        cout << "n1: " << edges[i].u << ", n2: " << edges[i].v << " wt: " << edges[i].wt << endl;
    }

    // Sorting the array of nodes based on wt
    sort(edges.begin(), edges.end(), comp);
    // Displaying array after Sorting
    cout << "Array acter sorting: \n";
    for (int i = 0; i < e; i++)
    {
        cout << "n1: " << edges[i].u << ", n2: " << edges[i].v << " wt: " << edges[i].wt << endl;
    }
    // Initialising pr vector by making each node parent of itself
    vector<int> pr(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pr[i] = i;
    }
    // Initialising rank array with zero ranks
    vector<int> rank(n, 0);

    int cost = 0;
    vector<pair<int, int>> mst;
    for (auto e : edges)
    {
        // If both nodes associated with edges dont belong to same component
        if (findpr(e.u, pr) != findpr(e.v, pr))
        {
            // Union them
            unionfn(e.u, e.v, pr, rank);
            // Keep record of weights used
            cost += e.wt;
            // Push this pair of u,v in mst
            mst.push_back({e.u, e.v});
        }
    }

    cout << "cost is: " << cost << endl;
    cout << "Pair in result is: " << endl;
    for (auto e : mst)
    {
        cout << e.first << " - " << e.second << endl;
    }
    return 0;
}