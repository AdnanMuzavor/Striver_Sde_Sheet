/*

733. Flood Fill
Easy
6.6K
657
Companies
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

 

Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.
 

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         //Getting rows and columns
        int rows=image.size();
        int cols=image[0].size();
        //Making visisted array to keep track of visited positions
        vector<vector<int>> vis(rows,vector<int>(cols,0));
        //Queue to help visiting indexes
        queue<pair<int,int>> q;
        //Filling first index as we are going to visist them
        q.push({sr,sc});
        //Marking it visisted
        vis[sr][sc]=1;
         //Starting pixel color
        int color=image[sr][sc];
        //Changing color of source
        image[sr][sc]=newColor;
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x-1>=0 && vis[x-1][y]==0 && image[x-1][y]==color){
                image[x-1][y]=newColor; //Changing to new color
                vis[x-1][y]=1; //Making it visited
                q.push({x-1,y}); //Pushing into queue to visit it's adjacent
            }
              if(y-1>=0 && vis[x][y-1]==0 && image[x][y-1]==color){
                image[x][y-1]=newColor; //Changing to new color
                vis[x][y-1]=1; //Making it visited
                q.push({x,y-1}); //Pushing into queue to visit it's adjacent
            }
              if(x+1<rows && vis[x+1][y]==0 && image[x+1][y]==color){
                image[x+1][y]=newColor; //Changing to new color
                vis[x+1][y]=1; //Making it visited
                q.push({x+1,y}); //Pushing into queue to visit it's adjacent
            }
               if(y+1<cols && vis[x][y+1]==0 && image[x][y+1]==color){
                image[x][y+1]=newColor; //Changing to new color
                vis[x][y+1]=1; //Making it visited
                q.push({x,y+1}); //Pushing into queue to visit it's adjacent
            }
        }
        return image;
    }
};