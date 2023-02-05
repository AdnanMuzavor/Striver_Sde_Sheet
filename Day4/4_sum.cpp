/*
18. 4Sum
Medium

7401

866

Add to List

Share
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.



Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]


Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

#include <bits/stdc++.h>
using namespace std;

// Brute force  => RUN TIME ERROR
// TC -> O(N^4 * 4log4 * log(set_size))
// SC -> O(4*N) for set which stored vector of size 4
/*
INPUT: [1000000000,1000000000,1000000000,1000000000]
        0

Line 16: Char 55: runtime error: signed integer overflow: 2000000000 + 1000000000 cannot be represented in type 'int' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:25:55


*/

// Brute force in different code pattern
// O(N^4 * 4log4 *logN)
//  N^4 ->  4 loops
//  4log4 ->sorting temp
//  logN  -> Insertion in set

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> op;
        set<vector<int>> st; // To prevent duplicate copies
        int n = nums.size();
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                for (int k = j + 1; k < n - 1; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        // Take care theta elemnts are unique
                        if (((long long int)nums[i] + (long long int)nums[j] + (long long int)nums[k] + (long long int)nums[l]) == (long long int)target)
                        {
                            vector<int> curr;
                            curr.push_back(nums[i]);
                            curr.push_back(nums[j]);
                            curr.push_back(nums[k]);
                            curr.push_back(nums[l]);
                            // To prevent duplicates
                            sort(curr.begin(), curr.end());
                            st.insert(curr);
                        }
                    }
                }
            }
        }
        // Put unque eleemts in o/p
        for (auto e : st)
            op.push_back(e);
        return op;
    }
};

// O(NlogN+ N^3 * 4log4 *logN * log(set_size))
//  N^3 ->  3 loops
//  4log4 ->sorting temp
//  log(Set_size)  -> Insertion in set
// logN  -> Binary search
//  => O(N^3*LogN)

// SC -> O(N*4 + N*4)
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // Sort vectr to use logN for finding last element
        sort(nums.begin(), nums.end());

        vector<vector<int>> op;
        vector<int> temp;
        int n = nums.size();

        set<vector<int>> st; // For unique pairs

        for (int i = 0; i < n - 3; i++)
        {

            for (int j = i + 1; j < n - 2; j++)
            {

                for (int k = j + 1; k < n - 1; k++)
                {

                    long long int new_target = (long long int)target - (long long int)nums[i] - (long long int)nums[j] - (long long int)nums[k];

                    // We can find the third eleemnt by7 Binary serach
                    // Which will reduce TC from O(N^4) to O(N^3*logN)

                    int l = k + 1, h = n - 1;
                    while (l <= h)
                    {
                        int mid = (l + h) / 2;
                        if (nums[mid] == new_target)
                        {
                            // Push eleemnts into the vector
                            temp.push_back(nums[i]);
                            temp.push_back(nums[j]);
                            temp.push_back(nums[k]);
                            temp.push_back(nums[mid]);

                            // Sort vector to assist set with unique solns
                            sort(temp.begin(), temp.end());

                            // Push into the set
                            st.insert(temp);

                            // clear temp for next iteration
                            temp.clear();
                        }
                        if (nums[mid] > new_target)
                            h = mid - 1;
                        else
                            l = mid + 1;
                    }
                }
            }
        }
        // st has all UNIQUE solutions, push them into the op
        for (auto e : st)
            op.push_back(e);
        return op;
    }
};

// OPTIMISED

// O(NlogN+ N^3 * 4log4)
//  N^3 ->  3 loops
//  NlogN -> for sorting
//  => O(N^3)

// SC -> O(N*4)
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // Sort vectr to use logN for finding last element
        sort(nums.begin(), nums.end());

        vector<vector<int>> op;
        vector<int> temp;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {

            for (int j = i + 1; j < n; j++)
            {
                // Since array is sorted, why not to use two pointer appraoch
                // That is high and low pointers
                // Such that if summation is greater then target we will reduce high
                // Such that if summation is lesser then target we will increase low
                long long int new_target = (long long int)target - (long long int)nums[i] - (long long int)nums[j];
                int low = j + 1, high = n - 1;
                while (low < high)
                {

                    int two_sum = nums[low] + nums[high];

                    if (two_sum == new_target)
                    {
                        // Push eleemnts into the vector
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);

                        op.push_back(temp);

                        // As array is sorted, it might happen
                        // that nexyt iteration will give same element
                        // Hence to avoid duplicates, lets update high and low

                        // Now if elements are same keep moving low ahead
                        while (low < high && nums[low] == temp[2])
                            low++;

                        // Now if elements are same keep moving high behind
                        while (high > low && nums[high] == temp[3])
                            high--;

                        // clear temp for next iteration
                        temp.clear();
                    }
                    else if (two_sum < new_target)
                        low++;
                    else
                        high--;
                }
                // It should not take same j again
                while (j + 1 < n && nums[j + 1] == nums[j])
                    j++;
            }
            // It should not take same i again
            while (i + 1 < n && nums[i + 1] == nums[i])
                i++;
        }

        return op;
    }
};
