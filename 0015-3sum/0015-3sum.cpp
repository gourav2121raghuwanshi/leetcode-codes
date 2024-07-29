class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // set<vector<int>> st;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int s = nums[l] + nums[r] + nums[i];
                if (s == 0) {
                    ans.push_back({nums[l], nums[i], nums[r]});
                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    while (l < r && nums[r] == nums[r - 1])
                        r--;

                    ++l, --r;
                } else if (s > 0)
                    --r;
                else
                    ++l;
            }
        }

        return ans;
    }
};