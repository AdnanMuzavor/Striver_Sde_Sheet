/*
City With the Smallest Number of Neighbors at a Threshold Distance
MediumAccuracy: 37.51%Submissions: 6K+Points: 4
Lamp
Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!

There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi , toi ,weighti]  represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distance Threshold. You need to find out a city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance, If there are multiple such cities, our answer will be the city with the greatest number.

Note: that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

Example 1:

Input:
N=4,M=4
edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]]
distanceThreshold = 4
Output:3
Explaination:The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2]
City 1 -> [City 0, City 2, City 3]
City 2 -> [City 0, City 1, City 3]
City 3 -> [City 1, City 2]
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findCity( ) which takes a No of nodes N and vector of edges and ThresHold Distance. and Return the city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance, If there are multiple such cities, return the city with the greatest number.

Expected Time Complexity: O(V^2 + EVlogV)
Expected Auxiliary Space:  O(N^3)


Constraints:
1 ≤ N≤ 100
1 <= edges.length <= n*(n-1)/2
edges[i].length == 3
0 <= fromi < toi < n
1 <= weight, distanceThreshold <= 10^4
All pairs (fromi, toi) are distinct
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findCity(int n, int m, vector<vector<int>> &edges,
                 int td)
    {
        vector<vector<int>> matrix(n, vector<int>(n, INT_MAX));
        for (auto e : edges)
        {
            matrix[e[0]][e[1]] = e[2];
            matrix[e[1]][e[0]] = e[2];
        }
        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][via] != INT_MAX && matrix[via][j] != INT_MAX)
                    {
                        matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                    }
                }
            }
        }
        //  for(int i=0;i<n;i++){
        //         for(int j=0;j<n;j++){
        //            cout<<
        //         }
        //     }
        int ans = 0, min_count = INT_MAX;
        for (int via = 0; via < n; via++)
        {
            int c = 0;
            for (int adjnode = 0; adjnode < n; adjnode++)
            {
                if (adjnode != via && matrix[via][adjnode] <= td)
                {
                    c++;
                }
            }
            //  cout<<" could reach "<<c<<" cities from "<<via<<endl;
            if (c <= min_count)
            {
                min_count = c;
                ans = via;
            }
        }
        return ans;
    }
};