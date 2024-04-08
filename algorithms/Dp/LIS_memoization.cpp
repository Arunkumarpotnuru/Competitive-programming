// this code will give TLE for n>1e4
// fun(ind,prev_ind) will return longest increasing subsequence starting from index ind, whose previous index is prev_ind
// note: we shift the co-ordinate by 1 , so that we can store prev_ind=-1;
// sc-> O(n x n)+ Auxiliary stack space
// Tc-> O(n x n)
int fun(int ind,int prev_ind,int *arr,int n,vector<vector<int>>&dp)
{
    	if(ind == n) return 0;//base case
    
    	if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
    
    	int not_take = 0+ fun(ind+1,prev_ind,arr,n,dp);
    	int take = INT_MIN;
    	if(prev_ind==-1 || arr[ind]>arr[prev_ind])
    	{
    		take = 1 + fun(ind+1,ind,arr,n,dp);
    	}
    	return dp[ind][prev_ind+1] = max(take,not_take);
}

int longestIncreasingSubsequence(int* arr, int n) {
  	// Write your code here
  	vector<vector<int>>dp(n,vector<int>(n+1,-1));
  	return fun(0,-1,arr,n,dp);
}
