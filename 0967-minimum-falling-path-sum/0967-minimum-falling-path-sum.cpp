class Solution {
    int n, m;
    int dp[101][101];
    int solve(int i, int j, vector<vector<int>>& matrix) {
        if (i == n)
            return 0;
        if (j < 0 || j >= m)
            return 1e7;
        int ans = 1e7;
        if (dp[i][j] != 1e8)
            return dp[i][j];
        if (i == 0) {
            for (int k = 0; k < m; ++k) {
                ans =
                    min(ans, matrix[i][k] + min({solve(i + 1, k, matrix),
                                                 solve(i + 1, k + 1, matrix),
                                                 solve(i + 1, k - 1, matrix)}));
            }
        } else {
            return dp[i][j] = matrix[i][j] + min({solve(i + 1, j, matrix),
                                                  solve(i + 1, j + 1, matrix),
                                                  solve(i + 1, j - 1, matrix)});
        }
        return dp[i][j] = ans;
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        for (int i = 0; i < 101; ++i)
            for (int j = 0; j < 101; ++j)
                dp[i][j] = 1e8;

        for (int j = 0; j < m; ++j) {
            dp[n][j] = 0;
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m-1; j >=0; --j) {
                    dp[i][j] =
                        matrix[i][j] +
                        std::min({dp[i + 1][j], dp[i + 1][j + 1],
                                  (j - 1 >= 0 ? dp[i + 1][j - 1] : (int)1e8)});
            }
        }
        int ans = 1e9;
        for (int i = 0; i < m; ++i) {
            ans = min(ans, dp[0][i]);
        }
        return ans;
    }
};