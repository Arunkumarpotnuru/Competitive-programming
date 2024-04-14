// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.
// If there are multiple valid strings, return any of them.

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(str1[i-1] == str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
                else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        int i=m,j=n;
        string ans;
        while(i>0 and j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans+= str1[i-1];
                i--;
                j--;
            }
            else if(dp[i][j-1] >dp[i-1][j])
            {
                ans+= str2[j-1];
                j--;
            }
            else
            {
                ans+= str1[i-1];
                i--;
            }

        }
        reverse(ans.begin(),ans.end());
        if(i>0)
        ans = str1.substr(0,i) + ans;
        if(j>0)
        ans = str2.substr(0,j) + ans;

        return ans;
    }
};
