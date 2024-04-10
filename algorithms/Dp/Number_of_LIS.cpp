class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,1); // dp[i] : length of LIS ending with nums[i].
        vector<int>count(n,1); // count[i] : number of subsequences of maximumm length ending with nums[i].

        int llis=1; 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                     if(1+dp[j]>dp[i])
                    {
                        dp[i]= dp[j]+1;
                        count[i]= count[j];
                    }
                    else if((dp[j]+1)== dp[i])
                    {
                        count[i]+= count[j];
                    }
                }
            }
            llis= max(llis,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++) if(dp[i]==llis) ans+= count[i];
        
        return ans;
    }
};
