// sc = O(n) {O(n) for vis array, O(n) for ans array , O(n) auxiliary stack space}
// tc = O(n + 2E) for undirected graph, for directed graph tc = O(n + E)
class Solution {
  public:
    
    void dfs(int node,vector<int>&ans,vector<int>&vis,vector<int> adj[])
    {
        vis[node] = 1;
        ans.push_back(node);
        
        for(auto nbr: adj[node])
        {
            if(vis[nbr]==0)
            {
                dfs(nbr,ans,vis,adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int>ans;
        vector<int>vis(V,0);
        dfs(0,ans,vis,adj);
        
        return ans;
        
    }
};
