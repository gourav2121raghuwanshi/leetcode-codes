class Solution {
    // long long dp[1001][1001];
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
        // memset(dp, 0, sizeof(dp));
        int n = s.size();
        int m = t.size();
        // Base case
        vector<int> curr(m + 1, 0);
        vector<int> prev(m + 1, 0);
        // for(int i=0;i<=n;i++){
        //     dp[i][m]=1;
        // }
        curr[m] = 1;
        prev[m] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    long long take = prev[j + 1];
                    long long ntake = prev[j];
                    curr[j] = (take + ntake) % ((int)1e9 + 7);
                } else {
                    curr[j] = prev[j];
                }
            }
            prev=curr;
        }
        return curr[0];
        // return solve(0, 0, s, t);
    }
};