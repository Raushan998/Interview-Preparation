class Solution {
private:
    vector<int> dp = vector<int>(50, -1);
public:
    int climbStairs(int n) {
        if(n==0 || n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        dp[n]=climbStairs(n-1) + climbStairs(n-2);
        return dp[n];
    }
};