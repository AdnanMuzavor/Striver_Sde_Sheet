/*
Stock buy and sell
Medium Accuracy: 39.53% Submissions: 79725 Points: 4
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.
The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.
Note: There may be multiple possible solutions. Return any one of them. Any correct solution will result in an output of 1, whereas wrong solutions will result in an output of 0.

Example 1:

Input:
N = 7
A[] = {100,180,260,310,40,535,695}
Output:
1
Explanation:
One possible solution is (0 3) (4 6)
We can buy stock on day 0,
and sell it on 3rd day, which will
give us maximum profit. Now, we buy
stock on day 4 and sell it on day 6.
Example 2:

Input:
N = 5
A[] = {4,2,2,2,4}
Output:
1
Explanation:
There are multiple possible solutions.
one of them is (3 4)
We can buy stock on day 3,
and sell it on 4th day, which will
give us maximum profit.

Your Task:
The task is to complete the function stockBuySell() which takes an array A[] and N as input parameters and finds the days of buying and selling stock. The function must return a 2D list of integers containing all the buy-sell pairs i.e. first value of pair will represent the day on which you buy the stock and second value represent the day on which you sell that stock. If there is No Profit, return an empty list.



Note: Since there can be multiple solutions, the driver code will return 1 if your answer is correct, otherwise, it will return 0. In case there's no profit the driver code will return the string "No Profit" for a correct solution.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the days of buying and selling stock for max profit.
    vector<vector<int>> stockBuySell(vector<int> arr, int n)
    {
        // code here
        // Basically we have to buy at local minima and sell at local maxima
        // So as to gain maximum of profit
        vector<vector<int>> op;
        // Upto n-1 because we might buy at n-2th and sell at n-1th element
        // Hence we can chopose to but at n-1th element as it last element
        for (int i = 0; i < n - 1; i++)
        {
            // If arr[i]>=arr[i+1] thn its not local minima
            // Hemce we will definitely not buy at this point
            if (arr[i] >= arr[i + 1])
                continue;
            // ELse if(arr[i)<arr[i+1] means it is local minima and we can buy at this point
            vector<int> temp;
            temp.push_back(i);
            // Now we need to find local maxima at which we can sell this stock
            while (i + 1 < n && arr[i] < arr[i + 1])
                i++;
            temp.push_back(i);
            // Hence we push pair into answer and start with next point
            op.push_back(temp);
        }
        return op;
    }
};
