/*
142. Linked List Cycle II
Medium

9185

636

Add to List

Share
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.



Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.


Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
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

// O(N) + o(1)
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // If no node, just single node with next NULL => no cycle
        if (!head || !head->next)
            return NULL;

        // Just single node and taht too pointing it at self,cycle at zero
        if (head && head->next == head)
            return head;

        // Use slow and fats pointer to find cycle
        ListNode *s = head, *f = head;
        while (f && f->next)
        {
            s = s->next;
            f = f->next->next;
            if (s == f)
                break;
        }

        // if any maomng a or f becomes null return  nul as non cycle due to which we reached    at null
        if (!f || !s)
            return NULL;
        // node at whi ch f=s is node from where head and slow pointer s both are
        // equidistant from nodes forming the cycle

        // move fast to head and traverse until we find teh cycle node
        f = head;

        // if any point of time s becaome snull, null will be retufurned => no cycle
        // or proper cycle node will be returned
        while (s && f && s != f)
        {
            s = s->next;
            f = f->next;
        }
        return s;
    }
};

// proper code/ideal code
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *p = head, *q = head;
        while (p && p->next)
        {
            q = q->next;
            p = p->next->next;
            if (p == q)
                break;
        }
        if (!p || !p->next)
            return NULL;
        if (q == head || p == head)
        {
            return head;
        }
        else
        {
            q = head;
            while (p->next != q->next)
            {
                p = p->next;
                q = q->next;
            }
            return p->next;
        }
        return head;
    }
};