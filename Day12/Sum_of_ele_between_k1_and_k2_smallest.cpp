/*
Sum of elements between k1'th and k2'th smallest elements
EasyAccuracy: 32.02%Submissions: 37K+Points: 2
Lamp
Don't Get Left Behind in the Rapidly Growing Data Science Industry. Try this course!

Given an array A[] of N positive integers and two positive integers K1 and K2. Find the sum of all elements between K1th and K2th smallest elements of the array. It may be assumed that (1 <= k1 < k2 <= n).



Example 1:

Input:
N  = 7
A[] = {20, 8, 22, 4, 12, 10, 14}
K1 = 3, K2 = 6
Output:
26
Explanation:
3rd smallest element is 10
6th smallest element is 20
Element between 10 and 20
12,14. Their sum = 26.


Example 2:

Input
N = 6
A[] = {10, 2, 50, 12, 48, 13}
K1= 2, K2 = 6
Output:
73


Your Task:
You don't need to read input or print anything. Your task is to complete the function sumBetweenTwoKth() which takes the array A[], its size N and two integers K1 and K2 as inputs and returns the sum of all the elements between K1th and K2th smallest elements.


Expected Time Complexity: O(N. log(N))
Expected Auxiliary Space: O(N)



Constraints:
1 ≤ N ≤ 105
1 ≤ K1, K2 ≤ 109

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        // Brute force
        // Sort the array and get elemnts between given k1 and k2
        vector<long long> op;
        for (int i = 0; i < N; i++)
        {
            op.push_back(A[i]);
        }
        sort(op.begin(), op.end());
        long long ans = 0;
        for (long long i = K1; i < K2 - 1; i++)
        {
            // cout<<"i: "<<i<<" op[i]"<<op[i]<<endl;
            ans += op[i];
        }
        return ans;
    }
};

// Using Heap
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long KSmallest(long long a[], long long n, long long k)
    {
        // Max_heap to give us the minimum elements
        priority_queue<long long> max_heap;
        for (long long i = 0; i < n; i++)
        {
            max_heap.push(a[i]);
            if (max_heap.size() > k)
            {
                max_heap.pop();
            }
        }
        return max_heap.top();
    }
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        // Brute force
        // Sort the array and get elemnts between given k1 and k2
        long long k1 = KSmallest(A, N, K1);
        long long k2 = KSmallest(A, N, K2);
        // cout<<k1<<" "<<k2<<endl;
        long long ans = 0;
        for (long long i = 0; i < N; i++)
        {
            // cout<<"i: "<<i<<" op[i]"<<op[i]<<endl;
            if (A[i] > k1 && A[i] < k2)
            {
                ans += A[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n;
        long long a[n + 5];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
    }
    return 0;
}

// } Driver Code Ends