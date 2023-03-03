/*

Minimum Spanning Tree
MediumAccuracy: 47.82%Submissions: 71K+Points: 4
Lamp
Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!

Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.



Example 1:

Input:
3 3
0 1 5
1 2 3
0 2 1

Output:
4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
Example 2:

Input:
2 1
0 1 5

Output:
5
Explanation:
Only one Spanning Tree is possible
which has a weight of 5.


Your task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function  spanningTree() which takes number of vertices V and an adjacency matrix adj as input parameters and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree. Here adj[i] contains a list of lists containing two integers where the first integer a[i][0] denotes that there is an edge between i and a[i][0][0] and second integer a[i][0][1] denotes that the distance between edge i and a[i][0][0] is a[i][0][1].

In other words , adj[i][j] is of form  { u , wt } . So,this denotes that i th node is connected to u th node with  edge weight equal to wt.



Expected Time Complexity: O(ElogV).
Expected Auxiliary Space: O(V2).


Constraints:
2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
Graph is connected and doesn't contain self loops & multiple edges.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int sum_wt = 0;
        // Priority queue as we are going to select those edge wts which are minimum always
        // pair strycture
        // 1) Wt as pq will be sorted based on first para always
        // 2) Node
        // 3) Parent node [May not be required here as we are not asked to give an MST edges]
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        // we take a visisted vector , basically nopde that is visited is the one which is already in the MST
        vector<int> vis(V, 0);
        // start with 0 th node
        q.push({0, {0, -1}});
        // Process rest of the nodes
        while (!q.empty())
        {
            auto tp = q.top();
            q.pop();
            int node = tp.second.first;

            // If may happen that by the time the node is extracted, it's already visited and adde dto MST
            // if so dont continue iwth it
            if (vis[node] == 1)
                continue;

            // Otherise since node is popped means we have selected it so add it's edge weight
            sum_wt += tp.first;
            vis[node] = 1;
            // and explore the current node's neighbors as not visisted and push them in the queue

            for (auto e : adj[node])
            {
                int adjnode = e[0];

                // If there exist the adjacent node and such node is not visisted i.e not in MST
                // push into priority queue for our consideration
                if (!vis[adjnode])
                {
                    q.push({e[1], {adjnode, node}});
                }
            }
        }

        return sum_wt;
    }
};