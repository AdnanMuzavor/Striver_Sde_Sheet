/*
105. Construct Binary Tree from Preorder and Inorder Traversal
Medium
11.5K
327
Companies
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.



Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]


Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.

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
    // To map node value in index value in inorder
    // as in inorder array, we'll be making nodes as per preorder
    // and accordingly splitting inorder array
    unordered_map<int, int> mp;
    int i = 0; // A global i as w'll be making nodes as per the the preorder

    TreeNode *TreeM(vector<int> pre, vector<int> in, int l, int h)
    {

        if (l > h)
            return NULL;

        TreeNode *newNode = new TreeNode(pre[i]);
        i++;

        if (l == h)
            return newNode;

        int mid = mp[newNode->val];
        newNode->left = TreeM(pre, in, l, mid - 1);
        newNode->right = TreeM(pre, in, mid + 1, h);

        return newNode;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // map node value iwth index in inorder array
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        // Lets tsrta making the tree
        return TreeM(preorder, inorder, 0, inorder.size() - 1);
    }
};