class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> precomputePair;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; j++) {
                precomputePair.insert(nums[i] ^ nums[j]);
            }
        }
        unordered_set<int> ans;
        for (auto& i : precomputePair) {
            for (auto& j : nums) {
                ans.insert(i ^ j);
            }
        }
        return ans.size();
    }
};