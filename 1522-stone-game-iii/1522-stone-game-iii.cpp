class Solution {
public:
    vector<int> dp;
    int n;
    int solve(int i, vector<int>& stone) {
        if (i >= n)
            return 0;
        if (dp[i] != INT_MIN)
            return dp[i];

        int result = -1e9;
        int sum = 0;

        for (int j = i; j <= min(i + 2, n - 1); j++) {
            sum += stone[j];
            result = max(result, sum - solve(j + 1, stone));
        }

        return dp[i] = result;
    }

public:
    string stoneGameIII(vector<int>& stone) {
        n = stone.size();
        dp.resize(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int result = -1e9;
            int sum = 0;
            for (int j = i; j <= min(i + 2, n - 1); j++) {
                sum += stone[j];
                result = max(result, sum - dp[j + 1]);
            }

            dp[i] = result;
        }
        int diff = dp[0];
        if (diff == 0)
            return "Tie";
        return diff > 0 ? "Alice" : "Bob";
    }
};