// fun(ind,w) tells maximum money we can loot considering till index ind, with bag weight of w ;
// recursive code
// tc = O(2^n) sc = O(n)
#include <bits/stdc++.h> 
int fun(int ind, int w,vector<int> &weight, vector<int>&value)
{
  	if(ind==0)
  	{
  		if(weight[0]<= w) return value[0] ;
  		else return 0;
  	}
  	int notPick = fun(ind-1,w,weight,value);
  	int pick = INT_MIN;
  
  	if(w >= weight[ind])
  	pick = value[ind]+ fun(ind-1,w-weight[ind],weight,value);
  
  	return max(notPick,pick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
  	// Write your code here
  	return fun(n-1,maxWeight,weight,value);
}

// memoization code
// tc = O( maxWeight x n)
// sc = O(maxWeight x n) + auxiliary stackspace
#include <bits/stdc++.h> 
int fun(int ind, int w,vector<int> &weight, vector<int>&value,vector<vector<int>>&dp)
{
  	if(ind==0)
  	{
  		if(weight[0]<= w) return value[0] ;
  		else return 0;
  	}
  
  	if(dp[ind][w]!=-1) return dp[ind][w];
  	int notPick = fun(ind-1,w,weight,value,dp);
  	int pick = INT_MIN;
  
  	if(w >= weight[ind])
  	pick = value[ind]+ fun(ind-1,w-weight[ind],weight,value,dp);
  
  	return dp[ind][w] =  max(notPick,pick);
  }
  int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
  {
  	// Write your code here
  	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
  	return fun(n-1,maxWeight,weight,value,dp);
}

// tabulation
// sc O(n x maxWeight)
// tc O(n x maxWeight)

#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
  	vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
  	for(int i = 1;i<= maxWeight;i++)
  	{
  		if(i<weight[0]) dp[0][i]=0;
  		else dp[0][i]= value[0];
  	}
  	for(int ind = 1;ind<n;ind++)
  	{
  		for(int w =1;w<=maxWeight;w++)
  		{
  			int notPick = 0 + dp[ind-1][w];
  			int pick = INT_MIN;
  
  			if(weight[ind]<=w)
  			pick = value[ind]+ dp[ind-1][w-weight[ind]];
  
  			dp[ind][w] = max(notPick,pick);
  		}
  	}
  	return dp[n-1][maxWeight];
}

// space optimization
// sc = O(maxWeight)
// tc = O(n x maxWeight)

#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
  	vector<int> prev(maxWeight+1) , curr(maxWeight+1);
  	
  	for(int i = 1;i<= maxWeight;i++)
  	{
  		if(i<weight[0]) prev[i]=0;
  		else prev[i]= value[0];
  	}
  	for(int ind = 1;ind<n;ind++)
  	{
  		for(int w =1;w<=maxWeight;w++)
  		{
  			int notPick = 0 + prev[w];
  			int pick = INT_MIN;
  
  			if(weight[ind]<=w)
  			pick = value[ind]+prev[w-weight[ind]];
  
  			curr[w] = max(notPick,pick);
  		}
  		prev = curr;
  	}
  	return prev[maxWeight];
}
// we can further optimize this code by using single array instead of prev and curr
