/*


*/

#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
int height(TreeNode* r,int &d){
    if(!r) return 0;
    if(r){
        int LH=height(r->left,d);
        int RH=height(r->right,d);
        d=max(d,LH+RH);
        return max(LH,RH)+1;

    }
    return 0;
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 0;
        int d=0;
        height(root,d);
        return d;

    }
};