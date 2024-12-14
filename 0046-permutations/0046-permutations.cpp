class Solution {
    vector<vector<int>> ans;
    void solve(int i, vector<int>& nums) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();++j){
            swap(nums[i],nums[j]);
            solve(i+1,nums);
            swap(nums[i],nums[j]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        // vector<int> v;
        solve(0, nums);
        return ans;
    }
};