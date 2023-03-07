/*
Number Of Islands
MediumAccuracy: 60.65%Submissions: 15K+Points: 4
Participate in Monthly Hiring Challenge conducted by GeeksforGeeks !!

You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.
Note : An island means group of 1s such that they share a common side.



Example 1:

Input: n = 4
m = 5
k = 4
A = {{1,1},{0,1},{3,3},{3,4}}

Output: 1 1 2 2
Explanation:
0.  00000
    00000
    00000
    00000
1.  00000
    01000
    00000
    00000
2.  01000
    01000
    00000
    00000
3.  01000
    01000
    00000
    00010
4.  01000
    01000
    00000
    00011




Example 2:

Input: n = 4
m = 5
k = 4
A = {{0,0},{1,1},{2,2},{3,3}}

Output: 1 2 3 4
Explanation:
0.  00000
    00000
    00000
    00000
1.  10000
    00000
    00000
    00000
2.  10000
    01000
    00000
    00000
3.  10000
    01000
    00100
    00000
4.  10000
    01000
    00100
    00010


Your Task:
You don't need to read or print anything. Your task is to complete the function numOfIslands() which takes an integer n denoting no. of rows in the matrix, an integer m denoting the number of columns in the matrix and a 2D array of size k denoting  the number of operators.

Expected Time Complexity: O(m * n)
Expected Auxiliary Space: O(m * n)

Constraints:

1 <= n,m <= 100
1 <= k <= 1000
*/

#include <bits/stdc++.h>
using namespace std;
//My Code
class Solution {
  public:
    int findP(vector<int> &p,int node){
        if(p[node]==node) return node;
        else return p[node]=findP(p,p[node]);
    }
    void union1(vector<int> &rank,vector<int> &p,int u,int v){
        int parr_u=findP(p,u);
        int parr_v=findP(p,v);
        if(parr_u==parr_v) return;
        if(rank[parr_u]>rank[parr_v]){
            p[parr_v]=parr_u;
        }
        else if(rank[parr_v]>rank[parr_u]){
            p[parr_u]=parr_v;
        }
        else{
            p[parr_u]=parr_v;
            rank[parr_v]++;
        }
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        int nodes=n*m;
        vector<int> p(nodes);
        
        vector<int> rank(nodes);
        
        vector<int> op;
        
        int vis[n][m];
        
        memset(vis,0,sizeof vis);
        
        int cnt=0;
        
        for(int i=0;i<nodes;i++) {p[i]=i;rank[i]=0;}
        
        for(auto it:operators){
            
            int r=it[0];
            int c=it[1];
            
            //If visisted we can push_back same count 
            if(vis[r][c]==1){
                op.push_back(cnt);
                continue;
            }
            
            //Else mark it visited
            vis[r][c]=1;
            
            //Initially consider it as individual so increment cnt by 1
            cnt++;
            
            //Try conncting it with neighbors
            int d1[4]={0,1,-1,0};
            int d2[4]={1,0,0,-1};
            for(int i=0;i<4;i++){
                int nr=r+d1[i];
                int nc=c+d2[i];
                //Invalid
                if(nr<0 || nr>=n || nc<0 || nc>=m ) continue;
                //Check if neighbors are visited
                if(vis[nr][nc]==1){
                    // => Check if Current node and neighbor belong to same component or not
                    
                    // => This check will be useful in second run when we are going to append current node 
                    //    to one of it's neighboring component as node should not be attched to same
                    //    component again
                    int curr_node=r*m+c;
                    int neighbor=nr*m+nc;
                    if(findP(p,curr_node)!=findP(p,neighbor)){
                       // cout<<"Unioning: "<<curr_node<<" => "<<neighbor<<endl;
                        //=> As node belong to compont , its obvios that the componnet has already been counted
                        //   hence we decrease the count
                        cnt--;
                        //Connect them both
                        // union1(vector<int> &rank,vector<int> &p,int u,int v)
                        union1(rank,p,curr_node,neighbor);
                    }
                }
            }
            
            //push count into op
            op.push_back(cnt);
        }
        return op;
        
    }
};

//Striver Code
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    bool isValid(int adjr, int adjc, int n, int m)
    {
        return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        DisjointSet ds(n * m);
        int vis[n][m];
        memset(vis, 0, sizeof vis);
        int cnt = 0;
        vector<int> ans;
        for (auto it : operators)
        {
            int row = it[0];
            int col = it[1];
            if (vis[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            // row - 1, col
            // row , col + 1
            // row + 1, col
            // row, col - 1;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for (int ind = 0; ind < 4; ind++)
            {
                int adjr = row + dr[ind];
                int adjc = col + dc[ind];
                if (isValid(adjr, adjc, n, m))
                {
                    if (vis[adjr][adjc] == 1)
                    {
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjr * m + adjc;
                        if (ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo))
                        {
                            cnt--;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
