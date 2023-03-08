/*

947. Most Stones Removed with Same Row or Column
Medium
4.5K
609
Companies
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.



Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.


Constraints:

1 <= stones.length <= 1000
0 <= xi, yi <= 104
No two stones are at the same coordinate point.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findP(vector<int> &p, int node)
    {

        if (p[node] == node)
            return node;
        return p[node] = findP(p, p[node]);
    }
    void union1(vector<int> &p, vector<int> &r, int u, int v)
    {
        int parr_u = findP(p, u);
        int parr_v = findP(p, v);
        cout << "aprr: " << parr_u << " " << parr_v << endl;
        if (parr_u == parr_v)
            return;
        if (r[parr_u] > r[parr_v])
        {
            p[parr_v] = parr_u;
        }
        else if (r[parr_v] > r[parr_u])
        {
            p[parr_u] = parr_v;
        }
        else
        {
            p[parr_u] = parr_v;
            r[parr_v]++;
        }
    }
    int removeStones(vector<vector<int>> &stones)
    {

        // We can consider row and column as a node
        // row from 0 to  max_row_coordinate
        // column from  max_row_cordinate + 1 + col_no

        // Get max_row and max_col with help of corrdinate
        int max_row = 0, max_col = 0;
        for (auto cor : stones)
        {
            max_row = max(max_row, cor[0]);
            max_col = max(max_col, cor[1]);
        }
        cout << max_row << " " << max_col << endl;

        // Hence no of nodes are
        int n = max_row + max_col + 2;
        vector<int> p(n);
        vector<int> r(n, 0);
        for (int i = 0; i < n; i++)
            p[i] = i;

        // NOTE: - THAT all nodex from 0-n doesnt exists, hence some nodes
        //       - if though they are parent of them selves need to be ignored
        //       - Hence we need a map to find out which nodes are and really in used
        unordered_map<int, int> mp; // if mp[node]=1  => node exists!

        // Lets join the components i.e the stones which lie on same
        // row/col can be combined into a single component
        for (auto cor : stones)
        {
            // Combine the row and column nodes into a single component
            int row = cor[0];
            int col = cor[1] + max_row + 1;
            // Nod ewill nbe compined with row
            union1(p, r, row, col);
            // mark existance of row, col node
            mp[row] = 1;
            mp[col] = 1;
        }

        int count = 0; // To find count of ultimate parents

        // Now among all nodes that exists, to fijnd no of components
        // finf the untimate parent/ count_ultimate parents
        for (auto existing_node : mp)
        {
            if (findP(p, existing_node.first) == existing_node.first)
                count++;
        }

        // Hence the number of stone which can be removed
        return stones.size() - count;
    }
};