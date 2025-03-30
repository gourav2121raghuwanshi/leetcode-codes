class Solution {
    // int dp[13][10001];
  

public:
    int coinChange(vector<int>& coins, int amountt) {


        int n = coins.size();
        vector<int>curr(amountt+1,1e7);
        vector<int>prev(amountt+1,1e7);
        // for (int i = 0; i <= n; ++i) {
        //     for (int j = 0; j <= amountt; ++j) {
        //         dp[i][j] = 1e7;
        //     }
        // }

        // for (int i = 0; i <= n; ++i) {
        //     dp[i][0] = 0;
        // }
        prev[0]=curr[0]=0;
        for (int i = n - 1; i >= 0; --i) {
            for (int amount = 0; amount <= amountt; ++amount) {
                int take = 1e7;
                if (amount - coins[i] >= 0)
                    take = 1 + curr[amount - coins[i]];
                int ntake = prev[amount];
                curr[amount] = min(take, ntake);
            }
            prev=curr;
        }

        return curr[amountt] == 1e7 ? -1 : curr[amountt];
  }
};