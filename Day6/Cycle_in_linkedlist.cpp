/*
141. Linked List Cycle
Easy

10276

887

Add to List

Share
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.



Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.


Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.


Follow up: Can you solve it using O(1) (i.e. constant) memory?
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
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;
        ListNode *s = head, *f = head;
        do
        {
            s = s->next;
            f = f->next;
            if (f)
                f = f->next;
            // If any point f=NULL means
            // there is no cycle
            else if (!f)
                return false;
        } while (f && s != f);

        // Out of loop can be two reasons:
        // 1) s==f cycle exists           -> return true
        // 2) f==null cycle doesnt exists -> return false
        if (!f)
            return false;
        return true;
    }
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next)
            return false;
        ListNode *p = head, *q = head;
        while (p && p->next)
        {
            q = q->next;
            p = p->next->next;
            // -> If cycle is ther ep->next will always exists and at certain point they will
            // -> meet returning the true
            if (p == q)
                return true;
        }
        return false;
    }
};