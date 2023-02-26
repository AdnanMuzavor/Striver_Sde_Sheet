/*

126. Word Ladder II
Hard
5.1K
658
Companies
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].



Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.


Constraints:

1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 500
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
The sum of all shortest transformation sequences does not exceed 105.
Accepted
338.3K
Submissions
1.2M
Acceptance Rate
27.5%
*/

#include <bits/stdc++.h>
using namespace std;

// STRIVER APPRAOCH | CP | INTERVIEW NOT NEEDED | LEETCODE ACCEPTED

class Solution
{
public:
    vector<vector<string>> op;
    // tO backtract and check later
    unordered_map<string, int> mp;

    void backtrack(string word, string begin, vector<string> temp)
    {
        // cout<<" at "<<word<<" which is at level "<<mp[word]<<endl;
        if (word == begin)
        {
            // cout<<"Found word matching with begin!!"<<endl;
            //  for(auto e:temp){
            //      cout<<e<<" <- ";
            //  }
            //  cout<<endl;
            reverse(temp.begin(), temp.end());
            op.push_back(temp);
            return;
        }
        string str = word;
        // Try replacing each character with other 25 chars and if str
        // formed exists then update the length and push new str into the queue
        for (int i = 0; i < str.size(); i++)
        {

            // cout<<"_________changing: "<<i<<" th char_____________"<<endl;
            str = word;
            for (char c = 'a'; c <= 'z'; c++)
            {

                str[i] = c;

                // Ele if str in dict, we shall find next version of str by including current
                // version henc elength too is increased
                if (mp[str] >= 1 && mp[str] == mp[word] - 1)
                {

                    // So as to avpod taking same str again, else itll go into looping
                    temp.push_back(str);
                    backtrack(str, begin, temp);
                    temp.pop_back();
                }
            }
        }
    }
    vector<vector<string>> findLadders(string startWord, string endWord, vector<string> &wordList)
    {

        // To help us know whether string exists in the list
        unordered_set<string> st;
        for (auto e : wordList)
        {
            if (e != startWord)
            {
                st.insert(e);
            }
        }

        if (st.find(endWord) == st.end())
            return op;

        // We shall start from startword
        queue<pair<string, int>> q;

        q.push({startWord, 1}); // Initally starting word and len = 1

        while (!q.empty())
        {
            auto tp = q.front();
            q.pop();
            int len = tp.second;
            string str = tp.first;
            // cout<<" mapped "<<str<<" with : "<<len<<endl;
            mp[str] = len;
            string init_str = str;

            if (str == endWord)
            {
                // cout<<"found "<<str<<" at level: "<<len<<endl;
                continue

                    ;
            } // We found the answer

            // Try replacing each character with other 25 chars and if str
            // formed exists then update the length and push new str into the queue
            for (int i = 0; i < str.size(); i++)
            {

                // cout<<"_________changing: "<<i<<" th char_____________"<<endl;
                str = init_str;
                for (char c = 'a'; c <= 'z'; c++)
                {

                    str[i] = c;

                    // Ele if str in dict, we shall find next version of str by including current
                    // version henc elength too is increased
                    if (st.find(str) != st.end())
                    {

                        // So as to avpod taking same str again, else itll go into looping
                        st.erase(str);
                        q.push({str, len + 1});
                    }
                }
            }
        }

        // for(auto e:mp){
        //     cout<<e.first<<" "<<e.second<<endl;
        // }

        vector<string> temp;
        temp.push_back(endWord);
        backtrack(endWord, startWord, temp);
        // If all its / combos are tried and we reach here means no Combos
        return op;
    }
};

// STRIVER APPROACH | MY  CODE | GFG ACCEPTED | LEETCODE FAILED

class Solution
{
public:
    int min(int a, int b)
    {
        if (a < b)
            return a;
        return b;
    }
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {
        // op vector
        vector<vector<string>> op;

        // To help us know whether string exists in the list
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end())
            return op;

        // We shall start from startword
        queue<vector<string>> q;

        vector<string> temp;
        temp.push_back(beginWord);
        q.push(temp); // Initally push vector with starting word and len = 1

        // prev_len will help us in deleting the string from set once all
        // combo for aprticular length are found
        int prev_len = 1;

        // ans_len will help us to add vectors only with min_len into op
        // and void any vectors with alrger length
        int ans_len = INT_MAX;

