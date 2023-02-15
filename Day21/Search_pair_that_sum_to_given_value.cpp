/*
653. Two Sum IV - Input is a BST
Easy
5.4K
235
Companies
Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.



Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false


Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105
Accepted
424.3K
Submissions
695.6K
Acceptance Rate
61.0%

*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// Optimised

// Approach:  O(N) + O(N)
class Solution
{
public:
    vector<int> in;
    void in_order(TreeNode *r)
    {
        if (r)
        {
            in_order(r->left);
            in.push_back(r->val);
            in_order(r->right);
        }
    }
    bool findTarget(TreeNode *root, int k)
    {
        in_order(root);
        int l = 0, h = in.size() - 1;
        while (l < h)
        {
            int sum = in[l] + in[h];
            if (sum == k)
                return true;
            if (sum > k)
                h--;
            else
                l++;
        }
        return false;
    }
};

// Brute force
class Solution
{
public:
    TreeNode *mainroot = NULL;
    bool search(TreeNode *r, int key, TreeNode *n)
    {
        if (!r)
            return false;
        if (r->val == key && r != n)
            return true;
        if (r->val < key)
            return search(r->right, key, n);
        else
            return search(r->left, key, n);
        return false;
    }
    bool helper(TreeNode *r, int k)
    {
        if (!r)
            return false;
        int val = (k - r->val);
        if (search(mainroot, val, r))
            return true;
        else
        {
            return (helper(r->left, k) || helper(r->right, k));
        }
    }
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;
        if (!root->right && !root->left)
            return false;
        mainroot = root;
        return helper(root, k);
    }
};