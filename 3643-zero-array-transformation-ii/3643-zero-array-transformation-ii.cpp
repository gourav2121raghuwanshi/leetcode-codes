class Solution {
    bool valid(vector<int>& nums, vector<vector<int>>& queries, int mid) {
        vector<int> diff(nums.size() + 1, 0);
        for (int j=0;j<mid;j++) {
            auto i=queries[j];
            diff[i[0]] += i[2];
            diff[i[1] + 1] -= i[2];
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += diff[i];
            if (sum < nums[i])
                return false;
        }
        return 1;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 1e9;
        int l = 0;
        int r = queries.size();

        while (l <= r) {
            int mid = (l + r) / 2;
            if (valid(nums, queries, mid)) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }

        return ans == 1e9 ? -1 : ans;
    }
};