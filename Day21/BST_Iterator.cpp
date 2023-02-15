/*

173. Binary Search Tree Iterator
Medium
7.1K
430
Companies
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.



Example 1:


Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False


Constraints:

The number of nodes in the tree is in the range [1, 105].
0 <= Node.val <= 106
At most 105 calls will be made to hasNext, and next.


Follow up:

Could you implement next() and hasNext() to run in average O(1) time and use O(h) memory, where h is the height of the tree?
Accepted
640.7K
Submissions
925.6K
Acceptance Rate
69.2%
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
// O(N)+O(N)

class BSTIterator
{
public:
    int c = 0;
    vector<int> inorder;
    void in(TreeNode *r)
    {
        if (r)
        {
            in(r->left);
            inorder.push_back(r->val);
            in(r->right);
        }
    }
    BSTIterator(TreeNode *root)
    {
        in(root);
        c = 0;
    }

    int next()
    {
        int x = inorder[c];
        c++;
        return x;
    }

    bool hasNext()
    {
        if (c < inorder.size())
            return true;
        return false;
    }
};

 //O(1) + O(H) space for stack
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        //Store nodes in inorder traversal 
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
       //When popping a node, check if right exists, if so in oinorder traversal we
       //shall be taking the left most nodes of this tree, and hence traverse left
       //and store nodes in the stack in inorder order
        TreeNode* node=st.top();
        int val=node->val;
        st.pop();
        if(node->right){
            node=node->right;
            while(node){
                st.push(node);
                node=node->left;
            }
        }
      
        return val;
    }
    
    //A val/node will not ahve next obviosuly when stack is empty
    bool hasNext() {
        if(!st.empty()) return true;
        return false;
    }
};
