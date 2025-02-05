class Solution {
unordered_map<string,int>dp;
public:
    int longestDecomposition(string text) {
        int n = text.size();
        if(n==0) return 0;
        if(dp.count(text)) return dp[text];
        int ans = 1;
        string a, b;
        int j = n - 1;
        for (int i = 0; i < n / 2; i++) {
            a.push_back(text[i]);
            b.push_back(text[j--]);
            string c = b;
            reverse(c.begin(), c.end());
            if (c == a) {
                // cout << a << endl;
                int len = j - i;
                string next = text.substr(i + 1, len);
                // cout << "nxt " << next << endl;
                ans = max(ans, 2 + longestDecomposition(next));
            }
        }

        return dp[text] = ans;
    }
};