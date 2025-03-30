class Solution {
public:
    int mod = 1e9 + 7;
    // int f(vector<int>& arr, int n, int s, vector<vector<int>>& dp) {
    //     if (n == 0) {
    //         if (s == 0 && arr[0] == 0) return 2;
    //         if (s == 0 || s == arr[0]) return 1;
    //         return 0;
    //     }

    //     if (dp[n][s] != -1) return dp[n][s];

    //     // take
    //     int take = 0;
    //     if (arr[n] <= s) {
    //         take = f(arr, n - 1, s - arr[n], dp) % mod;
    //     }

    //     int nottake = f(arr, n - 1, s, dp) % mod;

    //     return dp[n][s] = (take + nottake) % mod;
    // }

    int findTargetSumWays(vector<int>& nums, int target) {
        // similar to subset difference equal to d (s1-s2==d)
        // s1-s2==target
        // s1=total_sum-s2
        // total_sum- 2*s2 ==target
        // s2 = (total_sum-target)/2
        // now we just have to count number of subsets in nums with sum s2
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum - target) % 2 == 1 || sum - target < 0)
            return 0;
        int s2 = (sum - target) / 2;

        vector<vector<int>> dp(n, vector<int>(s2 + 1, 0));
        if (nums[0] == 0)
            dp[0][0] = 2; // If first element is 0, we can pick or skip it
        else
            dp[0][0] = 1; // sum=0, at index 0 (we can skip current number as sum already 0 , num!=0)

        if (nums[0] <= s2 && nums[0] != 0)
            dp[0][nums[0]] = 1;

        for (int i = 1; i < n; ++i) {
            for (int s = 0; s <= s2; ++s) {
                int take = 0;
                if (nums[i] <= s) {
                    take = dp[i - 1][s - nums[i]] % mod;
                }

                int nottake = dp[i - 1][s] % mod;

                dp[i][s] = (take + nottake) % mod;
            }
        }

        return dp[n - 1][s2];
    }
};
