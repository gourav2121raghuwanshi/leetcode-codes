class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        vector<int>curr(amount + 1,0);
        vector<int>prev(amount + 1,0);
        // Base case: There is 1 way to make amount 0 (by choosing no coins)
        for (int i = 0; i <= n; ++i) {
            prev[0] = 1;
        }

        // Fill the DP table
        for (int i = n - 1; i >= 0; --i) {
            for (int amt = 0; amt <= amount; ++amt) {
                long long take = 0, notTake = prev[amt];  // Use long long
                if (amt - coins[i] >= 0) {
                    take = curr[amt - coins[i]];
                }
               curr[amt] = (int)(take + notTake);  // Cast back to int
            }
            prev=curr;
        }

        return prev[amount];
    }
};
