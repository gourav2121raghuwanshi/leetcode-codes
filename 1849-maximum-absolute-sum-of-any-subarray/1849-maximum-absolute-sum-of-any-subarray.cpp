class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxsum = nums[0];
        int minsum = nums[0];
        int maxs = nums[0];
        int mins = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maxs = max(nums[i], maxs + nums[i]);
            mins = min(nums[i], mins + nums[i]);
            maxsum = max(maxsum, maxs);
            minsum = min(mins, minsum);
        }
        return max(maxsum, abs(minsum));
    }
};