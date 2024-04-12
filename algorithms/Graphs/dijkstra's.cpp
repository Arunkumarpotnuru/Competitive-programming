class Solution
{
  	public:
  	//Function to find the shortest distance of all the vertices
      //from the source vertex S.
      vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
      {
          // Code here
          vector<int> ans(v,1e9);
          ans[s]=0; // 
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
          pq.push({0,s}); // distance, node;
          
          while(!pq.empty())
          {
              auto it= pq.top(); pq.pop();
              int dist = it.first;
              int node = it.second;
              
              for(auto x: adj[node])
              {
                  int n= x[0]; // adjcent vertex;
                  int d= x[1]; // distance to adjacent vertex;
                  
                  if(dist+d<ans[n])
                  {
                      ans[n]= dist+d;
                      pq.push({ans[n],n});
                  }
              }
          }
          return ans;
      }
};
