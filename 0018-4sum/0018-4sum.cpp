class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i <= n - 4; ++i) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j <= n - 3; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int k = j + 1;
                int l = n - 1;
                long long req2 =(long long) t - (long long)(nums[i] + nums[j]);
                while (k < l) {
                    long long m = (nums[k] + nums[l]);
                    if (m == req2) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k < l && nums[k] == nums[k + 1])
                            ++k;
                        while (k < l && nums[l] == nums[l - 1])
                            --l;
                        --l, ++k;
                    } else if (m > req2)
                        --l;
                    else
                        ++k;
                }
            }
        }
        return ans;
    }
};