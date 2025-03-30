class Solution {
    int dp[13][10001];
    // int solve(vector<int>& coins, int amount, int i) {
    //     if (amount == 0)
    //         return 0;
    //     if (i >= coins.size() || amount < 0)
    //         return 1e7;
    //     if (dp[i][amount] != -1)
    //         return dp[i][amount];
    //     return dp[i][amount] = min(solve(coins, amount, i + 1),
    //                                1 + solve(coins, amount - coins[i], i));
    // }

public:
    int coinChange(vector<int>& coins, int amountt) {

        int n = coins.size();
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= amountt; ++j) {
                dp[i][j] = 1e7;
            }
        }

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int amount = 0; amount <= amountt; ++amount) {
                int take = 1e7;
                if (amount - coins[i] >= 0)
                    take = 1 + dp[i][amount - coins[i]];
                int ntake = dp[i + 1][amount];
                dp[i][amount] = min(take, ntake);
            }
        }

        return dp[0][amountt] == 1e7 ? -1 : dp[0][amountt];
        // int ans = solve(coins, amount, 0);
        // return ans == 1e7 ? -1 : ans;
    }
};