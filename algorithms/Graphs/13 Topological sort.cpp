// topological sort works only on directed acyclic graph
// topological sort is linear ordering such that if there is an edge between u and v, u appears before v in the ordering
// dfs
#include <bits/stdc++.h> 
void dfs(int node,vector<int> adj[],vector<int>&vis,stack<int>&st)
{
    vis[node]=1;
    for(auto nbr: adj[node])
    {
        if(!vis[nbr])
        {
            dfs(nbr,adj,vis,st);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
 
    stack<int>st;
    vector<int> adj[v];
    vector<int>vis(v,0);

    for(auto x: edges)
    adj[x[0]].push_back(x[1]);


    for(int i=0;i<v;i++)
    {
        if(vis[i]==0)
        dfs(i,adj,vis,st);
    }

    vector<int>ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

// topological sort using kahn's algorithm
class Solution {
public:
  	//Function to return list containing vertices in Topological order.
  	vector<int> topoSort(int V, vector<int> adj[])
  	{
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
  		vector<int> topo;
  		while (!q.empty()) {
  			int node = q.front();
  			q.pop();
  			topo.push_back(node);
  			// node is in your topo sort
  			// so please remove it from the indegree
  
  			for (auto it : adj[node]) {
  				indegree[it]--;
  				if (indegree[it] == 0) q.push(it);
  			}
  		}
  
  		return topo;
  	}
};
