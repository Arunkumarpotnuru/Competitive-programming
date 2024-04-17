//bfs
// there might be an error

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool bfs(int src, vector<int> adj[], vector<int>&vis) {
      vis[src] = 1; 
      
      queue<pair<int,int>> q; 
      q.push({src, -1}); 
      // {node,parent}
   
      while(!q.empty()) {
          auto temp = q.front(); q.pop();
          int node = temp.first; 
          int parent = temp.second; 
          
          for(auto nbr: adj[node]) {
              
              if(!vis[nbr]) {
                  vis[nbr] = 1; 
                  q.push({nbr, node}); 
              }
              // if adjacent node is visited and is not it's own parent node
              else if(parent != nbr) {
                  //it is a cycle
                  return true; 
              }
          }
      }
      // there's no cycle
      return false; 
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(bfs(i,adj,vis)) return true;
            }
        }
        return false;
    }
};

// dfs

class Solution {
  private: 
    bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
        vis[node] = 1; 
        // visit adjacent nodes
        for(auto nbr: adj[node]) {
            // unvisited adjacent node
            if(!vis[nbr]) {
                if(dfs(nbr, node, vis, adj) == true) 
                    return true; 
            }
            // visited node but not a parent node
            else if(adjacentNode != parent) return true; 
        }
        return false; 
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       int vis[V] = {0}; 
       // for graph with connected components 
       for(int i = 0;i<V;i++) {
           if(!vis[i]) {
               if(dfs(i, -1, vis, adj) == true) return true; 
           }
       }
       return false; 
    }
};
