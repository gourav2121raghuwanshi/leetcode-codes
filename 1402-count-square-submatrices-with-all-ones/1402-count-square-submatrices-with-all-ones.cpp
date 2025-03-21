class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int dp[301][301];
        memset(dp, 0, sizeof(dp));
        int n = mat.size();
        int m = mat[0].size();
           int ans = 0;
        for (int i = 0; i < n; i++) {
            if (mat[i][0])
                ans+=dp[i][0] = 1;
        }
        for (int i = 0; i < m; i++) {
            if (mat[0][i])
               ans+= dp[0][i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (mat[i][j] == 0)
                    dp[i][j] = 0;
                else
               ans+=     dp[i][j] =
                        1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }

     
        
        if(dp[0][0]) return ans-1;
        return ans;
    }
};