/*
25. Reverse Nodes in k-Group
Hard

9355

541

Add to List

Share
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.



Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]


Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000


*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // Firts check if length of LL is > k to reverse them
        int len = 0;
        ListNode *t = head;
        while (t)
        {
            len++;
            t = t->next;
        }
        if (len < k)
            return head;
        /// Reverse the linkedlist upto k nodes, from current head

        ListNode *prev = NULL, *curr = head, *nextn = NULL;

        int i = 0;
        while (curr && i < k)
        {
            nextn = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextn;
            i++;
        }

        // If you rpocess the diagram, the next k reverse nodes
        // are to be linked with head node for current recusrion call
        head->next = (curr ? reverseKGroup(curr, k) : NULL);

        // head now of new LL is prev_node
        return prev;
    }
};