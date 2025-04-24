class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto& i : nums) {
            ++mp[i];
        }
        int req = mp.size();
        int c = 0;
        mp.clear();
        int l = 0;
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {

            unordered_set<int> st;
            for (int j = i; j < n; ++j) {
                st.insert(nums[j]);
                if (st.size() == req)
                    ++ans;
            }
        }
        return ans;
    }
};