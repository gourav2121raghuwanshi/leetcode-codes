class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int ans = 1;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> last(n, -1);
        vector<int> dp(n, 1);
        int idx = -1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < 1 + dp[j]) {
                        dp[i] = 1 + dp[j];
                        last[i] = j;
                    }
                }
                if (ans < dp[i]) {
                    ans = dp[i];
                    idx = i;
                }
            }
        }
        if (ans == 1)
            return {nums[0]};
        vector<int>v;
        while(ans--){
            v.push_back(nums[idx]);
            idx=last[idx];
        }
        reverse(v.begin(),v.end());
        return v;
    }
};