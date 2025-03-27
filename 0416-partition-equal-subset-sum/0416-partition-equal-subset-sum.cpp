class Solution {
    // int dp[201][10001];
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
        // memset(dp, 0, sizeof(dp));
        int Totalsum = accumulate(nums.begin(), nums.end(), 0);
        if (Totalsum & 1)
            return false;
        vector<int>curr(Totalsum/2+1,0);
        vector<int>prev(Totalsum/2+1,0);
        for (int i = 0; i < 201; i++) {
            prev[0] = true;
        }
        int n = nums.size();
        for (int i = n - 1; i >= 0; --i) {
            for (int sum = 0; sum <= Totalsum / 2; ++sum) {
                curr[sum] =
                    prev[sum] ||
                    (sum - nums[i] >= 0 ? prev[sum - nums[i]] : false);
                //  solve(i + 1, nums, sum - nums[i]) || solve(i + 1, nums,sum);
            }
            prev=curr;
        }

        return prev[Totalsum / 2];
        // return solve(0, nums, sum / 2);
    }
};