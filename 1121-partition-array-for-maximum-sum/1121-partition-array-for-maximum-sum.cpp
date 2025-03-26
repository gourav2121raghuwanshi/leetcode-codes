class Solution {
    int dp[501];
    // int solve(int i, vector<int>& arr, int k) {
    //     if (i >= arr.size())
    //         return 0;
    //     if (dp[i] != -1)
    //         return dp[i];
    //     int ans = 0;
    //     int currmax = 0;
    //     for (int j = i; j < min(i + k, (int)arr.size()); ++j) {
    //         currmax = max(currmax, arr[j]);
    //         ans = max(ans, currmax * (j - i + 1) + solve(j + 1, arr, k));
    //     }
    //     return dp[i] = ans;
    // }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, 0, sizeof(dp));
        for (int i = arr.size()-1; i >= 0; --i) {
            int ans = 0;
            int currmax = 0;
            for (int j = i; j < min(i + k, (int)arr.size()); ++j) {
                currmax = max(currmax, arr[j]);
                ans = max(ans, currmax * (j - i + 1) + dp[j+1]);
            }
            dp[i] = ans;
        }

        return dp[0];
        // return solve(0, arr, k);
    }
};