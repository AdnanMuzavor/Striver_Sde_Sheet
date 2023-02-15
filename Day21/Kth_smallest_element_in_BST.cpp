/*
230. Kth Smallest Element in a BST
Medium
8.8K
157
Companies
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.



Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3


Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104


Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

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
//O(N)+O(N)
class Solution
{
public:
    vector<int> op;
    void in(TreeNode *r)
    {
        if (!r)
            return;
        in(r->left);
        op.push_back(r->val);
        in(r->right);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        in(root);
        return op[k - 1];
    }
};

//O(N)+O(1)
class Solution {
public:
    int ans;
    int count=0,K;
    void in(TreeNode*r){
        if(!r) return;
    
        //Go to left node as per inorder
        in(r->left);

       //Consider currrent node, hence count++ simce we found a node
        count++;
       //Check if it's the required node
        if(count==K){
            ans=r->val;
            return;
        }

        //Go to right node as per inorder traversal   
        in(r->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        K=k;
        in(root);
        return ans;
  
    }
};