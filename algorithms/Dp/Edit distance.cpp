// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

//recursive code
// fun(i,j) = min operations to convert s1[0-i] to s2[0-j]

class Solution {
  public:
    int fun(int i,int j,string &s,string &t)
    {
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(s[i] == t[j])
        {
            return fun(i-1,j-1,s,t);
        }
        int insert = 1+fun(i,j-1,s,t);
        int del  = 1+ fun(i-1,j,s,t);
        int replace = 1+ fun(i-1,j-1,s,t);
        
        return min(insert,min(del,replace));
    }
    int editDistance(string s, string t) {
        // Code here
        int m = s.size();
        int n = t.size();
        
        return fun(m-1,n-1,s,t);
    }
};

// memoization
// tc = O( m x n) 
// sc = O(m x n) + auxiliary stack space
class Solution {
  public:
    int fun(int i,int j,string &s,string &t,vector<vector<int>>&dp)
    {
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j])
        {
            return dp[i][j] = fun(i-1,j-1,s,t,dp);
        }
        int insert = 1+fun(i,j-1,s,t,dp);
        int del  = 1+ fun(i-1,j,s,t,dp);
        int replace = 1+ fun(i-1,j-1,s,t,dp);
        
        return dp[i][j] = min(insert,min(del,replace));
    }
    int editDistance(string s, string t) {
        // Code here
        int m = s.size();
        int n = t.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(m-1,n-1,s,t,dp);
    }
};

//tabulation
//sc = O(m x n)
//tc = O(m x n)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(),n= word2.length();
        int arr[m+1][n+1];

        for(int i=0;i<=m;i++)
        arr[i][0]=i;
        for(int i=0;i<=n;i++)
        arr[0][i]=i;

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1])
                arr[i][j]= arr[i-1][j-1];
                else
                {
                    int a= arr[i-1][j];
                    int b= arr[i][j-1];
                    int c= arr[i-1][j-1];

                    arr[i][j]= 1+ min(a,min(b,c));
                }
            }
        }
        return arr[m][n];

    }
};
