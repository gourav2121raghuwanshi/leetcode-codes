class Solution {
    // int dp[101][101];
    // int solve(int i, int j) {
    //     if (i == 1 && j == 1)
    //         return 1;
    //     if (i <= 0 || j <= 0)
    //         return 0;

    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     return dp[i][j] = solve(i - 1, j) + solve(i, j - 1);
    // }

public:
    int uniquePaths(int m, int n) {
        // memset(dp, 0, sizeof(dp));
        // dp[1][1]=1;
        vector<int>curr(n+1,0);
        vector<int>prev(n+1,0);
        prev[1]=1;
        curr[1]=1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 1 && j == 1)
                   continue;
                else
                    curr[j] = prev[j] + curr[j - 1];
            }
            prev=curr;
        }

        return prev[n];
        // return dp[m][n];
        // return solve(m,n);
    }
};