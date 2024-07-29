class Solution {
    /*
    in count, store number of ways to reach that count (this shows number of
    subsequences can be formed).
    */
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j] && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    count[i] = count[j];
                } else if (nums[i] > nums[j] && dp[i] == dp[j] + 1)
                    count[i] += count[j];
            }
            maxi = max(maxi, dp[i]);
        }
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (maxi == dp[i])
                c += count[i];
        }
        return c;
    }
};