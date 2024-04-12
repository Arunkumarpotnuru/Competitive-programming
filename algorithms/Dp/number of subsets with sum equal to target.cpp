// recursive code
// tc = O(2^n)

//tabulation is still pending

#include<bits/stdc++.h>
int fun(int ind,int target,vector<int>&arr)
{
	if(ind==0)
	{
		 if(target == 0 and arr[0]==0) return 2;
		 else if(target ==0) return 1;
		 else if(target == arr[0]) return 1;
		 else return 0;
	}
	
	int notTake = fun(ind-1,target,arr);
	int take = 0;
	if(arr[ind]<= target)
	take = fun(ind-1,target-arr[ind],arr);

	return take+notTake;
}
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	return fun(n-1,k,arr);
}

// memoization
// tc = O( n x target)
// sc = O( n x target) + auxiliary stack space

#include<bits/stdc++.h>
int fun(int ind,int target,vector<int>&arr,vector<vector<int>>&dp)
{
	if(ind==0)
	{
		 if(target == 0 and arr[0]==0) return 2;
		 else if(target ==0) return 1;
		 else if(target == arr[0]) return 1;
		 else return 0;
	}

	if(dp[ind][target]!=-1) return dp[ind][target];
	
	int notTake = fun(ind-1,target,arr,dp);
	int take = 0;
	if(arr[ind]<= target)
	take = fun(ind-1,target-arr[ind],arr,dp);

	return dp[ind][target] = take+notTake;
}
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector<vector<int>>dp(n,vector<int>(k+1,-1));
	return fun(n-1,k,arr,dp);
}

