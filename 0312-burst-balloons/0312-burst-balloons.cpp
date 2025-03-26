class Solution {
    int dp[303][303];

public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        for (int s = n - 1; s >= 1; --s) {
            for (int e = 0; e <= n - 2; ++e) {
                if (s > e) {
                    dp[s][e] = 0;
                    continue;
                }
                int ans = 0;
                for (int i = s; i <= e; ++i) {
                    dp[s][e] =
                        max(dp[s][e], nums[s - 1] * nums[i] * nums[e + 1] +
                                          dp[s][i - 1] + dp[i + 1][e]);
                }
            }
        }
        return dp[1][nums.size() - 2];
    }
};