class Solution {
    double dp[101][101];
    double solve(int i, vector<int>& nums, int k) {
        if (i >= nums.size() || k < 0)
            return 0;
        if(k==0) return INT_MIN;
        if (dp[i][k] != 0)
            return dp[i][k];
        double ans = 0;
        double sum = 0;
        for (int curr = i; curr < nums.size(); curr++) {
            double len = curr - i + 1;
            sum += nums[curr];
            // if (k - 1 >= 0)
                ans = max(ans, sum / len + solve(curr + 1, nums, k - 1));
        }
        return dp[i][k] = ans;
    }
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        memset(dp, 0, sizeof(dp));
        return solve(0, nums, k);
    }
};