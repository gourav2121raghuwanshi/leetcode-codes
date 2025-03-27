class Solution {
    int dp[201][10001];
    // bool solve(int i, vector<int>& nums, int sum) {
    //     if (sum == 0)
    //         return true;
    //     if (i >= nums.size() || sum < 0)
    //         return false;
    //     if (dp[i][sum] != -1)
    //         return dp[i][sum];
    //     return dp[i][sum] =
    //                solve(i + 1, nums, sum - nums[i]) || solve(i + 1, nums, sum);
    // }

public:
    bool canPartition(vector<int>& nums) {
        memset(dp, 0, sizeof(dp));
        int Totalsum = accumulate(nums.begin(), nums.end(), 0);
        if (Totalsum & 1)
            return false;
        for (int i = 0; i < 201; i++) {
            dp[i][0] = true;
        }
        int n = nums.size();
        for (int i = n - 1; i >= 0; --i) {
            for (int sum = 0; sum <= Totalsum / 2; ++sum) {
                dp[i][sum] =
                    dp[i + 1][sum] ||
                    (sum - nums[i] >= 0 ? dp[i + 1][sum - nums[i]] : false);
                //  solve(i + 1, nums, sum - nums[i]) || solve(i + 1, nums,sum);
            }
        }

        return dp[0][Totalsum / 2];
        // return solve(0, nums, sum / 2);
    }
};