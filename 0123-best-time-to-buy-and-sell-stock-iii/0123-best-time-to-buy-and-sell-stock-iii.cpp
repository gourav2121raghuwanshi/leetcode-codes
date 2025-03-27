class Solution {
    // int solve(int i, bool buy, int trxn, vector<int>& prices) {
    //     if (i >= prices.size())
    //         return 0;
    //     if (buy) {
    //         return max(-prices[i] + solve(i + 1, 0, trxn, prices),
    //                    solve(i + 1, 1, trxn, prices));
    //     } else if (trxn) {
    //         return max(solve(i + 1, 0, trxn, prices),
    //                    +prices[i] + solve(i + 1, 1, trxn - 1, prices));
    //     }
    //     return 0;
    // }

public:
    int maxProfit(vector<int>& prices) {
        // return solve(0, 1, 2, prices);
        int n = prices.size();
        int dp[100001][2][3];
        memset(dp, 0, sizeof(dp));
        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 0; buy <= 1; ++buy) {
                for (int trxn = 1; trxn <= 2; ++trxn) {
                    if (buy) {
                        dp[i][buy][trxn] = max(-prices[i] + dp[i + 1][0][trxn],
                                               dp[i + 1][1][trxn]);

                    } else {
                        dp[i][buy][trxn] =
                            max(dp[i + 1][0][trxn],
                                +prices[i] + dp[i + 1][1][trxn - 1]);
                        // return nbuy;
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};