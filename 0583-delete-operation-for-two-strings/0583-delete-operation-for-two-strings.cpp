class Solution {
    int dp[501][501];
    // int solve(int i, int j, string& a, string& b) {
    //     if (i >= a.size() && j >= b.size())
    //         return 0;
    //     if (i >= a.size())
    //         return b.size() - j;
    //     if (j >= b.size())
    //         return a.size() - i;
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     if (a[i] == b[j]) {
    //         return dp[i][j] = solve(i + 1, j + 1, a, b);
    //     } else {
    //         return dp[i][j] =
    //                    1 + min(solve(i + 1, j, a, b), solve(i, j + 1, a, b));
    //     }
    // }

public:
    int minDistance(string a, string b) {
        memset(dp, 0, sizeof(dp));
        int n = a.size();
        int m = b.size();
        vector<int>curr(m+1,0);
        vector<int>prev(m+1,0);
        // for(int i=0;i<=n;++i){
        //     dp[i][m]=n-i;
        // }
        for(int j=0;j<=m;++j){
            prev[j]=m-j;
        }
        for (int i = n - 1; i >= 0; --i) {
            curr[m]=n-i;
            for (int j = m - 1; j >= 0; --j) {
                if (a[i] == b[j]) {
                    curr[j] = prev[j + 1];
                    //  solve(i+1,j+1,a,b);
                } else {
                    curr[j] = 1 + min(prev[j], curr[j + 1]);
                }
            }
            prev=curr;
        }
        return curr[0];
        //   return solve(0,0,word1,word2) ;
    }
};