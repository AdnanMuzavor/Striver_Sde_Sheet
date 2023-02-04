/*
Sort an array of 0s, 1s and 2s
Easy Accuracy: 51.36% Submissions: 100k+ Points: 2
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


Example 1:

Input:
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated
into ascending order.
Example 2:

Input:
N = 3
arr[] = {0 1 0}
Output:
0 0 1
Explanation:
0s 1s and 2s are segregated
into ascending order.

Your Task:
You don't need to read input or print anything. Your task is to complete the function sort012() that takes an array arr and N as input parameters and sorts the array in-place.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


*/

#include <iostream>
using namespace std;

class Solution
{
public:
    void sort012(int a[], int n)
    {
        // code here
        int i = 0, j = n - 1, m = 0;

        // Brute force ->Count the number of each and place in array accordingly
        // int c0=0,c1=0,c2=0;
        //  for(i=0;i<n;i++){
        //      if(a[i]==0) c0++;
        //      else if(a[i]==1) c1++;
        //      else c2++;
        //  }
        //  for(i=0;i<c0;i++) a[i]=0;
        //  for(i=c0;i<c1+c0;i++)a[i]=1;
        //  for(i=c0+c1;i<c1+c2+c0;i++) a[i]=2;

        // Optimised->Two pointer appraoch
        while (i <= j)
        {
            // cout<<a[i]<<endl;
            if (a[i] == 0)
            {
                int temp = a[m];
                a[m] = a[i];
                a[i] = temp;
                m++;
                i++;
            }
            else if (a[i] == 2)
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
                j--;
            }
            else
            {
                i++;
            }
        }
    }
};