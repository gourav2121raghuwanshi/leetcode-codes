class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = 0;
        long long cs = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            cs += nums[i];
            if (cs >= sum - cs)
                ++ans;
        }
        return ans;
    }
};