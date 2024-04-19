class Solution {
  public:
      // Function to detect cycle in a directed graph.
      bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&pathvis)
      {
          vis[node] = 1;
          pathvis[node]=1;
          
          for(auto nbr: adj[node])
          {
              if(vis[nbr]==0)
              {
                  if(dfs(nbr,adj,vis,pathvis))
                  return true;
              }
              else if(pathvis[nbr])
              return true;
          }
          pathvis[node] = 0;
          
          return false;
      }
      bool isCyclic(int n, vector<int> adj[]) {
          // code here
          vector<int> vis(n,0);
          vector<int> pathvis(n,0);
          
          for(int i=0;i<n;i++)
          {
              if(vis[i]==0)
              {
                  if(dfs(i,adj,vis,pathvis))
                  return true;
              }
          }
          return false;
      }
};
