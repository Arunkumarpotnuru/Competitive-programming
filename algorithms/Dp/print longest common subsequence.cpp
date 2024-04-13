// sc = O(m x n)
// tc = O(m x n)
// To print the LCS, we will start from the last cell. We will check if 
// characters at ith index in string1 and the jth index in string2 are equal
// If they are equal, we will append it to our answer variable and then move diagonally upward to i-1 and j-1
// If not equal, we will check which cell has the higher value. Is it the one to the left or the one to the top?
// Accordingly, we will either decrement the value of i or j.
// Why are we comparing or taking the higher value?
// When we were trying to fill the matrix, if the characters were unequal, 
// we take the maximum cell value among its left or top cell value. 

// note : gives error for unknown test case on coding ninjas, 
#include <bits/stdc++.h>
string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			 if(s1[i-1] == s2[j-1])
			 dp[i][j] = 1+dp[i-1][j-1];
			 else
			 dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	 string ans;
	 int i= n;
	 int j= m;

	 while(i>0 or j>0)
	 {
		 if(s1[i-1]==s2[j-1])
		 {
			 ans+= s1[i-1];
			 i--;
			 j--;
		 }
		 else
		 {
			 if(dp[i-1][j] > dp[i][j-1])
			 i--;
			 else
			 j--;
		 }
	 }
	 reverse(ans.begin(),ans.end());
	 return ans;
}
