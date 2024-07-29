class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int minsum = nums[0];
        int maxi = nums[0];
        int maxsum = nums[0];
        int mini = nums[0];
        int ts = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maxi = max(nums[i], maxi + nums[i]);
            mini = min(nums[i], mini + nums[i]);
            maxsum = max(maxi, maxsum);
            minsum = min(mini, minsum);
            ts += nums[i];
        }
        int cs = ts - minsum;
        if (maxsum > 0)
            return max(maxsum, cs);
        return maxsum;
    }
};