        // prev_Strs vector help us to keep record of prev level strs
        vector<string> prevstrs;
        while (!q.empty())
        {
            // Get the vector
            vector<string> temp2 = q.front();
            // cout<<" temp is: "<<endl;
            // for(auto e:temp2) cout<<e<<" ";
            // cout<<endl;
            q.pop();

            // if temp2.size()!=prev_len means
            // we have gone to next level and hence we can erase all the strings
            // from the set which were used in prev level
            if (temp2.size() != prev_len)
            {
                prev_len = temp2.size();
                for (auto e : prevstrs)
                {
                    st.erase(e);
                    prevstrs.clear();
                }
            }

            // extract last string
            string str = temp2[temp2.size() - 1];
            string init_str = str;
            // if string is endword, push vector in op

            if (str == endWord)
            {
                ans_len = min(ans_len, temp2.size());
                if (temp2.size() == ans_len)
                {
                    op.push_back(temp2);
                    continue; // Avoid processing this word
                }
            }

            // Try replacing each character with other 25 chars and if str
            // formed exists then update the length and push new str into the queue
            for (int i = 0; i < str.size(); i++)
            {

                // cout<<"_________changing: "<<i<<" th char_____________"<<endl;
                str = init_str;
                for (char c = 'a'; c <= 'z'; c++)
                {

                    str[i] = c;

                    // Ele if str in dict, we shall find next version of str by including current
                    // version henc elength too is increased
                    if (st.find(str) != st.end())
                    {
                        //  cout<<"found : "<<str<<endl;
                        // push it into temp2 and push temp2 into queue
                        // we dont erase the str until all vectors withy len
                        // eqraul to temp2 are processed
                        temp2.push_back(str);
                        prevstrs.push_back(str);
                        q.push(temp2);
                        temp2.pop_back();
                    }
                }
            }
        }

        // If all its / combos are tried and we reach here means no Combos
        return op;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for (string i : a)
        x += i;
    for (string i : b)
        y += i;

    return x < y;
}

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
        // vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
        vector<vector<string>> ans;
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            sort(ans.begin(), ans.end(), comp);
            for (int i = 0; i < ans.size(); i++)
            {
                for (int j = 0; j < ans[i].size(); j++)
                {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends

// BRUTE FORCE => MY CODE
class Solution
{
public:
    // Tell us about the list
    unordered_map<string, int> isIn;
    // Tell us if taken or not while the coorse of DFS
    unordered_map<string, bool> isTaken;
    // In length to tell us the min len
    int min_len = INT_MAX;
    // temp vector to help temp strings pushed
    vector<string> temp;
    // Op vector
    vector<vector<string>> op;
    void dfs(string word, string endWord, int len)
    {
        if (len > min_len)
            return;
        // If the word is end word, we can proceed to pushing tye ans in our op
        if (word == endWord)
        {
            if (len < min_len)
            {
                min_len = len;
                // cout<<" min  length is: "<<min_len<<endl;
            }
            if (temp.size() == min_len)
            {
                if (op.size() > 0 && op[0].size() != min_len)
                {
                    //  cout<<" op[0] : "<<op[0].size()<<" HENCE CLEARED"<<endl;
                    op.clear();
                }
                op.push_back(temp);
            }
            // op.push_back(temp);
            //  cout<<" word: "<<word<<" _ f _ o _ u _ n _ d"<<endl;

            return;
        }
        string temp_str = word;
        bool not_a_single = true;
        //  cout<<"Processing "<<temp_str<<endl;
        // Find if the word with replaced char at any position of word
        // exists in the list
        for (int i = 0; i < word.size(); i++)
        {
            temp_str = word;
            for (char c = 'a'; c <= 'z'; c++)
            {
                // replace the ith char
                temp_str[i] = c;

                // check if c is in the list
                if (isIn[temp_str] == 1 && !isTaken[temp_str])
                {
                    not_a_single = false;
                    //   cout<<"temp: "<<temp_str<<" in list and not taken"<<endl;
                    // Push this combo into temp vector
                    temp.push_back(temp_str);
                    // Mark teh str taken to avoid cycles|retaking if same str
                    isTaken[temp_str] = true;
                    // Go ahead with finding the next word
                    dfs(temp_str, endWord, len + 1);
                    // Pop it out as trying next
                    temp.pop_back();
                    // Then as you come abck, mark word as untaken,as we will try next combo
                    isTaken[temp_str] = false;
                }
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {

        // Marking presence of ele
        // Marking all ele as not taken yet
        for (auto e : wordList)
        {
            isIn[e] = 1;
            isTaken[e] = false;
        }

        // EDGE CASE
        // 1)What of target is NOT in dict,then it can never be achieved
        if (!isIn[endWord])
            return op;
        temp.push_back(beginWord);
        dfs(beginWord, endWord, 1);
        return op;
    }
};