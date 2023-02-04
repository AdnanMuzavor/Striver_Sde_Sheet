/*
74. Search a 2D Matrix
Medium

9286

300

Add to List

Share
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/
#include <bits/stdc++.h>
using namespace std;

//O(R+C)
//O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
       ///Sice matrix is sorted
        //CONCLUSION:
        //1)All elemnts left to current elements will be lesser
        //2)All elements right to current element will be greater
        //3)All elements below current element will be greater
        //4)All elements above current element will be lesser
        //5)We can surely get answer by moving in any 2 directions only
        //Lets start from right most corner
        int i=0,j=c-1;
        while(i<r && j>=0){
            if(matrix[i][j]==target) return true;
            //If matrix[i][j]>=target, smaller elements can be found on left
            //hence j--
            if(matrix[i][j]>target) j--;
            //If matrix[i][j]<target, greater elements can be found down
            //hence i++
            else i++;
        }
        return false;
    }
};