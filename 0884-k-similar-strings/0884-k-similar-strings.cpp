class Solution {
    string getKey(string& a, int i) {
        string ans = a;
        ans += ":" + to_string(i);
        return ans;
    }
    unordered_map<string, int> dp;
    int solve(int i, string& s1, string& s2) {
        if (i >= s1.size())
            return 0;
        string key = getKey(s1, i);
        if (dp.count(key))
            return dp[key];
        if (s1[i] == s2[i]) {
            return dp[key] = solve(i + 1, s1, s2);
        } else {
            int ans = 1e9;
            for (int j = i + 1; j < s1.size(); ++j) {
                if (s1[j] == s2[i]) {
                    swap(s1[j], s1[i]);
                    ans = min(ans, 1 + solve(i + 1, s1, s2));
                    swap(s1[j], s1[i]);
                }
            }
            return dp[key] = ans;
        }
    }

public:
    int kSimilarity(string s1, string s2) { return solve(0, s1, s2); }
};