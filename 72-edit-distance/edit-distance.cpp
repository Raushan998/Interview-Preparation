class Solution {
private:
    vector<vector<int>>dp;
public:
    int helper(string word1, string word2, int i, int j){
        if(j==word2.length())
            return word1.length()-i;
        if(i==word1.length())
            return word2.length()-j;
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i] == word2[j])
            return dp[i][j] = helper(word1, word2, i+1, j+1);
        return dp[i][j] = 1 + min(
            helper(word1, word2, i+1, j+1),
            min(
                helper(word1, word2, i+1, j),
                helper(word1, word2, i, j+1)
            )
        );
    }
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        dp = vector<vector<int>>(m+1, vector<int>(n+1, 0));

        for(int i = 0; i <= m; i++) dp[i][0] = i;
        for(int j = 0; j <= n; j++) dp[0][j] = j;

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(
                        dp[i-1][j-1],
                        min(dp[i-1][j], dp[i][j-1])
                    );
                }
            }
        }
        return dp[m][n];
    }
};