/*
21. Merge Two Sorted Lists
Easy

15352

1342

Add to List

Share
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/
#include <bits/stdc++.h>
using namespace std;
// TC -> O(1)
// SC -> O(1)
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergell(ListNode*l1,ListNode*l2){
        if(!l1 && !l2) return NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode*t=NULL;
       // cout<<l1->val<<endl;
        if(l1->val<=l2->val){
            t=l1;
            t->next=mergell(l1->next,l2);
            }
        else{
            t=l2;
            t->next=mergell(l1,l2->next);
            }
        return t;
        }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return mergell(list1,list2);
    }
};