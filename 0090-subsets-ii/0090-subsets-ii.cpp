class Solution {
    void solve(int i, vector<int>& nums, vector<int>& v,
               vector<vector<int>>& ans) {
        ans.push_back(v);
        for (int j = i; j < nums.size(); ++j) {
            if (j != i && nums[j] == nums[j - 1])
                continue;
            v.push_back(nums[j]);
            solve(j + 1, nums, v, ans);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> v;
        solve(0, nums, v, ans);
        return ans;
    }
};