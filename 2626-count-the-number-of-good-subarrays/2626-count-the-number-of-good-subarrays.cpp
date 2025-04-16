class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0, totalPairs = 0;
        unordered_map<int, int> freq;
        int l = 0;

        for (int r = 0; r < nums.size(); ++r) {
            // Add nums[r] to the window
            totalPairs += freq[nums[r]];
            freq[nums[r]]++;

            // Shrink the window from left while totalPairs >= k
            while (totalPairs >= k) {
                ans += nums.size() - r;  // all subarrays ending at r and starting at l or later are valid
                totalPairs -= freq[nums[l]] - 1;  // removing nums[l]
                freq[nums[l]]--;
                l++;
            }
        }

        return ans;
    }
};
