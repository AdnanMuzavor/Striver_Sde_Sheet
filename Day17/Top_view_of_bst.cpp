/*
Top View of Binary Tree
MediumAccuracy: 38.43%Submissions: 100k+Points: 4
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3
Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
Your Task:
Since this is a function problem. You don't have to take input. Just complete the function topView() that takes root node as parameter and returns a list of nodes visible from the top view from left to right.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ Node Data ≤ 105


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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // Do it sam eas vertical order traversal
        // but pick only top most i.e first node on vertical line

        // Data structure to keep record of vertical,level={ele1,ele2...}
        // as one vertical can have many levels
        map<int, map<int, multiset<int>>> mp;

        // queue to push node and it's vertical + level
        queue<pair<Node *, pair<int, int>>> q;
        // starting at vertical 0, level 0 and node=root
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            int s = q.size();
            while (s--)
            {
                Node *temp = q.front().first;
                int vertical = q.front().second.first;
                int level = q.front().second.second;
                q.pop();
                mp[vertical][level].insert(temp->data);
                if (temp->left)
                    q.push({temp->left, {vertical - 1, level + 1}});
                if (temp->right)
                    q.push({temp->right, {vertical + 1, level + 1}});
            }
        }

        // Extract firsrt nodes at each vertical found
        vector<int> op;
        for (auto vertical : mp)
        {
            int top_node = -1;
            // Extracting first most vertical node at the level
            for (auto nodes : vertical.second)
            {
                auto it = nodes.second.begin();
                top_node = *it;
                break;
            }
            op.push_back(top_node);
        }

        return op;
    }
};

// Simplified code, after finding only whats needed
class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // Do it sam eas vertical order traversal
        // but pick only top most i.e first node on vertical line

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
                if (!mp[vertical])
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
