/*
547. Number of Provinces
Medium

4810

229

Add to List

Share
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.



Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
*/
#include <bits/stdc++.h>
using namespace std;

// Without making adjacency matrix:

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &isConnected, vector<int> &vis)
    {
        vis[node] = 1;
        // We know that we have n - nodes
        // so [ONLY IF] there is connection between any of other node
        //  and that other node is not visited we do DFS on that node
        for (int othernode = 0; othernode < isConnected.size(); othernode++)
        {
            if (isConnected[node][othernode] == 1 && !vis[othernode])
            {
                dfs(othernode, isConnected, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // => We can take this problem as a graph problem
        // => Where we need to find the number of components in the graph
        // => this can be done by doing dfs/bfs on each component
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int no_of_p = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, isConnected, vis);
                no_of_p++;
            }
        }
        return no_of_p;
    }
};
class Solution
{
public:
    void dfs(int node, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto e : adj[node])
        {
            if (!vis[e])
            {
                dfs(e, vis, adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // Getting rows and columns
        int rows = isConnected.size();
        int cols = isConnected[0].size();
        // For making adjacency list
        vector<int> adj[rows + 1];
        // To find if there is any node,adjacent to any other node
        int flagadj = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (isConnected[i][j] && i != j)
                {
                    flagadj = 1;
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        // If each node has no adjacent nodes we return rows as answer
        // as it measns non of cities are connected
        if (flagadj == 0)
            return rows;

        for (int i = 0; i <= rows; i++)
        {
            cout << "node is: " << i << " adjacent nides are: ";
            for (auto e : adj[i])
                cout << e << " ";
            cout << endl;
        }
        // count to check for n nodes how many dfs were required to traverse all
        int count = 0;
        // Making visited vector
        vector<int> vis(rows + 1, 0);
        for (int i = 0; i < rows; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj);
                count++;
                cout << "break" << endl;
            }
        }

        // Number of dfs traversal required will be the answer
        return count;
    }
};

// Without usig extra space for creating adjacency list
class Solution
{
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> adj)
    {
        vis[node] = 1;
        for (int j = 0; j < adj[0].size(); j++)
        {
            if (adj[node][j] == 1 && !vis[j])
            {
                dfs(j, vis, adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // Getting rows and columns
        int rows = isConnected.size();
        int cols = isConnected[0].size();

        int count = 0;
        // Making visited vector
        vector<int> vis(rows + 1, 0);
        for (int i = 0; i < rows; i++)
        {
            if (!vis[i])
            {
                cout << "Visiting" << i << endl;
                dfs(i, vis, isConnected);
                count++;
            }
        }

        // Number of dfs traversal required will be the answer
        return count;
    }
};