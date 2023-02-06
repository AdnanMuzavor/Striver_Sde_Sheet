/*
Pair Sum
Difficulty: EASY
Contributed By
Ashwani
|
Level 1
Avg. time to solve
15 min
Success Rate
90%
Problem Statement
Sample Input 1:
5 5
1 2 3 4 5
Sample Output 1:
1 4
2 3
Explaination For Sample Output 1:
Here, 1 + 4 = 5
      2 + 3 = 5
Hence the output will be, (1,4) , (2,3).
Sample Input 2:
5 0
2 -3 3 3 -2
Sample Output 2:
-3 3
-3 3
-2 2

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
      // Write your code here.
      // Bruet force
      // Clearing question
      //-> No unique pairs
      //-> An element considered before can eb taken again
      //-> prev instance of pair should come first and then secodn instance
      vector<vector<int>> op;
      int n = arr.size();
      for (int i = 0; i < n - 1; i++)
      {
            for (int j = i + 1; j < n; j++)
            {
                  if (arr[i] + arr[j] == s)
                  {
                        vector<int> curr(2);
                        if (arr[i] <= arr[j])
                        {
                              curr[0] = arr[i];
                              curr[1] = arr[j];
                        }
                        else
                        {
                              curr[0] = arr[j];
                              curr[1] = arr[i];
                        }
                        op.push_back(curr);
                  }
            }
      }
      sort(op.begin(), op.end());
      return op;
}