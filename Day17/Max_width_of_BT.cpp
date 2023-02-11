/*

662. Maximum Width of Binary Tree
Medium
5.9K
830
Companies
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.



Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
Example 2:


Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
Example 3:


Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
*/

#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
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
    int widthOfBinaryTree(TreeNode *root)
    {
        // Use concepot of indexing which says that
        // left node's index is it's parent's_index*2+1
        // right nodes's index is it's parent's_index*2+2
        // why 2? because it's binary tree
        // Do a dry run to find it out

        // Initialise ans to minimum value say -1
        int ans = -1;

        // Find width at each level using formula
        // widt h= index_of_last_node_at_level - index_of_first_node_at_level

        // Make the queue
        queue<pair<TreeNode *, long long>> q;

        // Push root inside with index of zero
        q.push({root, 0});

        // start iterating
        while (!q.empty())
        {
            int s = q.size();          // Number of nodes at an level
            int first = -1, last = -1; // Initialse first and last for this level
            long long int min = q.front().second;
            while (s--)
            {
                // Get node
                TreeNode *temp = q.front().first;

                // get index
                long long int index = q.front().second - min;
                q.pop();
                // cout<<"index: "<<index<<endl;
                // if it's first index intialise nthe first
                if (first == -1)
                    first = index;
                // last will be updated for every node, until mw find the last node
                last = index;
                // do indexing for left and right nodes as per formula
                if (temp->left)
                    q.push({temp->left, (index * 2) + 1});
                if (temp->right)
                    q.push({temp->right, (index * 2) + 2});
            }
            // Update ans wrt to this level
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};