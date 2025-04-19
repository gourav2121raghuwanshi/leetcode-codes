class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // We are looking for j > i, so we start from i + 1
            int l = i + 1;
            int h = n - 1;
            
            // Find the smallest j such that nums[i] + nums[j] >= lower
int low_idx = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            // Find the largest j such that nums[i] + nums[j] <= upper
            int high_idx = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin() - 1;
            
            if (low_idx <= high_idx) {
                ans += (high_idx - low_idx + 1);
            }
        }
        return ans;
    }
};
