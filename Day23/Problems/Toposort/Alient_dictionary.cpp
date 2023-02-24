/*
Alien Dictionary
HardAccuracy: 47.81%Submissions: 55K+Points: 8
Lamp
Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!

Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.


Example 1:

Input:
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is
'b', 'd', 'a', 'c' Note that words are sorted
and in the given language "baa" comes before
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
Example 2:

Input:
N = 3, K = 3
dict = {"caa","aaa","aab"}
Output:
1
Explanation:
Here order of characters is
'c', 'a', 'b' Note that words are sorted
and in the given language "caa" comes before
"aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.


Your Task:
You don't need to read or print anything. Your task is to complete the function findOrder() which takes  the string array dict[], its size N and the integer K as input parameter and returns a string denoting the order of characters in the alien language.


Expected Time Complexity: O(N * |S| + K) , where |S| denotes maximum length.
Expected Space Compelxity: O(K)


Constraints:
1 ≤ N, M ≤ 300
1 ≤ K ≤ 26
1 ≤ Length of words ≤ 50
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> ts(vector<int> adj[], int N)
    {
        vector<int> indeg(N, 0);
        vector<int> topo;
        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            for (auto adjn : adj[i])
            {
                indeg[adjn]++;
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            for (auto adjn : adj[node])
            {
                indeg[adjn]--;
                if (indeg[adjn] == 0)
                {
                    q.push(adjn);
                }
            }
        }
        return topo;
    }
    string findOrder(string dict[], int N, int K)
    {
        // code here
        vector<int> adj[K];
        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int p = 0;
            int len = min(s1.size(), s2.size());
            for (int ptr = 0; ptr < len; ptr++)
            {
                if (s1[ptr] != s2[ptr])
                {
                    // since s1 is upper string and s2 is alter, hence if char mismatch occurs
                    // we can asusme that mismatched char of s1 comes before character of s2
                    // and since we are finding topo soprt we assume there is edge from
                    // s1's char to s2'char which are mismatched
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }
        // Now graph is ready, all we nee need to do is find toposort
        vector<int> topo = ts(adj, K);
        string soln = "";
        for (auto e : topo)
        {
            soln += (e + 'a'); // Code back to character
        }
        // cout<<soln<<endl;
        return soln;
    }
};