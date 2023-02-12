/*

Maximum Sum Combination
MediumAccuracy: 27.37%Submissions: 832+Points: 4
Lamp
Don't Get Left Behind in the Rapidly Growing Data Science Industry. Try this course!

Given two integer array A and B of size N each.
A sum combination is made by adding one element from array A and another element of array B.
Return the maximum K valid distinct sum combinations from all the possible sum combinations.

Note : Output array must be sorted in non-increasing order.

Example 1:

Input:
N = 2
C = 2
A [ ] = {3, 2}
B [ ] = {1, 4}
Output: {7, 6}
Explanation:
7 -> (A : 3) + (B : 4)
6 -> (A : 2) + (B : 4)
Example 2:

Input:
N = 4
C = 3
A [ ] = {1, 4, 2, 3}
B [ ] = {2, 5, 1, 6}
Output: {10, 9, 9}
Explanation:
10 -> (A : 4) + (B : 6)
9 -> (A : 4) + (B : 5)
9 -> (A : 3) + (B : 6)


Your Task:
You don't need to read input or print anything. Your task is to complete the function maxCombinations() which takes the interger N,integer K and two integer arrays A [ ] and B [ ] as parameters and returns the maximum K valid distinct sum combinations .

Expected Time Complexity: O(Klog(N))
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤  105
1 ≤ K ≤  N
1 ≤ A [ i ] , B [ i ] ≤ 1000
*/

#include <bits/stdc++.h>
using namespace std;

// Optimised using heap
class Solution
{
public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B)
    {
        // code here
        vector<int> op;
        priority_queue<pair<int, pair<int, int>>> max_heap;

        // Sort the arrays
        //  => After sorting maximum values of both arrays will be at array end
        //     hence by combining these elements we will be able to form our very first
        //     maximum sum pair
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        // Get the first pair
        max_heap.push({A[N - 1] + B[N - 1], {N - 1, N - 1}});

        // Maintain a set to make sure that we dont consider same pair again
        set<pair<int, int>> st;
        // Save it's indexes in set to avoid same pair of indices again
        st.insert({N - 1, N - 1});
        // Get k combinations
        while (K--)
        {
            auto top = max_heap.top();
            max_heap.pop();
            // Since max heap , maximum sum elemnt will always be at top
            op.push_back(top.first);
            // Save it's indexes in set to avoid same pair of indices again
            int L = top.second.first;
            int R = top.second.second;
            // => Check if L and R are valid and that these L and R are not previsouly selected
            //    elements
            if (L > 0 && R > 0)
            {
                // Check if diagonal wrt current L and R not previously considered
                if (st.find(make_pair(L - 1, R)) == st.end())
                {
                    max_heap.push({A[L - 1] + B[R], {L - 1, R}});
                    st.insert({L - 1, R});
                }
                if (st.find(make_pair(L, R - 1)) == st.end())
                {
                    max_heap.push({A[L] + B[R - 1], {L, R - 1}});
                    st.insert({L, R - 1});
                }
            }
        }
        return op;
    }
};

// Brute force using Heap
class Solution
{
public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B)
    {
        // code here
        vector<int> op;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (auto n1 : A)
        {
            for (auto n2 : B)
            {
                min_heap.push(n1 + n2);
                if (min_heap.size() > K)
                {
                    min_heap.pop();
                }
            }
        }
        while (!min_heap.empty())
        {
            op.push_back(min_heap.top());
            min_heap.pop();
        }
        reverse(op.begin(), op.end());
        return op;
    }
};