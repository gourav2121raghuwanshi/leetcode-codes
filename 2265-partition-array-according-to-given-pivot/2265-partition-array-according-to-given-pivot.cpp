class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int i = 0;
        int n = nums.size();
        vector<int> ans(n);
        int idx = 0;
        int same = 0;
        int low = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < pivot)
                ++low;
            else if (nums[i] == pivot)
                ++same;
        }
        int high = same + low;
        same = low;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == pivot)
                ans[same++] = nums[i];
            else if (nums[i] > pivot)
                ans[high++] = nums[i];
            else
                ans[idx++] = nums[i];
        }

        return ans;
    }
};