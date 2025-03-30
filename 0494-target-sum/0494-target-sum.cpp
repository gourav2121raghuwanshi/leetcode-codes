class Solution {
public:
    int mod = 1e9 + 7;

    int findTargetSumWays(vector<int>& nums, int target) {
        // similar to subset difference equal to d (s1-s2==d)
        // s1-s2==target
        // s1=total_sum-s2
        // total_sum- 2*s2 ==target
        // s2 = (total_sum-target)/2
        // now we just have to count number of subsets in nums with sum s2
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum - target) % 2 == 1 || sum - target < 0)
            return 0;
        int s2 = (sum - target) / 2;

        vector<int> curr(s2 + 1, 0);
        vector<int> prev(s2 + 1, 0);
        if (nums[0] == 0)
            prev[0] = 2; // If first element is 0, we can pick or skip it
        else
            prev[0] = 1; // sum=0, at index 0 (we can skip current number as sum
                         // already 0 , num!=0)

        if (nums[0] <= s2 && nums[0] != 0)
            prev[nums[0]] = 1;

        for (int i = 1; i < n; ++i) {
            for (int s = 0; s <= s2; ++s) {
                int take = 0;
                if (nums[i] <= s) {
                    take = prev[s - nums[i]] % mod;
                }
                int nottake = prev[s] % mod;
                curr[s] = (take + nottake) % mod;
            }
            prev=curr;
        }

        return prev[s2];
    }
};
