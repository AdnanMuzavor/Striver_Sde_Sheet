/*

4. Median of Two Sorted Arrays
Hard
20.6K
2.3K
Companies
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &arr1, vector<int> &arr2)
    {
        // Brute force O((N+M)/2)=>  O(N+M)

        // Since we need median

        // THere are two cases:

        // Sum of sizes of both arrays is even
        // a1= 1 2 3 4 5
        // a2= 6 7 8 9 10
        // median=(5+6)/2=5

        // Sum of sizes of both arrays is odd
        // a1= 1 2 3 4
        // a2= 6 7 8 9 10
        // median=6

        // But arrays wont be given in this way
        // Both arrays will be sorted

        // Consider:EVEN SIZE EXAMPLE
        // arr[] = {1,5,8,10},
        // brr[] = {2,6,10,18}
        // Clearly after combining: we get : 1 2 5 6 8 10 10 12
        // median=(8+6)/2=07

        // Consider:ODD SIZE EXAMPLE
        // arr[] = {1,5,8},
        // brr[] = {2,6,10,18}
        // Clearly after combining: we get : 1 2 5 6 8 10 12
        // median=06

        /*******************************************************************/
        // Lets appraoch the solution
        // Since array is sorted we can directly use two pointers
        /********************************************************************/
        // But how much to travel?
        // Its obvious that if size=n
        // If n is thn median is arr[n/2]+arr[n/2-1]
        // if n is odd median is arr[n/2]
        // So in both cases we need to trace uptill n/2

        // hemce loop => for(int i=0;i<=(n+m)/2;i++)
        /*******************************************************************/

        // Now how to use the pointers?
        // Its obvios that we need smallest element i.e although two arrays
        // we need to find median considering both arrays as joined
        double currmed = 0, prevmed = 0, n = arr1.size(), m = arr2.size();
        int i = 0, j = 0;
        for (int k = 0; k <= (m + n) / 2; k++)
        {

            // Prev med will have median value at arr[(n/2)-1], where qrr-> combined sorted array
            prevmed = currmed;
            // Now we need to find curr median i.emedian at arr[n/2] where arr->  combined sorted array

            /*********
            If you forget why currmed is iniyialise like this
            Take exmaple of
            arr1=[1]
            arr2=[2]

            ///m+n=2
            //Therefore 2/2=1 interations to be done
            //i.e 0th and 1th interation

            //0th
            //prevmed=0
            //i<n && j<m
            //currmed=min(1,2)=1
            //hence i++ , i=1

            //1th
            //prevmed=1
            //i==n && j<m
            //currmed=arr[j]=2

            //Loop Over
            //Output
            //Since array size total=even
            // return (prevmed+currmed)/2 => (1+2)/2=1


            **********/
            // Case1, both pointer are valid yet
            if (i < n && j < m)
            {
                currmed = arr1[i] < arr2[j] ? arr1[i++] : arr2[j++];
            }
            // Case2, arr1 is fully considered
            // so we just need to evaluate arr2
            else if (i == n && j < m)
            {
                cout << "2" << j << endl;
                currmed = arr2[j++];
            }
            // Case3, arr2 is fully considered
            // so we just need to evaluate arr1
            else if (j == m && i < n)
            {
                cout << "1" << endl;
                currmed = arr1[i++];
            }
        }
        // If even we ned to return prev and current combo mid
        if ((long long)(n + m) % 2 == 0)
            return double((prevmed + currmed) / 2);
        // else its bjust current mid
        else
            return double(currmed);
    }
};