class Solution {
    vector<vector<int>> ans;
    void solve(int i, vector<int>& nums, vector<int>& v) {
        ans.push_back(v);
        for (int j = i; j < nums.size(); ++j) {
            v.push_back(nums[j]);
            solve(j + 1, nums, v);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        solve(0, nums, v);
        return ans;
    }
};