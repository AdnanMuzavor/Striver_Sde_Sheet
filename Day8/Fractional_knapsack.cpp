/*
Fractional Knapsack
MediumAccuracy: 45.14%Submissions: 100k+Points: 4
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item.



Example 1:

Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack.
Example 2:

Input:
N = 2, W = 50
values[] = {60,100}
weight[] = {10,20}
Output:
160.00
Explanation:
Total maximum value of item
we can have is 160.00 from the given
capacity of sack.


Your Task :
Complete the function fractionalKnapsack() that receives maximum capacity , array of structure/class and size n and returns a double value representing the maximum value in knapsack.
Note: The details of structure/class is defined in the comments above the given function.


Expected Time Complexity : O(NlogN)
Expected Auxilliary Space: O(1)


Constraints:
1 <= N <= 105
1 <= W <= 105

*/
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    // comapartor
    static int comp(Item a, Item b)
    {
        double a1 = ((double)a.value / (double)a.weight);
        double b1 = ((double)b.value / (double)b.weight);
        return (a1 > b1);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // sort array as per decreasing order of profit per weight
        sort(arr, arr + n, comp);
        // declare profit and cap vars
        int curr_Wt = 0;
        double profit = 0.0;
        // ietrate through each of teh element
        for (int i = 0; i < n; i++)
        {
            if (curr_Wt + arr[i].weight <= W)
            {
                // Add the item into the knapsack
                curr_Wt += arr[i].weight;
                profit += arr[i].value;
            }
            else
            {
                // Add only the fractio  of iotem into the knapack
                int rem_cap = W - curr_Wt;
                profit += (arr[i].value / (double)arr[i].weight) * (double)rem_cap;
                break;
            }
        }
        return profit;
    }
    //         bool static comp(Item a, Item b) {
    //          double r1 = (double) a.value / (double) a.weight;
    //          double r2 = (double) b.value / (double) b.weight;
    //          return r1 > r2;
    //       }
    //   // function to return fractionalweights
    //   double fractionalKnapsack(int W, Item arr[], int n) {

    //       sort(arr, arr + n, comp);

    //       int curWeight = 0;
    //       double finalvalue = 0.0;

    //       for (int i = 0; i < n; i++) {

    //          if (curWeight + arr[i].weight <= W) {
    //             curWeight += arr[i].weight;
    //             finalvalue += arr[i].value;
    //          } else {
    //             int remain = W - curWeight;
    //             finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
    //             break;
    //          }
    //       }

    //       return finalvalue;

    //   }
};
