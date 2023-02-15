/*
Children Sum Parent
EasyAccuracy: 51.58%Submissions: 62648Points: 2
Given a Binary Tree. Check whether all of its nodes have the value equal to the sum of their child nodes.


Example 1:

Input:
     10
    /
  10
Output: 1
Explanation: Here, every node is sum of
its left and right child.
Example 2:

Input:
       1
     /   \
    4     3
   /  \
  5    N
Output: 0
Explanation: Here, 1 is the root node
and 4, 3 are its child nodes. 4 + 3 =
7 which is not equal to the value of
root node. Hence, this tree does not
satisfy the given conditions.

Your Task:
You don't need to read input or print anything. Your task is to complete the function isSumProperty() that takes the root Node of the Binary Tree as input and returns 1 if all the nodes in the tree satisfy the following properties. Else, it returns 0.
For every node, data value must be equal to the sum of data values in left and right children. Consider data value as 0 for NULL child.  Also, leaves are considered to follow the property.


Expected Time Complexiy: O(N).
Expected Auxiliary Space: O(Height of the Tree).

*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int helper(Node *r)
    {

        // If leaf node return NULL
        if (!r)
            return 1;

        // If left and right exists and if both doesnt add up to root return false
        if (r->left && r->right && (r->left->data + r->right->data) != r->data)
            return 0;

        // If only left or gright are existing they must match with root value
        if (r->left && !r->right && r->left->data != r->data)
            return 0;
        if (r->right && !r->left && r->right->data != r->data)
            return 0;

        // Means this part/upto this node tree is valid, check for subtree
        // If both left and right subtree provides true thn only return 1
        int ans = (helper(r->left) && helper(r->right));

        if (ans)
            return 1;
        // else return 0
        return 0;
    }
    int isSumProperty(Node *root)
    {
        // Add your code here
        return helper(root);
    }
};