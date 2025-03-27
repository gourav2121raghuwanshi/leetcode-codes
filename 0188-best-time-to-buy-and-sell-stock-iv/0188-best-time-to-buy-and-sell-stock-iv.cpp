class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
        int dp[100001][2][k+1];
        memset(dp, 0, sizeof(dp));
        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 0; buy <= 1; ++buy) {
                for (int trxn = 1; trxn <= k; ++trxn) {
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
        return dp[0][1][k];
    }
};