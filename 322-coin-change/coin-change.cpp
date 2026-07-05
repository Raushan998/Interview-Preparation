class Solution {
private:
    vector<vector<int>> dp;
public:
    int helper(vector<int>& coins, int amount, int idx){
        if(amount == 0) return 0;
        if(amount < 0 || idx >= (int)coins.size()) return INT_MAX/2;
        if(dp[idx][amount] != -1) return dp[idx][amount];
        dp[idx][amount] = min(
                            1 + helper(coins, amount-coins[idx], idx), 
                            helper(coins, amount, idx+1));
        return dp[idx][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        dp = vector<vector<int>>(coins.size(), vector<int>(amount+1, -1));
        int ans = helper(coins, amount, 0);
        if(ans >= INT_MAX/2) return -1;
        return ans;
    }
};