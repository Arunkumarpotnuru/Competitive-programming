// sc O(n x n)
// tc o(n x n)
int longestIncreasingSubsequence(int* arr, int n) {

    	vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    
    	for(int ind = n-1;ind>=0;ind--)
    	{
    		for(int prev_ind= ind-1;prev_ind>=-1;prev_ind--)
    		{
    			int notTake = 0 + dp[ind+1][prev_ind+1]; 
    			int take = INT_MIN;
    			if(prev_ind==-1 || arr[ind]>arr[prev_ind])
    			{
    				take = 1 + dp[ind+1][ind + 1];
    			}
    			dp[ind][prev_ind+1] = max(take,notTake);
    		}
    	}
    	return dp[0][-1+1];
}

//--------------------------------------------
// space optimized version
// replace dp[ind+1] with next
// replace dp[ind] with curr
// Tc o(n x n)
// sc o(n) x 2
int longestIncreasingSubsequence(int* arr, int n) {

	
	vector<int>curr(n+1);
	vector<int>next(n+1);
	for(int ind = n-1;ind>=0;ind--)
	{
		for(int prev_ind= ind-1;prev_ind>=-1;prev_ind--)
		{
			int notTake = 0 + next[prev_ind+1]; 
			int take = INT_MIN;
			if(prev_ind==-1 || arr[ind]>arr[prev_ind])
			{
				take = 1 + next[ind + 1];
			}
			curr[prev_ind+1] = max(take,notTake);
		}
		next = curr;
	}
	return next[-1+1];
}

//----------------------------------------------------
// Tc O(n x n)
// sc o(n)

int longestIncreasingSubsequence(int* arr, int n) {
	vector<int>dp(n,1);
	int ans= 1;
	for(int i=0;i<n;i++)
	{
		for(int prev = 0;prev<i;prev++)
		{
			 if(arr[i]>arr[prev])
			 {
				 dp[i] = max(dp[i],1+dp[prev]);
			 }
		}
		ans = max(ans,dp[i]);
	}
	return ans;
}
