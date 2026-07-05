class Solution {
public:
    unordered_map<int, bool>dp;
    bool helper(string s, set<string>& wordDict, int idx){
        if(idx>=s.length())return true;
        if(dp.count(idx) > 0)return dp[idx];
        bool ans=false;
        for(int i=idx;i<s.length();i++){
            if(wordDict.find(s.substr(idx, i-idx+1)) != wordDict.end())
               ans = ans || helper(s, wordDict, i+1);
        }
        dp[idx]=ans;
        return ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(auto &x:wordDict)
           st.insert(x);
        return helper(s, st, 0);
    }
};