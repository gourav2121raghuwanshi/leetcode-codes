class Solution {
public:
    int solve(int i, bool buy, vector<int>& prices) {
        if (i >= prices.size())
            return 0;

        if (buy) {
            return max(-prices[i] + solve(i + 1, 0, prices),
                       solve(i + 1, 1, prices));
            // return buuy;
        } else {
            return max(solve(i + 1, 0, prices),
                       +prices[i] + solve(i + 2, 1, prices));
            // return nbuy;
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        // return solve(0,1,prices);
        int n = prices.size();
        int dp[5002][2];
        memset(dp, 0, sizeof(dp));
        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 0; buy <= 1; ++buy) {
                if (buy) {
                    dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                    // return buuy;
                } else {
                    dp[i][buy] = max(dp[i + 1][0], +prices[i] + dp[i + 2][1]);
                    // return nbuy;
                }
            }
        }
        return dp[0][1];
    }
};