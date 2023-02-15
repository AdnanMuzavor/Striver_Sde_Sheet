/*
Floor in BST
Medium
Avg time to solve 30 mins
Success Rate 70 %
Share
36 upvotes
Problem Statement

Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1:
2
10 5 15 2 6 -1 -1 -1 -1 -1 -1
7
2 1 3 -1 -1 -1 -1
2
Sample Output 1:
6
2
Explanation Of Sample Input 1:
In the first test case, the BST looks like as below:

The greatest value node of the BST which is smaller than or equal to  7 is 6.

In the second test case, the BST looks like as below:

The greatest value node of the BST which is smaller than or equal to  2 is 2.
Sample Input 2:
2
5 3 10 2 4 6 15 -1 -1 -1 -1 -1 -1 -1 -1
15
5 3 10 2 4 6 15 -1 -1 -1 -1 -1 -1 -1 -1
8
Sample Output 2:
15
6
*/

#include <bits/stdc++.h>
using namespace std;

// Simplest eay to understand approach, apply concept of inorder prec and succ problem here

#define MIN -100000

//   Following is the TreeNode class structure

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(TreeNode<int> *r, int X, int &ans)
{
    if (r)
    {
        inorder(r->left, X, ans);
        if (r->val <= X && r->val > ans)
        {
            ans = r->val;
        }
        inorder(r->right, X, ans);
    }
}
int floorInBST(TreeNode<int> *root, int X)
{
    // Write your code here.
    int ans = MIN;
    inorder(root, X, ans);
    return ans;
}
//______________________________________________________________
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int floorInBST(TreeNode<int> *root, int X)
{
    // Write your code here.
    if (!root)
        return -1;
    int nearest_floor = root->val;
    if (root->val == X)
        return X;
    if (root->val < X && root->right)
    {
        nearest_floor = floorInBST(root->right, X);
    }
    else if (root->val > X && root->left)
    {
        nearest_floor = floorInBST(root->left, X);
    }
    if (nearest_floor <= X)
        return nearest_floor;
    return root->val;
}