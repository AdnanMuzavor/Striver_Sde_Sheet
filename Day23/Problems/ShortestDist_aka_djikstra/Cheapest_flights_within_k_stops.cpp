/*

Cheapest Flights Within K Stops
MediumAccuracy: 49.41%Submissions: 6K+Points: 4
Lamp
Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!

There are n cities and m edges connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from the city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Example 1:
Input:
n = 4
flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
src = 0
dst = 3
k = 1
Output:
700
Explanation:
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

Constraint:
1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between the two cities.
0 <= src, dst, k < n
src != dst
*/

#include <bits/stdc++.h>
using namespace std;

#define ppi pair<int, pair<int, int>>
class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int des, int K)
    {
        // Code here
        vector<vector<int>> dist(n, vector<int>(K + 1, INT_MAX)); // Initally all have disatnce of MAX

        // => source will always have distance of zero from it self
        dist[src][0] = 0;

        // => Since finding min_dist, we need a min_heap
        priority_queue<ppi, vector<ppi>, greater<ppi>> q;

        // => 1) distance 2) node [src_node initially] 3) edges in between
        // => i.e is number of edges to reach node => there will be [edges-1] stops in between

        q.push({0, {src, 0}});
        while (!q.empty())
        {
            auto tp = q.top();
            q.pop();
            int distn = tp.first;
            int node = tp.second.first;

            // Third para tell number number of edges from source to reach node
            // Hence number of stops will be number of edges - 1
            int edges_bet = tp.second.second;

            int stops = edges_bet - 1;

            // if curr_Stops+1 [1 is current node as stop to reach adj nodes] are > k
            // there is even no need to process further
            if (stops + 1 > K)
                continue;

            // else find adjacent nodes and modfi distance between them
            // if distance is decreasing push them into queue with increment in number of stops
            for (auto e : flights)
            {
                if (e[0] == node)
                {
                    // => We are not just looking for distance but disatnce with atmost k stops
                    // => else it may happen that for a node with ahve minimum disatnce but this min distance is
                    // => result of having many nodes [STOPS] in between which we really dont want
                    // => Hence we have made distance array 2d
                    if (dist[e[1]][stops + 1] > distn + e[2])
                    {
                        dist[e[1]][stops + 1] = distn + e[2];
                        q.push({dist[e[1]][stops + 1], {e[1], edges_bet + 1}});
                    }
                }
            }
        }
        if (dist[des][K] == INT_MAX || dist[des][K] < 0)
            return -1;
        return dist[des][K];
    }
};