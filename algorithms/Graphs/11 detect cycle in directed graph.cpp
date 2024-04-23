// dfs
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

// cycle detection using kahns algorithm

class Solution {
public:
  	// Function to detect cycle in a directed graph.
  	bool isCyclic(int V, vector<int> adj[]) {
  		int indegree[V] = {0};
  		for (int i = 0; i < V; i++) {
  			for (auto it : adj[i]) {
  				indegree[it]++;
  			}
  		}
  
  		queue<int> q;
  		for (int i = 0; i < V; i++) {
  			if (indegree[i] == 0) {
  				q.push(i);
  			}
  		}
  
  		int cnt = 0;
  		// o(v + e)
  		while (!q.empty()) {
  			int node = q.front();
  			q.pop();
  			cnt++;
  			// node is in your topo sort
  			// so please remove it from the indegree
  
  			for (auto it : adj[node]) {
  				indegree[it]--;
  				if (indegree[it] == 0) q.push(it);
  			}
  		}
  
  		if (cnt == V) return false;
  		return true;
  	}
};

