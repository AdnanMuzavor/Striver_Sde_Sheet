/*
347. Top K Frequent Elements
Medium
12.6K
465
Companies
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.



Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.


Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> mp;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // min heap
        //  Why?  Because we will be adding elemnts in heap based on {frequecy,ele}
        //        hence if frequency is min that elemnt will be at top and since heap size is k
        //        itll would be filtered out.
        priority_queue<mp, vector<mp>, greater<mp>> min_heap;
        vector<int> op;
        // => Find frequency of elements
        // => This will assist in making pairs which we will be pushing into the heap
        unordered_map<int, int> m;
        for (auto n : nums)
        {
            m[n]++;
        }

        // => actual heap procedure, where we are pushing out elemnts at heap top when heap
        //    size beacomes > k, these elemnts popped are one siwth lesser frequency
        for (auto e : m)
        {
            min_heap.push({e.second, e.first});
            if (min_heap.size() > k)
            {
                min_heap.pop();
            }
        }

        //= => Prepare the output
        while (!min_heap.empty())
        {
            op.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return op;
    }
};