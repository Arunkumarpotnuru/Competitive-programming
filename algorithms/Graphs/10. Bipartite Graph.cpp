//bfs 

#include <bits/stdc++.h>
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
    	int n = edges.size();
    	vector<int> adj[n];
    
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<n;j++)
    		{
    			if(edges[i][j])
    			adj[i].push_back(j);
    		}
    	}
    
    	vector<int>color(n,-1);
    	color[0]=0;
    	queue<int>q;
    	q.push(0);
    
    	while(!q.empty()){
    		int node = q.front();
    		q.pop();
    
    		for(auto nbr: adj[node])
    		{
    			if(color[nbr]==-1)
    			{
    				color[nbr] = ! color[node];
    				q.push(nbr);
    			}
    			else if(color[nbr] == color[node])
    			return false;
    		}
    	}
    	return true;
}

// dsf algorithm

#include<bits/stdc++.h>
bool dfs(int node,int color,vector<int>&col,vector<int>adj[])
{
  	col[node] = color;
  	for(auto nbr : adj[node])
  	{
  		 if(col[nbr] == -1)
  		 {
  			 if(dfs(nbr,!color,col,adj)== false)
  			 return false;
  		 }
  		 else if(col[nbr] == col[node]) return false;
  	}
  	return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
  	// Write your code here.
  	int n = edges.size();
  	vector<int>adj[n];
  	for(int i=0;i<n;i++)
  	{
  		for(int j=0;j<n;j++)
  		{
  			if(edges[i][j])
  			adj[i].push_back(j);
  		}
  	}
  	vector<int>col(n,-1);
  	return dfs(0,0,col,adj);// starting node, color,adj
}
