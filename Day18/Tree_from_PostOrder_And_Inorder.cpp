/*
106. Construct Binary Tree from Inorder and Postorder Traversal
Medium
5.5K
82
Companies
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.



Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]


Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.

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
    int i = 0;
    unordered_map<int, int> m;
    TreeNode *tree(vector<int> &inorder, vector<int> &postorder, int l, int u)
    {
        if (l > u || i < 0)
            return NULL;
        TreeNode *node = new TreeNode(postorder[i]);
        i--;
        if (l == u || i < 0)
            return node;
        int mid = m[node->val];
        node->right = tree(inorder, postorder, mid + 1, u);
        node->left = tree(inorder, postorder, l, mid - 1);
        return node;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        i = inorder.size() - 1;
        for (int j = 0; j < inorder.size(); j++)
        {
            m[inorder[j]] = j;
        }
        return tree(inorder, postorder, 0, inorder.size() - 1);
    }
};