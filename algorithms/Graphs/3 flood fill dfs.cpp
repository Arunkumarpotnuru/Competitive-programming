// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
// You are also given three integers sr, sc, and color. 
//You should perform a flood fill on the image starting from the pixel image[sr][sc].
// To perform a flood fill, consider the starting pixel, plus 
//any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally 
//to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
// Return the modified image after performing the flood fill.

class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& image,vector<vector<int>>&ans,int color,int original)
    {
        if(i<0 or i==image.size() or j<0 or j== image[0].size()) return ;
        if(image[i][j] != original or ans[i][j]== color) return ;

        ans[i][j]= color;
        dfs(i,j-1,image,ans,color,original);
        dfs(i-1,j,image,ans,color,original);
        dfs(i,j+1,image,ans,color,original);
        dfs(i+1,j,image,ans,color,original);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;

        dfs(sr,sc,image,ans,color,image[sr][sc]);

        return ans;
    }
};
