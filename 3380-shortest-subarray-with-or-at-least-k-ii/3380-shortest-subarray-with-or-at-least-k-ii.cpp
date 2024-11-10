
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        int left = 0;
        vector<int> bit(32, 0);
        int val = 0;

        for (int right = 0; right < n; ++right) {
            for (int j = 0; j < 32; ++j) {
                if ((nums[right] >> j) & 1) {
                    if (bit[j] == 0) {
                        val |= (1 << j);
                    }
                    ++bit[j];
                }
            }

            while (val >= k && left <= right) {
                val = 0;
                ans = min(ans, right - left + 1);

                for (int j = 0; j < 32; ++j) {
                    if (((1 << j) & nums[left])) {
                        --bit[j];
                    }
                    if (bit[j] > 0) {
                        val |= (1 << j);
                    }
                }
                ++left;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
