//infinite supply of coins
// recursive code 
// tc = >>O(2^n) because in "take" case , we don't reduce the index , so we have 2 more than 2 options at every index
// sc = >>O(n)
class Solution{

  	public:
  	int fun(int ind,int target,vector<int>&coins)
  	{
  	    if(ind ==0)
  	    {
  	        if(target % coins[0] == 0) return target/coins[0];
  	        else return 1e9;
  	    }
  	    int notTake = fun(ind-1,target,coins);
  	    int take = 1e9;
  	    if(coins[ind]<= target)
  	    take = 1+ fun(ind,target-coins[ind],coins);
  	    
  	    return min(notTake ,take);
  	}
  	int minCoins(vector<int> &coins, int n, int target) 
  	{ 
  	    // Your code goes here
  	    return fun(n-1,target,coins);
  	} 
};

// memoization
// tc = O(n x target)
// sc = O(n x target) + auxiliary stackspace
class Solution{

	public:
	int fun(int ind,int target,vector<int>&coins,vector<vector<int>>&dp)
	{
	    if(ind ==0)
	    {
	        if(target % coins[0] == 0) return target/coins[0];
	        else return 1e9;
	    }
	    
	    if(dp[ind][target] != -1) return dp[ind][target];
	    
	    int notTake = fun(ind-1,target,coins,dp);
	    int take = 1e9;
	    if(coins[ind]<= target)
	    take = 1+ fun(ind,target-coins[ind],coins,dp);
	    
	    return dp[ind][target] = min(notTake ,take);
	}
	int minCoins(vector<int> &coins, int n, int target) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(n,vector<int>(target+1,-1));
	    return fun(n-1,target,coins,dp)==1e9?-1 : fun(n-1,target,coins,dp);
	} 
	  
};

// tabulation
// tc = O(n x target)
// sc = O(n x target)

class Solution{
  public:
	int minCoins(vector<int> &coins, int n, int target) 
	{ 
  	    // Your code goes here
  	    vector<vector<int>>dp(n,vector<int>(target+1,0));
  	    for(int i=0;i<= target;i++)
  	    {
  	        if(i%coins[0]==0)
  	        dp[0][i] = i/coins[0];
  	        else
  	        dp[0][i] = 1e9;
  	    }
  	    for(int ind=1;ind<n;ind++)
  	    {
  	        for(int tar=0;tar<=target;tar++)
  	        {
  	            int notTake = dp[ind-1][tar];
  	            int take = 1e9;
  	            if(coins[ind]<= tar)
  	            take =1+ dp[ind][tar-coins[ind]];
  	            
  	            dp[ind][tar] = min(take,notTake);
  	        }
  	    }
  	    return dp[n-1][target]==1e9? -1: dp[n-1][target];
  	} 
  	  
};

// optimized code
// tc = O(target x n)
// sc = O(target)

class Solution{

  	public:
  	int minCoins(vector<int> &coins, int n, int target) 
  	{ 
  	    // Your code goes here
  	    vector<int>arr(target+1);
  	    arr[0]=0;
  	    
  	    for(int t=1;t<=target;t++)
  	    {
  	        arr[t]= 1e9;
  	        for(int c: coins)
  	        {
  	            if(t>=c)
  	            arr[t] = min(arr[t],1+arr[t-c]);
  	        }
  	    }
  	    return arr[target]==1e9?-1: arr[target];
  	} 
  	  
};

// if asked to give an example how such a solution can be constructed
// this code prints the solution

int first[N];
value[0] = 0;
for (int x = 1; x <= n; x++)
  {
    value[x] = INF;
    for (auto c : coins)
    {
        if (x-c >= 0 && value[x-c]+1 < value[x])
        {
            value[x] = value[x-c]+1;
            first[x] = c;
        }
    }
  }

while (n > 0) {
    cout << first[n] << "\n";
    n -= first[n];
}
