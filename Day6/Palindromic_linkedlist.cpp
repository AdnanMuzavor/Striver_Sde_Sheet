/*
234. Palindrome Linked List
Easy

12026

670

Add to List

Share
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.



Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false


Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
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

// O(N)+O(N)
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *curr = head;
        vector<int> nos;
        while (curr)
        {
            nos.push_back(curr->val);
            curr = curr->next;
        }
        int i = 0, j = nos.size() - 1;
        while (i < j)
        {
            if (nos[i] != nos[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

// O(N)+O(1)
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
    bool isPalindrome(ListNode *head)
    {
        if (!head->next)
            return head;
        /// To do this in O(1)
        // 1) We can choose the split the linkedlist into 2 halves
        // 2) rev second half
        // 3) Comapre vals of second half with vals of first half

        // 1)Find the half of LL
        ListNode *slow = NULL, *fast = head, *curr_fast = head;
        while (fast && fast->next)
        {
            slow = curr_fast;
            curr_fast = curr_fast->next;
            fast = fast->next->next;
        }
        ListNode *second_half_head = rev(slow->next);
        slow = head;
        while (slow && second_half_head)
        {
            if (slow->val != second_half_head->val)
                return false;
            slow = slow->next;
            second_half_head = second_half_head->next;
        }
        return true;
    }
};

// O(N)+O(1)
// Better way
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
    bool isPalindrome(ListNode *head)
    {
        if (!head->next)
            return head;
        /// To do this in O(1)
        // 1) We can choose the split the linkedlist into 2 halves
        // 2) rev second half
        // 3) Comapre vals of second half with vals of first half

        // 1)Find the half of LL
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *second_half_head = rev(slow->next);
        slow = head;
        while (slow && second_half_head)
        {
            if (slow->val != second_half_head->val)
                return false;
            slow = slow->next;
            second_half_head = second_half_head->next;
        }
        return true;
    }
};