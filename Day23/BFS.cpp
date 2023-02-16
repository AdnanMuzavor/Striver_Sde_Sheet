/*

BFS of graph
EasyAccuracy: 44.09%Submissions: 228K+Points: 2
Lamp
Don't Get Left Behind in the Rapidly Growing Data Science Industry. Try this course!

Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.


Example 1:

Input:

Output: 0 1 2 3 4
Explanation:
0 is connected to 1 , 2 , 3.
2 is connected to 4.
so starting from 0, it will go to 1 then 2
then 3.After this 2 to 4, thus bfs will be
0 1 2 3 4.
Example 2:

Input:

Output: 0 1 2
Explanation:
0 is connected to 1 , 2.
so starting from 0, it will go to 1 then 2,
thus bfs will be 0 1 2.

Your task:
You dont need to read input or print anything. Your task is to complete the function bfsOfGraph() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns  a list containing the BFS traversal of the graph starting from the 0th vertex from left to right.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V, E ≤ 104

View Bookmarked Problems
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> op;
        vector<int> vis(V, 0);
        // Below two lines are/must be condiered after confirming that
        // => Given graph has more then 1 componenet
        // => We need not start traversal only from node 0 and w ecan satrt from any node
        // for(int i=0;i<V;i++){
        //     if(!vis[i]){
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while (!q.empty())
        {
            int node = q.front();
            op.push_back(node);
            q.pop();
            for (auto adj_node : adj[node])
            {
                if (!vis[adj_node])
                {
                    vis[adj_node] = 1;
                    q.push(adj_node);
                }
            }
        }
        //     }
        // }
        return op;
    }
};