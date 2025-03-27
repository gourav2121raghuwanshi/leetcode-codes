class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            if (a.size() != b.size())
                return a.size() < b.size();
            return a <= b;
        });
        for (auto& i : words)
            cout << i << " ";
        cout << endl;
        int n = words.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (words[i].size() - words[j].size() == 1) {
                    string a = words[j];
                    string b = words[i];
                    int cnt = 0;
                    int l = 0;
                    int r = 0;
                    while (l < a.size() && r < b.size()) {
                        if (a[l] == b[r])
                            ++l, ++r;
                        else
                            ++cnt, ++r;
                    }
                    if (cnt <= 1 && l == a.size()) {
                        dp[i] = max(dp[i], 1 + dp[j]);
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};