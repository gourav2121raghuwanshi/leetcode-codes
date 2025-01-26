class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int ts = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        // if (ts % 2 == 0)
        //     ++ans;
        int ls=0;
        for (int i = 0; i < nums.size()-1; ++i) {
            ls += nums[i];
            int rs = ts - ls;
            if (abs(ls - rs) % 2 == 0)
                ++ans;
        }
        return ans;
    }
};