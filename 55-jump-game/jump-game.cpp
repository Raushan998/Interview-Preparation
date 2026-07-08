class Solution {
private:
   vector<int>dp;
public:
    bool helper(vector<int>&arr, int idx){
        int n=arr.size();
        if(idx>=n-1)return true;
        if(arr[idx]==0)return false;
        if(dp[idx] != -1)return dp[idx];
        int max_reach = min(n-1, idx+arr[idx]);
        for(int i=idx+1;i<=max_reach;i++){
            if(helper(arr, i)){
                dp[i]=1;
                return true;
            }
        }
        dp[idx]=0;
        return false;
    }
    bool canJump(vector<int>& nums) {
        dp=vector<int>(nums.size(), -1);
        return helper(nums, 0);
    }
};