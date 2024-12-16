class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[302][302];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (matrix[i - 1][j - 1] == '1')
                    dp[i][j] =
                        1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                else
                    dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
};