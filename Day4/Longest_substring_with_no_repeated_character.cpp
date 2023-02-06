/*
3. Longest Substring Without Repeating Characters
Medium

28086

1206

Add to List

Share
Given a string s, find the length of the longest substring without repeating characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <bits/stdc++.h>
using namespace std;

// TC -> O(N^3)
// SC -> O(N)
class Solution
{
public:
    int substr(int i, int j, string s)
    {
        unordered_map<char, int> mp;
        // Map charcters with thier frequency for given substring
        for (int k = i; k <= j; k++)
            mp[s[k]]++;
        // If repeated character swe shall not be considering it, hecne return 0
        for (int k = i; k <= j; k++)
            if (mp[s[k]] > 1)
                return 0;
        // Else return the length
        return (j - i + 1);
    }
    int lengthOfLongestSubstring(string s)
    {
        int length = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < s.size(); j++)
            {
                // Check for each substring
                // If its valid, it'll returjn length hence update the length
                length = max(length, substr(i, j, s));
            }
        }
        return length;
    }
};

// TC -> O(N) as we are not taking additional TC to move left i.e l pointer
// SC -> O(N) for map

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int length = 0, l = 0, r = 0;
        // Move the right pointer
        for (int r = 0; r < s.size(); r++)
        {
            // if this character was not found earlier
            //  => consider it as path of subsequence
            //  => and update length
            //  => and map index of thsi character to tell its occurence
            if (!mp.count(s[r]))
            {
                length = max(length, r - l + 1);
                mp[s[r]] = r;
            }
            // => If this character had occured
            // => move l (left) pointr ahead at occurence of thus character
            // => to avoid reepated characters, however
            // => left should be updated only if possible i.e value is > cuurent_l
            // => else ther is no point in shifting greate value of l to back

            // => Update length after updating l i.e after removing repeated character

            // => update index of occurence of character
            else
            {
                if (mp[s[r]] >= l)
                    l = mp[s[r]] + 1;
                length = max(length, r - l + 1);
                mp[s[r]] = r;
            }
        }
        return length;
    }
};

// TC -> O(N) as we are not taking additional TC to move left i.e l pointer

// SC -> O(256) -> O(1) this case
// Instead of map we can also use charcter array of 256 length and map
// character s on that
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // unordered_map<char,int> mp;
        vector<int> mp(256, -1);
        int length = 0, l = 0, r = 0;
        // Move the right pointer
        for (int r = 0; r < s.size(); r++)
        {
            // if this character was not found earlier
            //  => consider it as path of subsequence
            //  => and update length
            //  => and map index of thsi character to tell its occurence
            if (mp[s[r]] == -1)
            {
                length = max(length, r - l + 1);
                mp[s[r]] = r;
            }
            // => If this character had occured
            // => move l (left) pointr ahead at occurence of thus character
            // => to avoid reepated characters, however
            // => left should be updated only if possible i.e value is > cuurent_l
            // => else ther is no point in shifting greate value of l to back

            // => Update length after updating l i.e after removing repeated character

            // => update index of occurence of character
            else
            {
                if (mp[s[r]] >= l)
                    l = mp[s[r]] + 1;
                length = max(length, r - l + 1);
                mp[s[r]] = r;
            }
        }
        return length;
    }
};