vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	// Write your code here
	vector<int> lis(n,1) , hash(n);
	int currMax = 1;
	int lastIndex = 0;

        for (int i = 0; i < n; i++) {
			hash[i]=i;
			for (int prev = 0; prev < i; prev++)
			{
				if(arr[prev]<arr[i] and lis[i]<lis[prev]+1)
				{
					lis[i] = lis[prev]+1;
					hash[i]= prev;
				}
			}
			if(lis[i]>currMax)
			{
				currMax = lis[i];
				lastIndex = i;
			}

        }
		vector<int>ans;
		ans.push_back(arr[lastIndex]);
		while(lastIndex != hash[lastIndex])
		{
			lastIndex = hash[lastIndex];
			ans.push_back(arr[lastIndex]);
		}
		reverse(ans.begin(),ans.end());
		return ans;
		
}
