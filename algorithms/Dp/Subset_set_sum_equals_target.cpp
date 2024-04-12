// recursive code to check if there exists a subset whoose sum is equal to target
// fun(ind,target,arr) Returns true if there exists a subset whose sum is equal to the target, considering indices
//starting from 0 to ind in the array arr
// tc = O(2^n)
// sc = O(n)

#include <bits/stdc++.h> 
bool fun(int ind,int target,vector<int>&arr)
{
    if(target == 0) return true;
    if(ind == 0) return arr[0]== target;

    bool notTake = fun(ind-1,target,arr);
    bool take = false;

    if(arr[ind] <= target)
    take = fun(ind-1,target-arr[ind],arr);

    return take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return fun(n-1,k,arr);
}

// to reduce the tc we memoize the recursive function
// tc = O(n x target)
// sc = O(n x target)+ auxiliary stack space
#include <bits/stdc++.h> 
bool fun(int ind,int target,vector<int>&arr,vector<vector<int>>&dp)
{
    if(target == 0) return true;
    if(ind == 0) return arr[0]== target;

    if(dp[ind][target]!=-1) return dp[ind][target];

    bool notTake = fun(ind-1,target,arr,dp);
    bool take = false;

    if(arr[ind] <= target)
    take = fun(ind-1,target-arr[ind],arr,dp);

    return dp[ind][target]  = take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return fun(n-1,k,arr,dp);
}

// tabulation code
// tc = O(n)
// sc = O(n)

#include <bits/stdc++.h> 
bool subsetSumToK(int n, int target, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>>dp(n,vector<bool>(target+1,false));
    for(int i=0;i<n;i++) dp[i][0] = true;
    if(arr[0]<= target) dp[0][arr[0]] = true;

    for(int ind=1;ind<n;ind++)
    {
        for(int tar = 1;tar<= target;tar++)
        {
             bool notTake = dp[ind-1][tar];
             bool take = false;
             if(arr[ind]<= tar)
             take = dp[ind-1][tar-arr[ind]];

             dp[ind][tar] = take || notTake;
        }
    }
    return dp[n-1][target];
}

// space optimized version
// tc = O(n x target)
// sc = O(target)

#include <bits/stdc++.h> 
bool subsetSumToK(int n, int target, vector<int> &arr) {
    // Write your code here.
   

    vector<bool>prev(target+1,false) , curr(target+1,false);
    prev[0]=curr[0]= true;
   
    if(arr[0]<= target) prev[arr[0]] = true;

    for(int ind=1;ind<n;ind++)
    {
        for(int tar = 1;tar<= target;tar++)
        {
             bool notTake = prev[tar];
             bool take = false;
             if(arr[ind]<= tar)
             take = prev[tar-arr[ind]];

             curr[tar] = take || notTake;
        }
        prev = curr;
    }
    return prev[target];
}
