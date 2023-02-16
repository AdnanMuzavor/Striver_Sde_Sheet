/*

297. Serialize and Deserialize Binary Tree
Hard
8.4K
307
Companies
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.



Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
*/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        // Doing level orde rtraversal
        string s = "";
        if (!root)
            return s;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                TreeNode *t = q.front();
                q.pop();
                if (t == NULL)
                    s += "#,";
                else
                {
                    s += to_string(t->val);
                    s += ",";
                }
                if (t)
                {
                    q.push(t->left);
                    q.push(t->right);
                }
            }
        }
        cout << "s: " << s << endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;
        queue<TreeNode *> q;
        stringstream s(data);
        // cout<<"str stream s: "<<s<<endl;
        // Getting first node val
        //->stoi convertts to int val
        //->get line  we give delimiter as , so as to get values before ','
        string str;
        getline(s, str, ',');
        cout << " str after delimiting : " << str << endl; // we'll get first value
        // Creating root node
        TreeNode *root = new TreeNode(stoi(str)); // creating node of interger val of str
        q.push(root);
        // Insertion of nodes as per level orde traversal
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            // Getting next integer value in str
            getline(s, str, ',');
            // handling left side insertion

            if (str == "#")
            {
                node->left = NULL;
            }
            else
            {
                TreeNode *newnode = new TreeNode(stoi(str));
                node->left = newnode;
                q.push(newnode);
            }

            // handling right node case
            getline(s, str, ',');

            // handling left side insertion
            if (str == "#")
            {
                node->right = NULL;
            }
            else
            {
                TreeNode *newnode = new TreeNode(stoi(str));
                node->right = newnode;
                q.push(newnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
