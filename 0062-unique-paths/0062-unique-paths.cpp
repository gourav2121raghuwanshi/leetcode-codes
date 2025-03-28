class Solution {
    int dp[101][101];
    int solve(int i, int j) {
        if (i == 1 && j == 1)
            return 1;
        if (i <= 0 || j <= 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = solve(i - 1, j) + solve(i, j - 1);
    }

public:
    int uniquePaths(int m, int n) {
        memset(dp, 0, sizeof(dp));
        // dp[1][1]=1;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 1 && j == 1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m][n];
        // return solve(m,n);
    }
};