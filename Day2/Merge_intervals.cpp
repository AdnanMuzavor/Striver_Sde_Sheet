/*
56. Merge Intervals
Medium

15682

562

Add to List

Share
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.



Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.


Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/
// TC-> O(N+NlogN) as we are given with N intervals,a dn we are Sorting N intervals
// SC-> O(2*N) for output vector
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> op;
        // Concept if we have two intervals say:
        //[a,b][c,d]
        // then we can combine them if and only if
        //  b<=c
        // Hence [a,b] after combining

        // In order to ensure that we dont miss
        // combining any interval, we can choose
        // to sort to them to take care of edge cases

        sort(intervals.begin(), intervals.end());

        // Now we can choose frist pair as reference pair
        // Then we can go adding to it as much as we can
        vector<int> p = intervals[0];

        // Iterate for rest of the pairs
        for (int i = 1; i < intervals.size(); i++)
        {
            // We can combine the currnet pair
            if (intervals[i][0] <= p[1])
            {
                p[1] = max(p[1], intervals[i][1]);
            }
            // We cannot combine the pair,so we have our combined interval in  p
            // So we add p to soln, and take current apir as refernce pair
            else
            {
                op.push_back(p);
                p = intervals[i];
            }
        }
        // Add the last pair which is in p
        op.push_back(p);

        // return the answer
        return op;
    }
};