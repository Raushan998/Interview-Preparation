class Solution {
private:
   vector<vector<int>>dp;
public:
    int helper(vector<int>&nums, int prevIdx, int idx){
        if(idx>=nums.size())return 0;
        if(dp[prevIdx+1][idx] != -1)return dp[prevIdx+1][idx];
        int value = prevIdx==-1?INT_MIN:nums[prevIdx];
        if(nums[idx]>value)
            return dp[prevIdx+1][idx] = max(helper(nums, prevIdx, idx+1), 
                                    1+helper(nums, idx, idx+1));
        return dp[prevIdx+1][idx] = helper(nums, prevIdx, idx+1);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp = vector<vector<int>>(n, vector<int>(n + 1, -1));
        return helper(nums,-1,0);
    }
};
/*
[10,9,2,5,3,7,101,18]


*/