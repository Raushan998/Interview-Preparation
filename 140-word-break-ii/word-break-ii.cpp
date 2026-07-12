class Solution {
public:
    void helper(string s, set<string>&st, int idx, vector<string>&res, vector<string>&result){
        if(idx==s.length()){
            string current="";
            for(int i=0;i<res.size();i++){
                current+=res[i];
                if(i != res.size()-1)current+= " ";
            }
            result.push_back(current);
            return;
        }
        for(int i=idx;i<s.length();i++){
            if(st.find(s.substr(idx, i-idx+1)) != st.end()){
                res.push_back(s.substr(idx, i-idx+1));
                helper(s, st, i+1, res, result);
                res.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(auto &x:wordDict)st.insert(x);
        vector<string>result;
        vector<string>res;
        helper(s, st, 0, res, result);
        return result;
    }
};