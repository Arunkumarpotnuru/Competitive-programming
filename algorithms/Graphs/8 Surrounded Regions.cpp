// Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

class Solution {
public:
    int row ,col;
    void dfs(int i,int j,vector<vector<char>>& temp)
    {
        if(i<0 or j<0 or i>=row or j>=col) return;
        if(temp[i][j]!='O') return;
        
        temp[i][j]='Y';
        for(int r=-1;r<=1;r++)
        {
            for(int c=-1;c<=1;c++)
            {
                if(abs(r)+abs(c)==2) continue;
                dfs(i+r,j+c,temp);
            }
        }
        
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<char>>temp = board;
        row = board.size();
        col = board[0].size();

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0 or j==0 or i==row-1 or j==col-1)
                {
                    dfs(i,j,temp);
                }
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(temp[i][j]=='Y')
                board[i][j]='O';
                else
                board[i][j]='X';
            }
        }
        return;
    }
};
