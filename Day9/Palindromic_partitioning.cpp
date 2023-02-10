/*
131. Palindrome Partitioning
Medium

8529

264

Add to List

Share
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.



Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]


Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ispalin(string s)
    {
        if (s.size() == 0)
            return 0;
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }
    void helper(vector<vector<string>> &op, string s, vector<string> curr, int index)
    {
        if (index == s.size())
        {
            op.push_back(curr);
            return;
        }
        string res = "";
        for (int i = index; i < s.size(); i++)
        {
            res = res + s[i];
            if (res.size() == 1 || ispalin(res))
            {
                curr.push_back(res);
                helper(op, s, curr, i + 1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> op;
        vector<string> curr;
        helper(op, s, curr, 0);
        return op;
    }
};