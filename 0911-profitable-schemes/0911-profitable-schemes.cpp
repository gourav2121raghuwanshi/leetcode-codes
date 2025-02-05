class Solution {
    int dp[101][101][101];
    const int mod=1e9+7;

    int solve(int i, int reqProf, int n, vector<int>& group,
              vector<int>& profit) {
        if (i == group.size()) {
            return reqProf <= 0;
        }
        if (dp[i][reqProf][n] != -1)
            return dp[i][reqProf][n];
        int ntake = solve(i + 1, reqProf, n, group, profit);
        int take = 0;
        if (n >= group[i]) {
            take = solve(i + 1, max(0, reqProf - profit[i]), n - group[i],
                         group, profit);
        }
        return dp[i][reqProf][n] = (take%mod + ntake%mod)%mod;
    }

public:
    int profitableSchemes(int n, int minProfit, vector<int>& group,
                          vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return solve(0, minProfit, n, group, profit);
    }
};