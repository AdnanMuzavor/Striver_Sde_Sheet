/*

703. Kth Largest Element in a Stream
Easy
3.8K
2.3K
Companies
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
 

Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
 

Constraints:

1 <= k <= 104
0 <= nums.length <= 104
-104 <= nums[i] <= 104
-104 <= val <= 104
At most 104 calls will be made to add.
It is guaranteed that there will be at least k elements in the array when you search for the kth element.
*/

#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
///As per given example it's clear that we have to use Min_heap concept
   priority_queue<int,vector<int>,greater<int>> min_heap;
   int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto e:nums){
            min_heap.push(e);
            if(min_heap.size()>k) min_heap.pop();
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        if(min_heap.size()>k) min_heap.pop();
        return min_heap.top();
    }
};