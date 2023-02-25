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

//BRUTE FORCE => MY CODE
class Solution {
public:
      //Tell us about the list
     unordered_map<string,int> isIn;
     //Tell us if taken or not while the coorse of DFS
     unordered_map<string,bool> isTaken;
     //In length to tell us the min len
     int min_len=INT_MAX;
     //temp vector to help temp strings pushed
     vector<string> temp;
      //Op vector
        vector<vector<string>> op;
     void dfs(string word, string endWord,int len){
         if(len>min_len) return;
         //If the word is end word, we can proceed to pushing tye ans in our op
         if(word==endWord){
             if(len<min_len){
                 min_len=len;
                 //cout<<" min  length is: "<<min_len<<endl;
             }
             if(temp.size()==min_len){
                 if(op.size()>0 && op[0].size()!=min_len){
                  //  cout<<" op[0] : "<<op[0].size()<<" HENCE CLEARED"<<endl;
                    op.clear();
                 }
                 op.push_back(temp);
             }
            // op.push_back(temp);
           //  cout<<" word: "<<word<<" _ f _ o _ u _ n _ d"<<endl;
             
             return;
         }
         string temp_str=word;
         bool not_a_single=true;
       //  cout<<"Processing "<<temp_str<<endl;
         //Find if the word with replaced char at any position of word
         //exists in the list
         for(int i=0;i<word.size();i++){
             temp_str=word;
             for(char c='a';c<='z';c++){
                 //replace the ith char
                 temp_str[i]=c;
                
                 //check if c is in the list
                 if(isIn[temp_str]==1 && !isTaken[temp_str]){
                       not_a_single=false;
                  //   cout<<"temp: "<<temp_str<<" in list and not taken"<<endl;
                     //Push this combo into temp vector
                     temp.push_back(temp_str);
                     //Mark teh str taken to avoid cycles|retaking if same str
                     isTaken[temp_str]=true;
                     //Go ahead with finding the next word
                     dfs(temp_str,endWord,len+1);
                     //Pop it out as trying next
                     temp.pop_back();
                     //Then as you come abck, mark word as untaken,as we will try next combo
                     isTaken[temp_str]=false;
                 }
             }
         }
     }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
       

        //Marking presence of ele
        //Marking all ele as not taken yet
        for(auto e:wordList){
            isIn[e]=1;
            isTaken[e]=false;
        }

        //EDGE CASE
        //1)What of target is NOT in dict,then it can never be achieved
        if(!isIn[endWord]) return op;
        temp.push_back(beginWord);
        dfs(beginWord,endWord,1);
        return op;
    }
};