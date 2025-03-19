class Solution {
public:
    int minOperations(vector<int>& nums) {
        int switchCount = 0;
        int n = nums.size();
        for (int i = 0; i <= n - 3; ++i) {
             if (nums[i] == 0) {
                ++switchCount;
                nums[i + 1] = 1 - nums[i + 1];
                nums[i + 2] = 1 - nums[i + 2];
            }
        }

        // check for last 2 elements
        // as we dont have sufficient elements now to make a swithc
        for (int i = n - 3 + 1; i < n; ++i) {
            if (nums[i] == 0) {
                return -1;
            }
        }
        return switchCount;
    }
};