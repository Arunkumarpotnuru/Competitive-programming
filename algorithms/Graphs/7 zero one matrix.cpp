// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
// The distance between two adjacent cells is 1.

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m= mat.size();
        int n= mat[0].size();
        vector<vector<int>>res(m,vector<int>(n,0));
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int drow[]= {-1,0,1,0};
        int dcol[]= {0,1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;

            res[r][c]= d;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr= r+ drow[i];
                int nc= c+ dcol[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc])
                {
                    vis[nr][nc]=1;
                    q.push({{nr,nc},d+1});
                }

            }
        }
        return res;
    }
};
