class Solution {
    int dp[201][10001];
    bool solve(int i, vector<int>& nums, int sum) {
        if (sum == 0)
            return true;
        if (i >= nums.size() || sum < 0)
            return false;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        return dp[i][sum] =
                   solve(i + 1, nums, sum - nums[i]) || solve(i + 1, nums, sum);
    }

public:
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return false;
        return solve(0, nums, sum / 2);
    }
};