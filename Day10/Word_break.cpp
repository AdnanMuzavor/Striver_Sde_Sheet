/*
139. Word Break
Medium

12650

530

Add to List

Share
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.



Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false


Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
Accepted
1,231,706
Submissions
2,712,734

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // Keep bool array and check if at word till inde xj is found in dict or not
        vector<bool> dp(s.size() + 1, false);
        // Assume first letter to hv been found in doict, so mark it true
        dp[0] = true;
        // Iterate for reaming words, and cjeck if in dict
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                // Substring from j to i
                // Where we'll check by forming words from j to i
                // But we shall do so only if dp[j]=true
                // i.e if dp j is true, means till length j we have found a word
                // hence we try to find word from j till ith length
                if (dp[j])
                {
                    string word = s.substr(j, i - j);
                    // Check if word in dict, that means w ehave an word
                    //  found at dp[i]
                    for (auto e : wordDict)
                    {
                        if (e == word)
                        {
                            dp[i] = true; // Word found
                            break;
                        }
                    }
                }
            }
        }
        // Answer will be in last dp array
        return dp[s.size()];
    }
};