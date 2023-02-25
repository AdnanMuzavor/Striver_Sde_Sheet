/*
Word Ladder I
HardAccuracy: 37.65%Submissions: 19K+Points: 8
Lamp
Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!

Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList
The second part of this problem can be found here.

Note: If no possible way to transform sequence from startWord to targetWord return 0


Example 1:

Input:
wordList = {"des","der","dfr","dgt","dfs"}
startWord = "der", targetWord= "dfs",
Output:
3
Explanation:
The length of the smallest transformation
sequence from "der" to "dfs" is 3
i,e "der" -> "dfr" -> "dfs".
Example 2:

Input:
wordList = {"geek", "gefk"}
startWord = "gedk", targetWord= "geek",
Output:
2
Explanation:
gedk -> geek
Example 3:

Input:
wordList = {"poon", "plee", "same", "poie","plea","plie","poin"}
startWord = "toon", targetWord= "plea",
Output: 7
Explanation:
toon -> poon -> poin -> poie -> plie -> plee -> plea


Your Task:
You don't need to read or print anything, Your task is to complete the function wordLadderLength() which takes startWord, targetWord and wordList as input parameter and returns the length of the shortest transformation sequence from startWord to targetWord. If not possible return 0.


Expected Time Compelxity: O(N2 * M)
Expected Auxiliary Space: O(N * M) where N = length of wordList and M = |wordListi|


Constraints:
1 ≤ N ≤ 100
1 ≤ M ≤ 10
*/

#include <bits/stdc++.h>
using namespace std;



//BRUTE FORCE => MY CODE
// } Driver Code Ends
class Solution
{
public:
    int wordLadderLength(string startWord, string endWord, vector<string> &wordList)
    {
        // To help us know whether string exists in the list
        unordered_map<string, int> mp;
        for (auto e : wordList)
        {
            mp[e] = 1;
        }
        if (!mp[endWord])
            return 0;
        // We shall start from startword
        queue<pair<string, int>> q;
        int ans = INT_MAX;
        q.push({startWord, 1}); // Initally starting word and len = 1
        while (!q.empty())
        {
            auto tp = q.front();
            q.pop();
            string str = tp.first;
            string init_str = str;
            int len = tp.second;

            // cout<<"str: "<<str<<" len: "<<len<<endl;

            int break1 = 0;
            // Try replacing each character with other 25 chars and if str
            // formed exists then update the length and push new str into the queue
            for (int i = 0; i < str.size(); i++)
            {

                // cout<<"_________changing: "<<i<<" th char_____________"<<endl;
                str = init_str;
                for (char c = 'a'; c <= 'z'; c++)
                {

                    str[i] = c;

                    // If we found the end word, update the ans minimisng it
                    if (str == endWord)
                    {

                        ans = min(ans, len + 1);
                        break1 = 1;
                        break;
                    }

                    // Ele if str in dict, we shall find next version of str by including current
                    // version henc elength too is increased
                    if (mp[str] == 1)
                    {
                        //    cout<<str<<" found "<<endl;
                        // So as to avpod taking same str again, else itll go into looping
                        mp[str]++;
                        q.push({str, len + 1});
                    }
                }
                // Since match is foudn , break off the loop and proceed with next queue ele
                if (break1)
                    break;
            }
        }

        // If ans is not changed means we could not make it from satrt to stop hence return 0
        return ans != INT_MAX ? ans : 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<string> wordList(n);
        for (int i = 0; i < n; i++)
            cin >> wordList[i];
        string startWord, targetWord;
        cin >> startWord >> targetWord;
        Solution obj;
        int ans = obj.wordLadderLength(startWord, targetWord, wordList);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends