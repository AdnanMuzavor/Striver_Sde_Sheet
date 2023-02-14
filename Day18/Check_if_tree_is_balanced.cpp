/*

110. Balanced Binary Tree
Easy
7.7K
418
Companies
Given a binary tree, determine if it is
height-balanced
.



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true


Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
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
    int ht(TreeNode *r)
    {
        if (!r)
            return 0;
        int lh = ht(r->left);
        int rh = ht(r->right);
        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode *root)
    {

        if (!root)
            return true;

        // for curreent root, find the hts of Left and Right
        // subtrees and validate them wrt to consition
        int LH = ht(root->left);
        int RH = ht(root->right);
        if (abs(LH - RH) > 1)
            return false;

        // Else if valid, validate the subtrees
        return (isBalanced(root->left) && isBalanced(root->right));
    }
};