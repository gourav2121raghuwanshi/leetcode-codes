class Solution {
public:
    int solve(int i, bool buy, int fee, vector<int>& prices) {
        if (i >= prices.size())
            return 0;

        if (buy) {
            return max(-prices[i] + solve(i + 1, 0, fee, prices),
                       solve(i + 1, 1, fee, prices));
            // return buuy;
        } else {
            return max(solve(i + 1, 0, fee, prices),
                       +prices[i] - fee + solve(i + 1, 1, fee, prices));
            // return nbuy;
        }
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        // return solve(0,1,fee,prices);
        int n = prices.size();
        int dp[50001][2];
        memset(dp, 0, sizeof(dp));
        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 0; buy <= 1; ++buy) {
                if (buy) {
                    dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                } else {
                    dp[i][buy] =
                        max(dp[i + 1][0], -fee + prices[i] + dp[i + 1][1]);
                }
            }
        }
        return dp[0][1];
    }
};