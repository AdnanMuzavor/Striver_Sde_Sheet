/*

133. Clone Graph
Medium
7.3K
3K
Companies
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}


Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.



Example 1:


Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
Example 2:


Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
Example 3:

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
*/

#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
// NOT AN EEFICINT APPROACH
class Solution
{
public:
    // Firts lets map each node with it's clone
    unordered_map<Node *, Node *> mp;
    // keep track of ehich node has been cloned as yet
    unordered_map<Node *, int> vis;

    // Function to map original nodes iwth clone nodes
    void map_the_Clone(Node *node)
    {
        if (!node)
            return;
        Node *newNode = new Node(node->val);
        mp[node] = newNode;
        cout << " mapped " << node->val << endl;
        if (node->neighbors.size() == 0)
            return;
        for (auto neb : node->neighbors)
        {
            if (!mp[neb])
            {
                map_the_Clone(neb);
            }
        }
    }

    // Function to clone the graph
    Node *clone(Node *node)
    {
        if (!node)
            return node;
        Node *dupnode = mp[node];
        vis[node] = 1;
        for (auto neb : node->neighbors)
        {
            dupnode->neighbors.push_back(mp[neb]);
            if (!vis[neb])
            {
                clone(neb);
            }
        }
        return dupnode;
    }
    Node *cloneGraph(Node *node)
    {
        map_the_Clone(node);
        return clone(node);
    }
};

//Efficient Approach
unordered_map<Node*,Node*> mp;
Node* dfs(Node* node){
    //Clone the current node
    Node* newnode=new Node(node->val);
    mp[node]=newnode; //Node clone node iwth original node
    //Create clone for adjcent/ if created directly push in neighbors matrix
    for(auto e:node->neighbors){
    //Check if this node was cloen or not
    if(mp[e]){
        //If cloned, push into neighbors
         newnode->neighbors.push_back(mp[e]);
    }
        else{
            //If not create one and push it in
            //Clone can bevcreated by calling same function
             newnode->neighbors.push_back(dfs(e));
        }
    }
    
   return newnode;
}
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        //If node with no neighbors
        if(node->neighbors.size()==0){
            Node* newnode=new Node(node->val);
            return newnode;
                
        }
        return dfs(node);
    }
};