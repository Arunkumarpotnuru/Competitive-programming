// There are n cities. Some of them are connected, while some are not. 
//If city a is connected directly with city b, and city b is connected directly with city c,
//then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, 
// and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.
// solution 1 bfs
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // creating an adj list
        int n= isConnected.size();
        vector<int> adj[n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j])
                adj[i].push_back(j);
            }
        } // end

        vector<bool>vis(n,false);
        int ans=0;

        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                ans++;
                queue<int>q;
                q.push(i);

                while(q.empty()==false)
                {
                    int node= q.front();
                    q.pop();
                    for(int x: adj[node])
                    {
                        if(!vis[x])
                        {
                            vis[x]=true;
                            q.push(x);
                        }
                    }
                }
            }  
        }
        return ans;
    }
};

// solution 2
// dfs solution

class Solution {
public:
    void dfs(int node,vector<bool>&vis,vector<int>adj[])
    {
        vis[node]= true;
        for(int x: adj[node])
        {
            if(vis[x]==false)
            dfs(x,vis,adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // creating an adj list
        int n= isConnected.size();
        vector<int> adj[n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && isConnected[i][j])
                adj[i].push_back(j);
            }
        }

        vector<bool>vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=true)
            {
                ans++;
                dfs(i,vis,adj);
            }
        }
        return ans;
    }
};

// solution 3
// dsu solution
class Solution {
public:
    vector<int>parent;
    int find(int x)
    {
        return parent[x]== x? x : find(parent[x]);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n+1);

        for(int i=0;i<=n;i++) parent[i]=i;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isConnected[i][j] and find(i)!= find(j))
                {
                    parent[find(i)]= find(j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        if(parent[i]==i) ans++;

        return ans;
    }
};
