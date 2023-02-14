/*
101. Symmetric Tree
Easy
11.6K
262
Companies
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).



Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false


Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100


Follow up: Could you solve it both recursively and iteratively?
Accepted
1.4M
Submissions
2.7M
Acceptance Rate
53.0%

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
    bool checker(TreeNode *r1, TreeNode *r2)
    {
        if (!r1 && !r2)
            return true;
        if (!r1 || !r2)
            return false;
        if (r1->val != r2->val)
            return false;
        bool l = checker(r1->left, r2->right);
        bool r = checker(r1->right, r2->left);
        return (l && r);
    }
    bool isSymmetric(TreeNode *root)
    {
        return checker(root, root);
    }
};