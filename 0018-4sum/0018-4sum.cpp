class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1;
                int r = n - 1;
                while (l < r) {
                    long long cs = 1LL * nums[i] + 1LL * nums[j] +
                                   1LL * nums[l] + 1LL * nums[r];
                    if (cs == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1])
                            ++l;
                        while (l < r && nums[r] == nums[r - 1])
                            --r;
                        ++l, --r;
                    } else if (cs > target) {
                        --r;
                    } else
                        ++l;
                }
            }
        }
        return ans;
    }
};