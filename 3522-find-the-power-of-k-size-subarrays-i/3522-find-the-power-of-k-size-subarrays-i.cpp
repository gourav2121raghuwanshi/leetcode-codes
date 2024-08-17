class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        set<int> mark;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1)
                mark.insert(i);
        }
        int n = nums.size();

        vector<int> ans;
        for (int i = 0; i <= n - k; i++) {
            int nrs = i;
            if (mark.upper_bound(nrs) != mark.end()) {
                auto it = mark.upper_bound(nrs);
                if (*it > k + i - 1) {
                    ans.push_back(nums[i + k - 1]);
                } else {
                    ans.push_back(-1);
                }
            } else {
                ans.push_back(nums[i + k - 1]);
            }
        }

        return ans;
    }
};
