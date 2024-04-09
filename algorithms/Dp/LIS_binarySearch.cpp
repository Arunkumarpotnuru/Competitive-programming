// Tc - O(nlogn)
// sc - O(n)
// please note that arr won't store LIS , it's size will be equal of length of LIS.

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>arr;
        arr.push_back(nums[0]);

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>arr.back())
            arr.push_back(nums[i]);
            else
            {
                int ind = lower_bound(arr.begin(),arr.end(),nums[i])-arr.begin();
                arr[ind] = nums[i];
            }
        }
        return arr.size();
    }
};
