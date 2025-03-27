class Solution {
    // int solve(int i, int j, string& a, string& b) {
    //     if (i < 0 || j < 0)
    //         return 0;
    //     if (a[i] == b[j]) {
    //         return 1 + solve(i - 1, j - 1, a, b);
    //     } else
    //         return max(solve(i - 1, j, a, b), solve(i, j - 1, a, b));
    // }

public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        // int dp[1001][1001];
        vector<int>prev(1+m,0);
        vector<int>curr(1+m,0);
        // memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1]) {
                   curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev=curr;
        }
        return curr[m];
        // return solve(text1.size() - 1, text2.size() - 1, text1, text2);
    }
};