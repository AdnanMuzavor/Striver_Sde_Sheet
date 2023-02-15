/*

Largest BST
MediumAccuracy: 29.73%Submissions: 81K+Points: 4
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.

Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.
Example 2:

Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2
Output: 2
Explanation: The following sub-tree is a
BST of size 2:
       2
    /    \
   N      8
Your Task:
You don't need to read input or print anything. Your task is to complete the function largestBst() that takes the root node of the Binary Tree as its input and returns the size of the largest subtree which is also the BST. If the complete Binary Tree is a BST, return the size of the complete Binary Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 106
*/

#include <bits/stdc++.h>
using namespace std;

/* Tree node structure  used in the program*/

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
// We node to carry 3 values at each point ba s we know a sper STriver METHOD
//  => MAX_VAL,MIN_VAL_MAX_SIZE
//  => So lets do this using class concept
class Nodeval
{
public:
    int maxval, minval, maxsize;
    Nodeval(int a, int b, int s)
    {
        this->maxval = a;
        this->minval = b;
        this->maxsize = s;
    }
};

class Solution
{
    Nodeval helper(Node *root)
    {
        // CASE 1: ROOT DOESNT EXISTS
        if (!root)
        {
            // This node must be BSTs hence we return min and max as such that
            //  to root node of this leaf node, it gives positive impact
            //  i.e maxval should be  < root_node->val incase of LEFT node hence is set MIN
            //  i.e minval should be > root_node->val incase of RIGHT node hence is set MAX
            return Nodeval(INT_MIN, INT_MAX, 0);
        }
        // Check for left and right nodes of this node
        Nodeval lf = helper(root->left);
        Nodeval rt = helper(root->right);

        // Check if both left and right are BSTs
        // If yes, thn  w ecan add up size of both the trees
        // as well as +! for current node
        // This is true only if MAX_Of_Left < root->val
        // and MIN_Of_Right > root->val
        if (lf.maxval < root->data && rt.minval > root->data)
        {
            return Nodeval(max(rt.maxval, root->data), min(lf.minval, root->data), lf.maxsize + rt.maxsize + 1);
        }

        // Other eise since this node is not BST we shall return value
        // keeping in mind that it's minval and maxval shall never satisfy the BST condition
        // but size can constribute to answer
        return Nodeval(INT_MAX, INT_MIN, max(lf.maxsize, rt.maxsize));
    }

public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        return helper(root).maxsize;
    }
};