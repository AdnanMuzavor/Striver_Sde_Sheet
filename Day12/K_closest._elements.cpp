/*
658. Find K Closest Elements
Medium
6.6K
538
Companies
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b


Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]


Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &nums, int k, int x)
    {
        // => Again concept of heap come here
        // => as we are given k
        // => However here we are going to use the abs diff between
        //   each array element and the given x to arrange our heap values
        /*
         Say array is   :  5 6 7 8 9  k=3 x=7
         abs diff with 7:  2 1 0 1 2

         Hence if we use max_heap maximum key values will be at top which
         we shall pop out and min_key vales will be left in heap giving us our answer
         hence we use max_heap here
         ______________________________________________________________________
               5 6 7 8 9
               2 1 0 1 2
               |

               Heap:

               |   |
               |   | k
               |   |
               |2,5|
         ______________________________________________________________________
         ______________________________________________________________________
               5 6 7 8 9
               2 1 0 1 2
                 |

               Heap:

               |   |
               |   | k
               |2,5|
               |1,6|
         ______________________________________________________________________
          ______________________________________________________________________
               5 6 7 8 9
               2 1 0 1 2
                   |

               Heap:

               |   |
               |2,5|k
               |1,6|
               |0,7|
         ______________________________________________________________________
           ______________________________________________________________________
               5 6 7 8 9
               2 1 0 1 2
                     |

               Heap:


               |2,5| <= pop out
               |1,8|k
               |1,6|
               |0,7|
         ______________________________________________________________________
           ______________________________________________________________________
               5 6 7 8 9
               2 1 0 1 2
                       |

               Heap:


               |2,9| <= pop out
               |1,8|k
               |1,6|
               |0,7|
         ______________________________________________________________________
           ______________________________________________________________________
               5 6 7 8 9
               2 1 0 1 2
                       |

               Heap:
               = >    R E S U L T   H E A P     < =

               |1,8|k
               |1,6|
               |0,7|
         ______________________________________________________________________


        */

        priority_queue<pair<int, int>> max_heap;
        for (int i = 0; i < nums.size(); i++)
        {
            max_heap.push({abs(nums[i] - x), nums[i]});
            if (max_heap.size() > k)
            {
                max_heap.pop();
            }
        }
        vector<int> op;
        while (!max_heap.empty())
        {
            op.push_back(max_heap.top().second);
            max_heap.pop();
        }
        sort(op.begin(), op.end());
        return op;
    }
};