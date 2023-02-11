/*
K-th element of two sorted Arrays
MediumAccuracy: 37.4%Submissions: 100k+Points: 4
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.

Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the k’th position of the final sorted array.


Example 1:

Input:
arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5
Output:
6
Explanation:
The final sorted array would be -
1, 2, 3, 4, 6, 7, 8, 9, 10
The 5th element of this array is 6.
Example 2:
Input:
arr1[] = {100, 112, 256, 349, 770}
arr2[] = {72, 86, 113, 119, 265, 445, 892}
k = 7
Output:
256
Explanation:
Final sorted array is - 72, 86, 100, 112,
113, 119, 256, 265, 349, 445, 770, 892
7th element of this array is 256.

Your Task:
You don't need to read input or print anything. Your task is to complete the function kthElement() which takes the arrays arr1[], arr2[], its size N and M respectively and an integer K as inputs and returns the element at the Kth position.


Expected Time Complexity: O(Log(N) + Log(M))
Expected Auxiliary Space: O(Log (N))


Constraints:
1 <= N, M <= 106
1 <= arr1i, arr2i < INT_MAX
1 <= K <= N+M

*/

#include <bits/stdc++.h>
using namespace std;

// O(K)
class Solution
{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {

        int count = 0, i = 0, j = 0, ele = -1;
        // Iterate both arrays as single array using two pointers
        while (i < n && j < m)
        {
            if (arr1[i] <= arr2[j])
            {

                count++;
                ele = arr1[i];
                // cout<<count<<" th ele = "<<ele<<endl;
                i++;
            }
            else
            {

                count++;
                ele = arr2[j];
                //  cout<<count<<" th ele = "<<ele<<endl;
                j++;
            }
            if (count == k)
                return ele;
        }
        while (i < n)
        {
            ele = arr1[i];
            count++;
            i++;
            // cout<<count<<" th ele = "<<ele<<endl;
            if (count == k)
                return ele;
        }
        while (j < m)
        {
            ele = arr2[j];
            count++;
            j++;
            // cout<<count<<" th ele = "<<ele<<endl;
            if (count == k)
                return ele;
        }

        return ele;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int arr1[n], arr2[m];
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        for (int i = 0; i < m; i++)
            cin >> arr2[i];

        Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k) << endl;
    }
    return 0;
}
// } Driver Code Ends