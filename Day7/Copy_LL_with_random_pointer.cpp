/*
138. Copy List with Random Pointer
Medium

10058

1091

Add to List

Share
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.



Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]


Constraints:

0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.
*/
#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// O(N)+O(1 (Although O(N) as we are creating N cloned nodes, but that is what question required))
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        // STEP 01
        // Lets create copy of each nodes and insert them
        // after each ooriginal node
        Node *curr = head;
        while (curr)
        {
            // create clone of current
            Node *newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // STEP 02
        // Link the random pointer of these clone nodes with random
        // nodes they are suppose to attch with

        curr = head;
        while (curr)
        {

            // curr->next->random : is cloned node's random
            // curr->random->next : is cloned node tow hcih random of cloned
            //                      current node should point to

            // Howveer do this only have current as random
            // else no need to do it
            if (curr->random)
                curr->next->random = curr->random->next;

            // Move current to next ORIGINAL node
            curr = curr->next->next;
        }

        // Step3:
        // Remove original nodes and keep the cloned nodes only
        // But leave original node unchanged, i.e re structure it
        // dummy will help us to acjieve this!!
        Node *dummy = new Node(-1);
        curr = head;
        Node *cloneptr = dummy;
        while (curr)
        {
            cloneptr->next = curr->next;
            cloneptr = cloneptr->next;
            curr->next = curr->next->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};