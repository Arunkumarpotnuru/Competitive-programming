vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
      vector<int>bfs;
      vector<int>vis(n,0);
      queue<int>q;
  
      q.push(0);
      vis[0] = 1;
  
      while(!q.empty())
      {
          int node= q.front(); q.pop();
          bfs.push_back(node);
          for(auto nbr : adj[node])
          {
              if(vis[nbr]==0)
              {
                  q.push(nbr);
                  vis[nbr] =1;
              }
          }
      }
      return bfs;
}
