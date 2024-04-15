// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

//recursion
// fun(i,j) returns weather s1[0-i] matches with s2[0-j]
class Solution {
public:
    bool fun(int i,int j,string &s,string &p)
    {
        if(i<0 and j<0) return true;
        if(i>=0 and j<0) return false;
        if(i<0 and j>=0)
        {
            while(j>=0)
            {
                if(p[j]!='*') return false;
                j--;
            }
            return true;
        }
        if(s[i] == p[j] or p[j]=='?')
        {
            return fun(i-1,j-1,s,p);
        }
        else if(p[j] == '*')
        {
            return fun(i,j-1,s,p) or fun(i-1,j,s,p);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        return fun(m-1,n-1,s,p);
    }
};

//memeoization
//tc = O(m x n)
// sc = O(m x n) + auxiliary stackspace
class Solution {
public:
    bool fun(int i,int j,string &s,string &p,vector<vector<int>>&dp)
    {
        if(i<0 and j<0) return true;
        if(i>=0 and j<0) return false;
        if(i<0 and j>=0)
        {
            while(j>=0)
            {
                if(p[j]!='*') return false;
                j--;
            }
            return true;
        }
        if(dp[i][j] != -1 ) return dp[i][j];
        if(s[i] == p[j] or p[j]=='?')
        {
            return dp[i][j] = fun(i-1,j-1,s,p,dp);
        }
        else if(p[j] == '*')
        {
            return dp[i][j] =  fun(i,j-1,s,p,dp) or fun(i-1,j,s,p,dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(m-1,n-1,s,p,dp);
    }
};

// tabulation
//tc = O(m x n)
// sc = O(m x n)
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));

        dp[0][0]= true;
        for(int i=1;i<=m;i++) dp[i][0] = false;
        for(int j=1;j<=n;j++)
        {
            if(p[j-1]=='*') dp[0][j] = true;
            else break;
        }

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1] == p[j-1] or p[j-1]=='?')
                dp[i][j]= dp[i-1][j-1];
                else if(p[j-1] == '*')
                {
                    dp[i][j] = dp[i-1][j] or dp[i][j-1];
                }
                else
                dp[i][j] =false;
            }
        }
        return dp[m][n];

    }
};
