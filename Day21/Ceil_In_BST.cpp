/*

Ceil from BST
Contributed by
Nikhil Nischal
Easy
32/40
Avg time to solve 15 mins
Success Rate 85 %
Share
44 upvotes
Problem Statement
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1:
2
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
4
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
7
Sample Output 1:
5
7
Explanation For Sample Output 1:
 In the first test case, we traverse the tree starting from the root node which has a value of 8. Now the value of its left child is 5 and its right child is 10. Key-value 4 is less than the left child so we traverse the left subtree. Now we reach a node with value 5 and then again repeat the above process till we reach a null node. Finally, we return 5 as our answer.

In the second test case, we traverse the tree starting from the root node which has a value of 8. Now the value of its left child is 5 and its right child is 10. Key-value 7 is less than the right child and more than the left child, so we traverse the right subtree. Now we reach a node with value 10 and then again follow the same procedure and reach a node with value 7 and stop there and return 7 as our final answer.
Sample Input 2:
2
55 25 82 13 34 67 86 6 21 28 47 61 70 84 92 1 10 17 24 26 29 45 54 56 65 68 81 83 85 91
96 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
34
84 19 97 0 56 96 99 -1 8 50 83 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
50
Sample Output 2:
34
50
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

//    Following is the TreeNode class structure:
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

void inorder(BinaryTreeNode<int> *r, int X, int &ans)
{
    if (r)
    {
        inorder(r->left, X, ans);
        if (r->data >= X && r->data < ans)
        {
            ans = r->data;
        }
        inorder(r->right, X, ans);
    }
}
int findCeil(BinaryTreeNode<int> *root, int X)
{
    // Write your code here.
    int ans = MAX;
    inorder(root, X, ans);
    if (ans == MAX)
        return -1;
    return ans;
}