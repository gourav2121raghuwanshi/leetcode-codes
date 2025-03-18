class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int setBits = 0, s = 0, ans = 0;

        for (int e = 0; e < nums.size(); ++e) {
            while ((setBits & nums[e]) !=
                   0) { // Check if `nums[e]` shares bits with `setBits`
                setBits ^= nums[s++]; // Remove `nums[s]` from setBits using XOR
            }
            setBits |= nums[e]; // Add `nums[e]` to `setBits`
            ans = max(ans, e - s + 1);
        }
        return ans;
    }
};