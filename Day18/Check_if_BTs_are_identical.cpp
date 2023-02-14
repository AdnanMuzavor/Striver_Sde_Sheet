/*
100. Same Tree
Easy
7.6K
158
Companies
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.



Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false

*/

#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // Both doesnt exists is ok
        if (!p && !q)
            return true;
        // if one exist, othe rdoesnt it's sign of imbalance
        if (!p || !q)
            return false;
        // If value is not equal
        if (p->val != q->val)
            return false;
        // check for right and left trees
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        return (left && right);
    }
};