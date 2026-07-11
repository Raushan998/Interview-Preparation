class Solution {
private:
   vector<vector<int>>dp;
public:
    bool helper(vector<int>&nums, int idx, int sum){
        if(sum==0)return true;
        if(sum<0 || idx>=nums.size())return false;
        if(dp[idx][sum] != -1)return dp[idx][sum];
        return dp[idx][sum]= helper(nums, idx+1, sum-nums[idx]) 
                                || helper(nums, idx+1, sum);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto &x:nums)sum+=x;
        if(sum&1)return false;
        dp=vector<vector<int>>(nums.size(), vector<int>(sum+1, -1));
        return helper(nums, 0, sum/2);
    }
};