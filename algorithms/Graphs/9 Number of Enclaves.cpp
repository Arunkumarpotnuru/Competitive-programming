// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off
//the boundary of the grid.
// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.


class Solution {
public:
    int row ,col;
    void dfs(int i,int j,vector<vector<int>> &temp)
    {
        if(i<0 or j<0 or i>=row or j>= col) return;
        if(temp[i][j] != 1) return;

        temp[i][j]=0;
        for(int r = -1 ; r<=1; r++)
        {
            for(int c=-1; c<=1; c++)
            {
                if(abs(r)+abs(c)==2) continue;
                dfs(i+r,j+c,temp);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>>temp = grid;
        row = grid.size();
        col = grid[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0 or i==row-1 or j==0 or j==col-1)
                {
                    dfs(i,j,temp);
                }
            }
        }

        int ans = 0 ;
        for(auto x: temp)
        {
            for(auto y: x)
            ans+= y;
        }
        return ans;
    }
};
