class Solution {
private:
   vector<int>dp;
   int helper(vector<int>&arr, int idx){
        int n=arr.size();
        if(idx>=n-1)return 0;
        if(arr[idx]==0)return INT_MAX/2;
        if(dp[idx] != (INT_MAX/2))return dp[idx];
        int max_reach = min(n-1, idx+arr[idx]);
        int ans = INT_MAX;
        for(int i=idx+1;i<=max_reach;i++){
            ans=min(ans, 1+helper(arr, i));
        }
        return dp[idx] = ans;
   }
public:
    int jump(vector<int>& nums) {
        dp=vector<int>(nums.size(), INT_MAX/2);
        return helper(nums, 0);
    }
};

/*
  [2,3,1,1,4]

*/