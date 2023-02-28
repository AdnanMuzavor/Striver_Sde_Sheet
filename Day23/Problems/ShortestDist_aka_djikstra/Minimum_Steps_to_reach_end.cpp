/*
Minimum Multiplications to reach End
MediumAccuracy: 45.42%Submissions: 9K+Points: 4
Lamp
Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!

Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

Example 1:

Input:
arr[] = {2, 5, 7}
start = 3, end = 30
Output:
2
Explanation:
Step 1: 3*2 = 6 % 100000 = 6
Step 2: 6*5 = 30 % 100000 = 30
Example 2:

Input:
arr[] = {3, 4, 65}
start = 7, end = 66175
Output:
4
Explanation:
Step 1: 7*3 = 21 % 100000 = 21
Step 2: 21*3 = 6 % 100000 = 63
Step 3: 63*65 = 4095 % 100000 = 4095
Step 4: 4095*65 = 266175 % 100000 = 66175
Your Task:

You don't need to print or input anything. Complete the function minimumMultiplications() which takes an integer array arr, an integer start and an integer end as the input parameters and returns an integer, denoting the minumum steps to reach in which end can be achieved starting from start.

Expected Time Complexity: O(105)

Expected Space Complexity: O(105)

Constraints:

1 <= n and n <= 104
1 <= arr[i] and arr[i] <= 104
1 <= start, end < 105
View Bookmarked Problems

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        // => This can be solved using djikstra's algorithm
        // => Given that value will enever exceed beyond 100000
        // => We can assume that there are 100000 nodes and source
        // => is the node with the start value

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> dist(100000, INT_MAX);
        dist[start] = 0;
        int minsteps = INT_MAX;
        q.push({0, start});
        while (!q.empty())
        {
            int steps = q.top().first;
            int value = q.top().second;
            q.pop();

            for (int i = 0; i < arr.size(); i++)
            {
                int node = (value * arr[i]) % 100000;
                // cout<<node<<" ";
                if (dist[node] > steps + 1)
                {
                    dist[node] = steps + 1;
                    if (node == end)
                        return dist[node];
                    q.push({steps + 1, node});
                }
            }
        }
        return -1;
    }
};