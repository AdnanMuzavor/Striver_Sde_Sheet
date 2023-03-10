/*

721. Accounts Merge
Medium
5.4K
918
Companies
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.



Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'],
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Example 2:

Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]


Constraints:

1 <= accounts.length <= 1000
2 <= accounts[i].length <= 10
1 <= accounts[i][j].length <= 30
accounts[i][0] consists of English letters.
accounts[i][j] (for j > 0) is a valid email.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int giveP(vector<int> &parr, int node)
    {
        if (parr[node] == node)
            return node;
        else
            return parr[node] = giveP(parr, parr[node]);
    }
    void union1(vector<int> &parr, vector<int> &rank, int u, int v)
    {
        int parr_u = giveP(parr, u);
        int parr_v = giveP(parr, v);
        if (parr_u == parr_v)
        {
            return;
        }
        if (rank[parr_u] > rank[parr_v])
        {
            parr[parr_v] = parr_u;
        }
        else if (rank[parr_v] > rank[parr_u])
        {
            parr[parr_u] = parr_v;
        }
        else
        {
            parr[parr_u] = parr_v;
            rank[parr_v]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        // => Lets consider each vector as node and map the email to that node number
        int node_no = 0;

        int n = accounts.size(); // no of nodes

        vector<int> rank(n, 0);
        vector<int> parr(n, 0);

        for (int i = 0; i < n; i++)
        {
            parr[i] = i;
        }

        unordered_map<string, int> mp;
        vector<vector<string>> op;

        for (auto entries : accounts)
        {
            for (int i = 1; i < entries.size(); i++)
            {
                // => If current email is not mapped , map it to node number
                string email = entries[i];

                if (!mp.count(email))
                {

                    mp[email] = node_no;
                }
                else
                {

                    // This means all mails in current entry should be added
                    // to the node_no where mp[email] is MAPPED
                    // We do this using disjoint set
                    union1(parr, rank, node_no, mp[email]);
                }
            }
            // Update node number to map next entries
            node_no++;
        }
        for (int i = 0; i < n; i++)
        {
            // to keep uniquye emails
            set<string> temp;
            // to sort and add to op
            vector<string> t2;

            // If current elemnt is parent of itsel f means it's boss and other
            // emails if any will be attched to it
            if (parr[i] == i)
            {

                // push all emails
                for (int j = 1; j < accounts[i].size(); j++)
                    temp.insert(accounts[i][j]);

                // push other elements whose parent is (i) i.e linked with same name
                for (int j = 0; j < n; j++)
                {
                    if (j != i && giveP(parr, j) == i)
                    {
                        // Start from 01 to avoid pushing the name
                        for (int k = 1; k < accounts[j].size(); k++)
                            temp.insert(accounts[j][k]);
                    }
                }

                // push ele from set into vector for sorting
                for (auto e : temp)
                {
                    cout << e << " ";
                    t2.push_back(e);
                }

                // sort the temp
                sort(t2.begin() + 1, t2.end());

                t2.insert(t2.begin(), accounts[i][0]); // Push name ay first positiom

                // push temp in op
                op.push_back(t2);

                // continue...
            }
        }
        return op;
    }
};

// Reformed code
class Solution
{
public:
    int giveP(vector<int> &parr, int node)
    {
        if (parr[node] == node)
            return node;
        else
            return parr[node] = giveP(parr, parr[node]);
    }
    void union1(vector<int> &parr, vector<int> &rank, int u, int v)
    {
        int parr_u = giveP(parr, u);
        int parr_v = giveP(parr, v);
        if (parr_u == parr_v)
        {
            return;
        }
        if (rank[parr_u] > rank[parr_v])
        {
            parr[parr_v] = parr_u;
        }
        else if (rank[parr_v] > rank[parr_u])
        {
            parr[parr_u] = parr_v;
        }
        else
        {
            parr[parr_u] = parr_v;
            rank[parr_v]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        // => Lets consider each vector as node and map the email to that node number
        int node_no = 0;

        int n = accounts.size(); // no of nodes

        vector<int> rank(n, 0);
        vector<int> parr(n, 0);

        for (int i = 0; i < n; i++)
        {
            parr[i] = i;
        }

        unordered_map<string, int> mp;
        vector<vector<string>> op;

        for (auto entries : accounts)
        {
            for (int i = 1; i < entries.size(); i++)
            {
                // => If current email is not mapped , map it to node number
                string email = entries[i];

                if (!mp.count(email))
                {

                    mp[email] = node_no;
                }
                else
                {

                    // This means all mails in current entry should be added
                    // to the node_no where mp[email] is MAPPED
                    // We do this using disjoint set
                    union1(parr, rank, node_no, mp[email]);
                }
            }
            // Update node number to map next entries
            node_no++;
        }

        vector<string> mergeMail[n];
        for (auto it : mp)
        {
            string mail = it.first;                 // Get the mail
            int main_node = giveP(parr, it.second); // Get the aprent node
            // push the current mail to the parent node's vector
            mergeMail[main_node].push_back(mail);
        }

        // Make the op vector
        for (int i = 0; i < n; i++)
        {
            // If current node has no mails, that means it must be having a prent node
            // to which all other nodes are attached
            if (mergeMail[i].size() == 0)
                continue;
            // Otherise first make a temp vector to pbe pushed to op
            vector<string> temp;
            // push name
            temp.push_back(accounts[i][0]);
            // Sort the vector at mergeMail[i]
            sort(mergeMail[i].begin(), mergeMail[i].end());
            // push these sorted mails into the op temp
            for (auto mail : mergeMail[i])
            {
                temp.push_back(mail);
            }
            // push the temp into ans
            op.push_back(temp);
        }
        return op;
    }
};