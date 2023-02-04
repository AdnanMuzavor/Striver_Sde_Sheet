/*
Count Inversions
Difficulty: MEDIUM
Contributed By
Deep Mavani
|
Level 1
Avg. time to solve
40 min
Success Rate
55%
Problem Statement
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Explanation Of Sample Output 1:
We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
Sample Input 2 :
5
2 5 1 3 4
Sample Output 2 :
4
Explanation Of Sample Output 1:
We have a total of 4 pairs which satisfy the condition of inversion. (2, 1), (5, 1), (5, 3) and (5, 4).
*/

#include <bits/stdc++.h>
using namespace std;

// O(NlogN) + O(N/2)
long long merge(long long *arr, int l, int m, int h)
{
    long long i = l, j = m + 1, k = 0, inv = 0;
    long long temp[h - l + 1];
    while (i <= m && j <= h)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            inv += (m - i + 1);
            temp[k++] = arr[j++];
        }
    }
    while (i <= m)
        temp[k++] = arr[i++];
    while (j <= h)
        temp[k++] = arr[j++];
    k = 0;
    for (int i = l; i <= h; i++)
    {
        arr[i] = temp[k++];
    }
    return inv;
}
long long mergesort(long long *arr, long long l, long long h)
{
    long long inv = 0;
    if (l < h)
    {
        long long mid = (l + h) / 2;
        inv += mergesort(arr, l, mid);
        inv += mergesort(arr, mid + 1, h);
        inv += merge(arr, l, mid, h);
    }
    return inv;
}
long long getInversions(long long *arr, int n)
{
    // Write your code here.
    return mergesort(arr, 0, (long long)n - 1);
}