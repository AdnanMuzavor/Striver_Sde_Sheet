/*
Minimum Platforms
MediumAccuracy: 46.78%Submissions: 100k+Points: 4
Lamp
IT'S THE FINAL DAY OF GEEK WEEK SALE! Ace your Interview Preparation with CIP Course at EXTRA 25% OFF.
Offer Expires Tonight. Click Here to Claim!
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.


Example 1:

Input: n = 6
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation:
Minimum 3 platforms are required to
safely arrive and depart all trains.
Example 2:

Input: n = 3
arr[] = {0900, 1100, 1235}
dep[] = {1000, 1200, 1240}
Output: 1
Explanation: Only 1 platform is required to
safely manage the arrival and departure
of all trains.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findPlatform() which takes the array arr[] (denoting the arrival times), array dep[] (denoting the departure times) and the size of the array as inputs and returns the minimum number of platforms required at the railway station such that no train waits.

Note: Time intervals are in the 24-hour format(HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (this may be > 59).


Expected Time Complexity: O(nLogn)
Expected Auxiliary Space: O(n)


*/

#include <bits/stdc++.h>
using namespace std;
// 0(NlogN)+O(N)

class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // Your code here
        // -> We know that a certain is going to arrive and a certain train is going to leave
        // -> so we dont nee do keep arrivals corresponding to departures
        // -> rather we train comes and prev train (which can be any train) has departed
        // -> then we dont need additional platform while in other case we new train has arive3d
        // -> while any other train has not departed, thn we need an additional platform

        sort(arr, arr + n);
        sort(dep, dep + n);
        int platforms = 1, result = 1; // At beginning we always will need one platform
        int i = 1;                     // a train as arrived at that one platform
        int j = 0;                     // no train has departed yet
        while (i < n && j < n)
        {
            // -> If train i has arrived while a train j was already at platform
            // -> so we need additional platform for this ith train
            // -> hence platforms++, and we go head to look requirement
            // -> of next train
            if (arr[i] <= dep[j])
            {
                platforms++;
                i++;
            }
            // -> else if train has arrived while prev trian had departed
            // -> so we can use same platform for ith train where jth train was present
            // -> so we decrement numbe rof platform
            // -> and we increment j, to know next departure time
            else if (arr[i] > dep[j])
            {
                platforms--;
                j++;
            }
            if (platforms > result)
                result = platforms;
        }
        return result;
    }
};
