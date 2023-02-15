/*
Predecessor and Successor
MediumAccuracy: 47.36%Submissions: 54010Points: 4
There is BST given with root node with key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.

Example:

Input:
2
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
65
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
100

Output:
60 70
80 -1
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains n denoting the number of edges of the BST. The next line contains the edges of the BST. The last line contains the key.

Output:
Find the predecessor and successor of the key in BST and sets pre and suc as predecessor and successor, respectively Otherwise, set to NULL.

Your Task: You don't need to print anything. You only need to set p.pre to the predecessor and s.succ to the successor. p and s have been passed in the function parameter.

Constraints:
1<=T<=100
1<=n<=100
1<=data of node<=100
1<=key<=100

*/
#include <bits/stdc++.h>
using namespace std;

// BST Node
struct Node
{
    int key;
    struct Node *left, *right;
};

#include <bits/stdc++.h>
vector<Node *> op;
void pret(Node *root, int &pree, int &succ, Node *&p, Node *&s, int key)
{
    if (root)
    {

        pret(root->left, pree, succ, p, s, key);
        if (root->key > pree && root->key < key)
        {
            // cout<<"Found new predecessor for "<<key<<" is: "<<root->key<<endl;
            pree = root->key;
            p = root;
        }
        if (root->key < succ && root->key > key)
        {
            // cout<<"Found new successor for "<<key<<" is: "<<root->key<<endl;
            succ = root->key;
            s = root;
        }
        pret(root->right, pree, succ, p, s, key);
    }
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    int i;
    // Your code goes here
    int pree = INT_MIN;
    int succ = INT_MAX;
    pret(root, pree, succ, pre, suc, key);
}