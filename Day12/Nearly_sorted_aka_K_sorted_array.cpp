/*

Nearly sorted
MediumAccuracy: 75.25%Submissions: 26K+Points: 4
Lamp
Don't Get Left Behind in the Rapidly Growing Data Science Industry. Try this course!

Given an array of n elements, where each element is at most k away from its target position, you need to sort the array optimally.

Example 1:

Input:
n = 7, k = 3
arr[] = {6,5,3,2,8,10,9}
Output: 2 3 5 6 8 9 10
Explanation: The sorted array will be
2 3 5 6 8 9 10
Example 2:

Input:
n = 5, k = 2
arr[] = {3,1,4,2,5}
Output: 1 2 3 4 5
Note: DO NOT use STL sort() function for this question.

Your Task:
You are required to complete the method nearlySorted() which takes 3 arguments and returns the sorted array.

Expected Time Complexity : O(nlogk)
Expected Auxilliary Space : O(n)

Constraints:
1 ≤ n ≤ 106
1 ≤ k < n
1 ≤ arri ≤ 107
*/

#include <bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return the sorted array.
    vector<int> nearlySorted(int arr[], int num, int K)
    {
        // Brute Force => Sort the array => O(NlogN)
        // Optimised => Use heap

        // which heap?
        //  => Since we start iterating from 0th positionj, we know that minimum element
        //     should come  at position zero
        //  => And since array is k- sorted that means that minimum elemnt will be in window
        //     of size k i.e either at k+1 or k-1 (although k-1 is not applicable to 0)
        //  => Hence once we reach limit of k, that means the last elemnt i.e elemnt at stack
        //     top is our current minimum elemnt to be placed

        priority_queue<int, vector<int>, greater<int>> min_heap;
        vector<int> op(num, 0);
        int sort_index = 0;
        for (int i = 0; i < num; i++)
        {
            min_heap.push(arr[i]);
            if (min_heap.size() > K)
            {
                op[sort_index++] = min_heap.top();
                min_heap.pop();
            }
        }
        while (!min_heap.empty())
        {
            op[sort_index++] = min_heap.top();
            min_heap.pop();
        }
        return op;
    }
};