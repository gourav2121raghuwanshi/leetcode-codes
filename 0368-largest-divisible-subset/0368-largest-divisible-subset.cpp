class Solution {
 
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // LIS code with lastIndex logic
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        vector<int> dp(n, 1);
        vector<int> prevIdx(n, -1);
        int maxlen = 1;
        int lastIdx = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < 1 + dp[j]) {
                        dp[i] = 1 + dp[j];
                        prevIdx[i] = j;
                    }
                }
            }
            if (maxlen < dp[i]) {
                maxlen = dp[i];
                lastIdx = i;
            }
        }
        while (maxlen--) {
            ans.push_back(nums[lastIdx]);
            lastIdx = prevIdx[lastIdx];
        }
        return ans;
    }
};