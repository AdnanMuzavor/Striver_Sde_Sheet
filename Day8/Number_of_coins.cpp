/*
Number of Coins
MediumAccuracy: 47.78%Submissions: 70119Points: 4
Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then return -1.


Example 1:

Input: V = 30, M = 3, coins[] = {25, 10, 5}
Output: 2
Explanation: Use one 25 cent coin
and one 5 cent coin
Example 2:
Input: V = 11, M = 4,coins[] = {9, 6, 5, 1}
Output: 2
Explanation: Use one 6 cent coin
and one 5 cent coin

Your Task:
You don't need to read input or print anything. Complete the function minCoins() which takes V, M and array coins as input parameters and returns the answer.

Expected Time Complexity: O(V*M)
Expected Auxiliary Space: O(V)

Constraints:
1 ≤ V*M ≤ 106
*/
#include <bits/stdc++.h>
using namespace std;
// This will not work as it'll always need dp
// But a shumans w ecan uise this in real life
// O(NLogN)
// O(N)
class Solution
{

public:
    int minCoins(int coins[], int M, int V)
    {
        // Your code goes here
        sort(coins, coins + M);
        int i = M, ans = -1;
        for (i = M - 1; i >= 0; i--)
        {
            if (coins[i] <= V)
            {
                if (ans == -1)
                    ans = 0;
                int taking = (V / coins[i]); /// Taking maximum numbe rof coins of this denominations
                V = V - (coins[i] * taking); /// Subtract the corresponding amount
                ans = ans + taking;          /// update the answer
            }
        }
        if (V != 0)
            return -1;
        return ans;
    }
};

// Hence dp is used(Refer MIN COINS PROBLEM FROM SUBSETS BASED SECTION IN DP)

class Solution
{

public:
    int helper(int amount, int coins[], int i, vector<vector<int>> &dp)
    {
        if (amount == 0)
            return 0;
        if (i == 0)
        {
            if (amount % coins[0] == 0)
            {
                return (amount / coins[i]);
            }
            return 100000;
        }
        if (dp[i][amount])
            return dp[i][amount];
        // Not at all taking this coin
        int not_take = helper(amount, coins, i - 1, dp);
        int take = INT_MAX;
        if (coins[i] <= amount)
        {
            take = 1 + helper(amount - coins[i], coins, i, dp); // I can take the same coin again
        }
        return dp[i][amount] = min(not_take, take);
    }
    int minCoins(int coins[], int M, int V)
    {
        // Your code goes here
        vector<vector<int>> dp(M + 1, vector<int>(V + 1, 0));
        int ans = helper(V, coins, M - 1, dp);
        if (ans == 100000)
            return -1;
        return ans;
    }
};