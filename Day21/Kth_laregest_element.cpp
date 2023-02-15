/*
Kth largest element in BST
EasyAccuracy: 49.31%Submissions: 83212Points: 2
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.

Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.


Example 1:

Input:
      4
    /   \
   2     9
k = 2
Output: 4

Example 2:

Input:
       9
        \
          10
K = 1
Output: 10

Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the root of the BST and an integer K as inputs and returns the Kth largest element in the given BST.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H) where H is max recursion stack of height h at a given time.


Constraints:
1 <= N <= 1000
1 <= K <= N
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Find N i.e number of nodes
    // Then kth laregst will be N-Kth smallest
    int ans = -1, count = 0, n = 0, newk;
    void counter(Node *root)
    {
        if (!root)
            return;
        n++;
        counter(root->left);
        counter(root->right);
    }
    void in(Node *r)
    {
        if (!r)
            return;
        in(r->left);
        count++;
        if (count == newk)
        {
            ans = r->data;
            return;
        }
        in(r->right);
    }
    int kthLargest(Node *root, int K)
    {
      
        // Count number of nodes
        counter(root);
        // Find kth laregst which will be (n-k)th smallest
        newk = n - K + 1;
        in(root);
        return ans;
    }
};