class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int miniIdx = -1;
        int maxiIdx = -1;
        int culpritIdx = -1;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == minK)
                miniIdx = i;
            if (nums[i] == maxK)
                maxiIdx = i;
            if (nums[i] < minK || nums[i] > maxK) {
                culpritIdx = i;
                miniIdx = -1;
                maxiIdx = -1;
            }
            if (miniIdx != -1 && maxiIdx != -1) {
                int temp = min(miniIdx, maxiIdx) - culpritIdx;
                ans += (temp > 0) ? temp : 0;
            }
        }
        return ans;
    }
};