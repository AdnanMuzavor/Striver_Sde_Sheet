/*

Bottom View of Binary Tree
MediumAccuracy: 54.18%Submissions: 100k+Points: 4
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.

Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \
                 10       14

For the above tree the output should be 5 10 4 14 25.


Example 1:

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation:
First case represents a tree with 3 nodes
and 2 edges where root is 1, left child of
1 is 3 and right child of 1 is 2.

Thus nodes of the binary tree will be
printed as such 3 1 2.
Example 2:

Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
Your Task:
This is a functional problem, you don't need to care about input, just complete the function bottomView() which takes the root node of the tree as input and returns an array containing the bottom view of the given tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
*/

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
class Solution
{
public:
    vector<int> bottomView(Node *root)
    {

        // Do it same as vertical order traversal
        // but pick only bottom most i.e last node on vertical line

        // Data structure to keep record of vertical,level={ele1,ele2...}
        // as one vertical can have many levels
        map<int, int> mp;

        // queue to push node and it's vertical + level
        queue<pair<Node *, int>> q;
        // starting at vertical 0, level 0 and node=root
        q.push({root, 0});
        while (!q.empty())
        {
            int s = q.size();
            while (s--)
            {
                Node *temp = q.front().first;
                int vertical = q.front().second;

                q.pop();
                mp[vertical] = temp->data;

                if (temp->left)
                    q.push({temp->left, vertical - 1});
                if (temp->right)
                    q.push({temp->right, vertical + 1});
            }
        }

        // Extract firsrt nodes at each vertical found
        vector<int> op;
        for (auto node : mp)
        {
            op.push_back(node.second);
        }

        return op;
    }
};