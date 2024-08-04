class Solution {
    const int mod = 1e9 + 7;

public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sub;
        for (int i = 0; i < n; ++i) {
            int s = 0;
            for (int j = i; j < n; ++j) {
                s = (s + nums[j]) % mod;
                sub.push_back(s);
            }
        }
        int ans = 0;
        sort(sub.begin(), sub.end());
        for (int i = left - 1; i < right; ++i) {
            ans = (ans + sub[i]) % mod;
        }
        return ans;
    }
};