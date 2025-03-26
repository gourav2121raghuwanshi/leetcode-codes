class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
          int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = matrix[i][0];
            ans+=dp[i][0];
        }
        for (int j = 0; j < m; ++j) {

            dp[0][j] = matrix[0][j];
            ans+=dp[0][j];
        } 
        if(dp[0][0]) --ans;

      
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j]) {
                    dp[i][j] =
                        1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                    ans += dp[i][j];
                }
            }
        }
        //  for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < m; ++j) {
        //             ans += dp[i][j];
                
        //     }
        // }
        return ans;
    }
};