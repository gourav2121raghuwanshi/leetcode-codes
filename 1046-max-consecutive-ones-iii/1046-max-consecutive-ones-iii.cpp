class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int flipc = 0;
        int s = 0;
        int c = 0;
        for (int e = 0; e < nums.size(); ++e) {
            if (nums[e]==0) {
                ++flipc;
            }
            while (flipc > k) {
                if (nums[s]==0) {
                    --flipc;
                }
                ++s;
            }

            ans = max(ans, e - s + 1);
        }
        return ans;
    }
};