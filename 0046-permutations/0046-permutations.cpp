class Solution {
    void solve(int i, int e, vector<int>& nums, vector<vector<int>>& ans) {
        {
            if (i == e) {
                ans.push_back(nums);
                return;
            }
        }
        for (int j = i; j <= e; ++j) {
            swap(nums[i], nums[j]);
            solve(i + 1, e, nums, ans);
            swap(nums[i], nums[j]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums.size() - 1, nums, ans);
        return ans;
    }
};