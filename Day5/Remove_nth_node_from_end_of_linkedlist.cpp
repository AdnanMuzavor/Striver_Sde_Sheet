/*
19. Remove Nth Node From End of List
Medium

13393

551

Add to List

Share
Given the head of a linked list, remove the nth node from the end of the list and return its head.



Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]


Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
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

// TC -> O(N+N+N)
// SC -> O(1)
class Solution
{
public:
    ListNode *rev(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *prev = NULL;
        ListNode *nxt = NULL;
        ListNode *curr = head;
        while (curr != NULL)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head = prev;
        return head;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Reverse linkedlist
        head = rev(head);
        // Dummy node to handle null condition, when only one node
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *todel = head, *prev = dummy, *del = NULL;
        int i = 1;
        // delete nth node of linkedlist
        while (i < n)
        {
            todel = todel->next;
            prev = prev->next;
            i++;
        }
        // disconnext unwanted node
        prev->next = todel->next;
        // return again proper LL
        return rev(dummy->next);
    }
};

// O(N)
// O(1)
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Make slow and fats pointer poinmt to head
        ListNode *fast = head, *slow = head;

        // Create dummy to handle null case
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        // make prev point bto dunmy, prev will always point to node
        // preceding nod eto be deleted
        ListNode *prev = dummy;

        // mopve fast , so that at last when fats is ended, slow will be at nth node from last
        for (int i = 0; i < n; i++)
            fast = fast->next;

        // move slow pointer
        while (fast)
        {
            prev = prev->next;
            slow = slow->next;
            fast = fast->next;
        }

        // delete node poin ted by slow
        prev->next = slow->next;

        // return updated linkedlist
        return dummy->next;
    }
};