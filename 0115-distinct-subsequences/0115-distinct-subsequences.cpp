class Solution {
    long long dp[1001][1001];
    // int solve(int i, int j, string& s, string& t) {
    //     if (j >= t.size())
    //         return 1;
    //     if (i >= s.size())
    //         return 0;
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     if (s[i] == t[j]) {
    //         int take = solve(i + 1, j + 1, s, t);
    //         int ntake = solve(i + 1, j, s, t);
    //         return dp[i][j] = take + ntake;
    //     } else {
    //         return dp[i][j] = solve(i + 1, j, s, t);
    //     }
    // }

public:
    int numDistinct(string s, string t) {
        memset(dp, 0, sizeof(dp));
        int n = s.size();
        int m = t.size();
        // Base case
        for(int i=0;i<=n;i++){
            dp[i][m]=1;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    long long take = dp[i+1][j+1];
                    long long ntake =dp[i+1][j]; 
                     dp[i][j] = (take + ntake)%((int)1e9+7);
                } else {
                    dp[i][j] =dp[i+1][j] ;
                }
            }
        }
        return dp[0][0];
        // return solve(0, 0, s, t);
    }
};