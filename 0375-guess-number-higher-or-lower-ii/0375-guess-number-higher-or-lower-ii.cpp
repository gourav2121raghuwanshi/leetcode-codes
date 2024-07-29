class Solution {
    int dp[201][201];
    int solve(int s, int e) {
        if (e == s)
            return 0;
        if (s > e)
            return -1e8;
        if (dp[s][e] != -1)
            return dp[s][e];
        int ans = 1e9;

        for (int i = s; i <= e; ++i) {
            ans = min(ans, i + max(solve(s, i - 1), solve(i + 1, e)));
        }
        return dp[s][e] = ans;
    }

public:
    int getMoneyAmount(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(1, n);
    }
};