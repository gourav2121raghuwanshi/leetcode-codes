class Solution {
    int n, m;
    // int dp[101][101];
    // int solve(int i, int j, vector<vector<int>>& obstacleGrid) {
    //     if (i >= n || j >= m)
    //         return 0;
    //     if (obstacleGrid[i][j] == 1)
    //         return 0;
    //     if (i == n - 1 && j == m - 1)
    //         return 1;
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     return dp[i][j] = solve(i + 1, j, obstacleGrid) +
    //                       solve(i, j + 1, obstacleGrid);
    // }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        if (obstacleGrid[n - 1][m - 1] == 1 || obstacleGrid[0][0] == 1)
            return 0;
        // memset(dp, 0, sizeof(dp));
        // dp[n - 1][m - 1] = 1;
        vector<int> curr(m + 1, 0);
        vector<int> prev(m + 1, 0);
        curr[m - 1] = prev[m - 1] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (i == n - 1 && j == m - 1)
                    continue;
                if (obstacleGrid[i][j] == 1)
                    curr[j] = 0;
                else
                    curr[j] = (prev[j]*1LL +1LL* curr[j + 1])%(2*(int)1e9+1);
            }
            prev=curr;
        }
        return prev[0];
        // return solve(0,0,obstacleGrid);
    }
};