/*
Duplicate Subtrees
MediumAccuracy: 23.98%Submissions: 31K+Points: 4
Lamp
Bag Offers from Top Product Companies. Explore Exclusive Problems Now!

Given a binary tree of size N, your task is to that find all duplicate subtrees from the given binary tree.

Note: Here's the Output of every Node printed in the Pre-Order tree traversal format. Arrange nodes in the answer array based on the ascending value of nodes.

Example:

Input :

Output : 2 4
         4
Explanation: Above Trees are two
duplicate subtrees.i.e  and
Therefore,you need to return above trees
root in the form of a list.
Your Task:
You don't need to take input. Just complete the function printAllDups() that takes the root node as a parameter and returns an array of Node*, which contains all the duplicate subtree.


Constraints:
1<=T<=100
1<=N<=100
*/

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
string process(Node *root, unordered_map<string, int> &mp, vector<Node *> &op)
{

    if (!root)
        return "";
    string s = "(";
    s += process(root->left, mp, op);
    s += to_string(root->data);
    s += process(root->right, mp, op);
    s += ")";

    // If map value is already one means we had found that string
    // and now we are finding it for second time
    // hence we shall add string/tree to o/p
    if (mp[s] == 1)
    {
        op.push_back(root);
    }
    mp[s]++;
    return s;
}
vector<Node *> printAllDups(Node *root)
{
    // => We shall convert each subtree into a string
    // => Hence mapping string with count of occurences will help
    // => us to fidn repeated/duplicate trees
    unordered_map<string, int> mp;
    vector<Node *> op;
    process(root, mp, op);
    return op;
}