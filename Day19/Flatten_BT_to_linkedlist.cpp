/*

Flatten binary tree to linked list
MediumAccuracy: 75.82%Submissions: 21576Points: 4
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same Node class where the right child pointer points to the next   node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
Example 1:

Input :
          1
        /   \
       2     5
      / \     \
     3   4     6
Output :
1 2 3 4 5 6
Explanation:
After flattening, the tree looks
like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6
Here, left of each node points
to NULL and right contains the
next node in preorder.The inorder
traversal of this flattened tree
is 1 2 3 4 5 6.
Example 2:

Input :
        1
       / \
      3   4
         /
        2
         \
          5
Output :
1 3 4 2 5
Explanation :
After flattening, the tree looks
like this
     1
      \
       3
        \
         4
          \
           2
            \
             5
Here, left of each node points
to NULL and right contains the
next node in preorder.The inorder
traversal of this flattened tree
is 1 3 4 2 5.
Your task:
You don't have to read input or print anything. Your task is to complete the function flatten() which takes the root of the tree and flattens the tree into a linkes list without using any auxiliary space.
Note : The driver code prints the inorder traversal of the flattened binary tree.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints :
1<=n<=10^5
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

// Method I => Used Extra Space But
class Solution
{
public:
    void pre(vector<Node *> &p, Node *r)
    {
        if (r)
        {
            p.push_back(r);
            pre(p, r->left);
            pre(p, r->right);
        }
    }

    void flatten(Node *r)
    {
        if (!r)
            return;
        if (!r->left && !r->right)
            return;

        vector<Node *> p;
        pre(p, r);

        if (p.size() == 1)
            return;

        Node *curr = p[0], *prev = p[1];
        curr->left = NULL;
        curr->right = prev;
        prev->left = NULL;
        for (int I = 1; I < p.size(); I++)
        {
            curr->right = prev;
            prev->left = NULL;
            curr = prev;
            if (I + 1 < p.size())
                prev = p[I + 1];
            else
                break;
        }
        p[p.size() - 1]->left = NULL;
    }
};

// Method II Striver Algorithm
class Solution
{
public:
    TreeNode *prev = NULL;
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};