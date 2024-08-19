class Solution {
    int dp[1001][1001];
    int solve(int c, int lc, int n) {
        if (c == n)
            return 0;
        if (c > n)
            return 1e9;
        if (dp[c][lc] != -1)
            return dp[c][lc];
        int cp = 1e9, ps = 1e9;
        if (lc < c) {
            int a = solve(c, c, n);
            if (a != 1e9)
                cp = 1 + a;
        }
        int b = solve(c + lc, lc, n);
        if (b != 1e9)
            ps = 1 + b;
        return dp[c][lc] = min(cp, ps);
    }

public:
    int minSteps(int n) {
        if (n == 1)
            return 0;
        memset(dp, -1, sizeof(dp));
        return 1 + solve(1, 1, n);
    }
};