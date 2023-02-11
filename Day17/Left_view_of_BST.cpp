/*
Left View of Binary Tree
EasyAccuracy: 33.74%Submissions: 100k+Points: 2
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.

Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

Example 2:

Input:

Output: 10 20 40
Your Task:
You just have to complete the function leftView() that returns an array containing the nodes that are in the left view. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 100
1 <= Data of a node <= 1000

*/
// O(N) => Traversing N nodes
// O(N) => Stack space
// Do level order traversal and push the first most node into the output vector
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

// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> op;
    if (!root)
        return op;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {

        int s = q.size();
        int count = 1;
        while (s--)
        {
            Node *temp = q.front();
            q.pop();
            if (count == 1)
                op.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            count++;
        }
    }
    return op;
}