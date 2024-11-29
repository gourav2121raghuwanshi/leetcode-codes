class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int sum = 1e9;
        int n = nums.size();
        for (int i = 0; i <n ; i++) {
            int sm = 0;
            for (int j = i; j < i + r && j<n; j++) {
                sm += nums[j];
                if (j - i + 1 >= l && j - i + 1 <= r) {
                    if (sm > 0) {
                        sum = min(sum, sm);
                    }
                }
            }
        }

        return sum == 1e9 ? -1 : sum;
    }
};