class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int nf=0; // number of fresh oranges
        int m= grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                q.push({i,j});
                else if(grid[i][j]==1)
                nf++;
            }
        }
        if(nf==0) return 0;

        int ans=0;
        while(!q.empty())
        {
            int s= q.size();
            ans++;
            for(int i=0;i<s;i++)
            {
                int r= q.front().first;
                int c= q.front().second;
                q.pop();

                if(r-1>=0 && grid[r-1][c]==1)
                {
                    q.push({r-1,c});
                    grid[r-1][c]=2;
                }
                if(r+1<m && grid[r+1][c]==1)
                {
                    q.push({r+1,c});
                    grid[r+1][c]=2;
                }
                if(c-1>=0 && grid[r][c-1]==1)
                {
                    q.push({r,c-1});
                    grid[r][c-1]=2;
                }
                if(c+1<n && grid[r][c+1]==1)
                {
                    q.push({r,c+1});
                    grid[r][c+1]=2;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }

        return ans-1;
    }
};
