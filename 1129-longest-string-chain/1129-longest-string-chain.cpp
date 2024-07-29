class Solution {
    bool isPossible(const string& a, const string& b) {
        if (a.size() + 1 != b.size())
            return false;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j])
                ++i;
            ++j;
        }
        return i == a.size();
    }

public:
    int longestStrChain(vector<string>& words) {
        auto comp = [](const string& a, const string& b) {
            return a.size() < b.size();
        };
        sort(words.begin(), words.end(), comp);
        int n = words.size();
        vector<int> dp(n + 1, 1);
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (words[i].size() ==
                      words[j].size() + 1 && isPossible(words[j], words[i])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
