/*
Number of Ways to Arrive at Destination
MediumAccuracy: 64.31%Submissions: 12K+Points: 4
Lamp
Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!  

You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

Example 1:

Input:
n=7, m=10
edges= [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]

Output:
4
Explaination:

The four ways to get there in 7 minutes are:
- 0  6
- 0  4  6
- 0  1  2  5  6
- 0  1  3  5  6
 

Example 2:

Input:
n=6, m=8
edges= [[0,5,8],[0,2,2],[0,1,1],[1,3,3],[1,2,3],[2,5,6],[3,4,2],[4,5,2]]

Output:
3
Explaination:

The three ways to get there in 8 minutes are:
- 0  5
- 0  2  5
- 0  1  3  4  5
 

Constraints:
1 <= n <= 200
n - 1 <= roads.length <= n * (n - 1) / 2
roads[i].length == 3
0 <= ui, vi <= n - 1
1 <= timei <= 109
ui != vi
There is at most one road connecting any two intersections.
You can reach any intersection from any other intersection.

Expected Time Complexity: O(M * logN + N)
Expected Space Complexity: O(M+N)
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        // We start from source which is zero
        // We have to find number of ways to reach to destination
        
        //Distance vector which can help us to know distance for each node
        vector<long long> dist(n,INT_MAX);
        
        //distance of source is zero
        dist[0]=0;
        
        //Ways vector tell us number of ways we can reach the n- nodes
        vector<int> ways(n,0);
        
        //We can always reach the starting node by one way
        ways[0]=1;
        
        //Principal used
        // -> If we are able to reach a node u from node v then we can conclude that
        //    we can reach node [[ u ]] in as many ways as we cna reach node [[ v ]]
        // -> If dist to reach uth node is same as [ dist of vth node + edge wt between u - v]
        //    then we can say that ways to reach uth node is sum of ways we can reach u and v nodes
        //    as distances are same so we can add up ways we can reach v with ways we can reach u
        
        //Lets process using djikstras algorithm
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,0}); //Node zero with distance zero
        while(!q.empty()){
            auto qtop=q.top();
            int distn=qtop.first;
            int node=qtop.second;
             q.pop();
            if(distn > dist[node]) continue;
           
            // Find adjacent nodes
            for(auto adjs:roads){
                
                // => Get the adjacent node
                int adj_node=-1;
                if(adjs[0]==node) adj_node=adjs[1];
                else if(adjs[1]==node)adj_node=adjs[0];
                
                // => If found follow above principles
                if(adj_node!=-1){
                    //principle point 01
                    if(dist[adj_node]>distn+adjs[2]){
                        dist[adj_node]=distn+adjs[2];
                        ways[adj_node]=ways[node];
                        q.push({dist[adj_node],adj_node});
                    }
                       //principle point 02
                    else if(dist[adj_node]==distn+adjs[2]){
                        ways[adj_node]=(ways[adj_node]+ways[node])%MOD;
                    }
                }
                }
            }
        
       return ways[n-1]; 
        
    }
};