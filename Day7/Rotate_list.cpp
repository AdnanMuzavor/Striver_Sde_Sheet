/*
61. Rotate List
Medium

6529

1313

Add to List

Share
Given the head of a linked list, rotate the list to the right by k places.



Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]


Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
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
    int len(ListNode *h)
    {
        ListNode *p = h;
        int l = 0;
        while (p)
        {
            l++;
            p = p->next;
        }
        return l;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;
        // case 01
        // if len is 5 and k=5
        // why to do five rotations,an result will be same?

        // case 02
        // if len =5 and k=12
        // thn we know that 10 rotations will yeild same LL
        // hence just 2 rotations will give the naswer

        int l = len(head);
        k = k % l;
        if (k == 0)
            return head; //-> case 01

        // -> case 02

        // How can we make it easy?
        // Lets just remove the last k nodes
        //  and attach them, thats all

        // Detach last k nodes that will be attached to front
        //  At end of iteration:
        // curr =>  will point tofirst node from detached nodes
        // prev => new last node of Linkedlist
        int detach_at = l - k;
        ListNode *curr = head, *prev = NULL;
        while (detach_at--)
        {
            prev = curr;
            curr = curr->next;
        }

        // As prev is last node, make it's next node null
        // hence nodes detached
        prev->next = NULL; // Nodes detached

        // ne whead is curfren
        ListNode *newHead = curr;
        // Find it's tail
        while (curr->next)
            curr = curr->next;
        // attach tail with prev head
        curr->next = head;
        // update head
        head = newHead;
        return head;
    }
};