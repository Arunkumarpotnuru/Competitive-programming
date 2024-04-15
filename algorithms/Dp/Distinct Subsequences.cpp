//Given two strings s and t, return the number of distinct subsequences of s which equals t.

// recursion
// tc = O(2^m x 2^n)
class Solution {
public:
    int fun(int i,int j,string &s,string &t)
    {
        if(j<0) return 1;
        if(i<0) return 0;

        if(s[i] == t[j])
        {
            return fun(i-1,j-1,s,t) + fun(i-1,j,s,t);
        }
        else
        {
            return fun(i-1,j,s,t);
        }
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        return fun(m-1,n-1,s,t);
    }
};

// tabulation code:
class Solution {
public:
    //used double to deal with overflow issue
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<double>>dp(m+1,vector<double>(n+1,0));
        for(int i=0;i<=m;i++) dp[i][0]=1;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[m][n];
    }
};
