/*

973. K Closest Points to Origin
Medium
7.1K
259
Companies
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 

Example 1:


Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
 

Constraints:

1 <= k <= points.length <= 104
-104 < xi, yi < 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> op;
        // At max heap when it's size exceeds k we shall pop out the
        // values at top as they will be ones haveing greater distances
        // from the origin, hence first int in first pair is distance
        priority_queue<pair<double,pair<int,int>>> max_heap;
        
        //Iterate through the points
        for(auto pt:points){
            //Push current points and their distnace into the max_heap
            double dist=sqrt((pt[0]*pt[0])+(pt[1]*pt[1]));
            max_heap.push({dist,{pt[0],pt[1]}});
            //Since we want k smallest, pop out the max distanc epoints from top
            if(max_heap.size()>k){
                max_heap.pop();
            }
        }

        //Ans is in the max_heap so extract and use it.
        while(!max_heap.empty()){
            vector<int> temp(2,0);
            auto pt=max_heap.top();
            max_heap.pop();
            temp[0]=pt.second.first;
            temp[1]=pt.second.second;
            op.push_back(temp);
        }
        return op;
    }
};