class Solution {
    int dp[301];
public:
    bool solve(int i, string& s, unordered_set<string>& st) {
        if (i >= s.size()) {
            return true;
        }
        if(dp[i]!=-1) return dp[i];
        string temp = "";
        for (int j = i; j < s.size(); j++) {
            temp.push_back(s[j]);
            if (st.count(temp)) {
                if (solve(j + 1, s, st))
                    return true;
            }
        }
        return dp[i]= false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        unordered_set<string> st;
        for (auto& i : wordDict)
            st.insert(i);
        return solve(0, s, st);
    }
};