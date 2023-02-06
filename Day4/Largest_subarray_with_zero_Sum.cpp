/*
Largest subarray with 0 sum
EasyAccuracy: 46.94%Submissions: 100k+Points: 2
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.

Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N*log(N)).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
-1000 <= A[i] <= 1000, for each valid i
*/

#include <bits/stdc++.h>
using namespace std;
// O(N^3)
// O(1)
class Solution
{
public:
    // If sum between i to j is zero, it returns length
    // else returns zero i.e min_length
    int give_len(vector<int> a, int i, int j)
    {
        int len = 0, s = 0;
        for (int l = i; l <= j; l++)
        {
            s += a[l];
        }
        if (s == 0)
            return j - i + 1;
        else
            return 0;
    }

    int maxLen(vector<int> &A, int n)
    {
        // BRUTE FORCE
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int len = give_len(A, i, j);
                ans = max(ans, len);
            }
        }
        return ans;
    }
};

// TC -> O(NlogN)
// N -> for traversing the array
// logN -> for getting result from map rgearding occurence of sum

// SC -> O(N)
class Solution
{
public:
    int maxLen(vector<int> &nums, int n)
    {
        // Your code here

        unordered_map<int, int> mp; // To keep track of every occurence of sum

        int max_len = 0; // To keep record of maximum length

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sum == 0)
            {
                // If at any point we get sum zero
                // we consider it as sum from beginning and try to get max length
                max_len = max(max_len, i - 0 + 1);
            }

            // If we had got the sum previously
            if (mp.count(sum))
            {
                // That means it's this condition
                /*     _______________S___________________i
                     |                                   |
                      ______S_______j________0___________

                      i.e we got sum = S again, that mrans right from current i
                      till last occurence of sum that is j
                      => i.e from [ j to i ] sum is zero
                      =>Hence we update the max_length
                 */
                max_len = max(max_len, (i - mp[sum]));
            }
            // Else map the current occurence of sum
            // we are not going to update sum's occurence index to current index
            //  because we want amx_len not minlen
            else
            {
                mp[sum] = i;
            }
        }

        return max_len;
    }
};