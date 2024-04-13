// recursive code
// tc = O(2^m x 2^n)
int fun(int i,int j,string &s,string &t)
{
  	if(i<0 or j<0) return 0;
  	if(s[i]== t[j])
  	{
  		 return 1+ fun(i-1,j-1,s,t);
  	}
  	else
  	{
  		int a = fun(i-1,j,s,t);
  		int b = fun(i,j-1,s,t);
  		return max(a,b);
  	}
  }
  int lcs(string s, string t)
  {
  	//Write your code here
  	return fun(s.size()-1,t.size()-1,s,t);

}

// memoization
// tc =O( m x n)
// sc = O(m x n) + O(m+n) auxiliary stack space
#include <bits/stdc++.h>
int fun(int i,int j,string &s,string &t,vector<vector<int>>&dp)
{
  	if(i<0 or j<0) return 0;
  	if(dp[i][j]!= -1) return dp[i][j];
  	if(s[i]== t[j])
  	{
  		 return dp[i][j] = 1+ fun(i-1,j-1,s,t,dp);
  	}
  	else
  	{
  		int a = fun(i-1,j,s,t,dp);
  		int b = fun(i,j-1,s,t,dp);
  		return dp[i][j] = max(a,b);
  	}
  }
  int lcs(string s, string t)
  {
  	//Write your code here
  	int m = s.size() , n = t.size();
  	vector<vector<int>>dp(m,vector<int>(n,-1));
  	return fun(m-1,n-1,s,t,dp);

}

// tabulation 
// tc = O(m x n)
// sc = O(m x n)

#include <bits/stdc++.h>

int lcs(string s, string t)
{
  	 int m = s.size();
  	 int n = t.size();
  
  	vector<vector<int>>dp(m+1,vector<int>(n+1,0));
  	for(int i=1;i<=m;i++)
  	{
  		for(int j=1;j<=n;j++)
  		{
  			 if(s[i-1]==t[j-1])
  			 {
  				 dp[i][j]= 1+dp[i-1][j-1];
  			 }
  			 else
  			 {
  				 dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
  			 }
  		}
  	}
  	return dp[m][n];
}

// space optimization
// tc = O(m x n)
// sc = O( n)

#include <bits/stdc++.h>

int lcs(string s, string t)
{
  	 int m = s.size();
  	 int n = t.size();
  
  	vector<int> curr(n+1,0) , prev(n+1,0);
  	for(int i=1;i<=m;i++)
  	{
  		for(int j=1;j<=n;j++)
  		{
  			 if(s[i-1]==t[j-1])
  			 {
  				 curr[j]= 1+prev[j-1];
  			 }
  			 else
  			 {
  				 curr[j] = max(prev[j],curr[j-1]);
  			 }
  		}
  		prev = curr;
  	}
  	return prev[n];
}

