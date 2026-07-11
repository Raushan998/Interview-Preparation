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
        dp=vector<vector<int>>(word1.length(), vector<int>(word2.length(), -1));
        return helper(word1, word2, 0, 0);
    }
};