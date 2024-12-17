class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xo = 0;
        for (auto& i : nums)
            xo ^= i;
        long long c = 0;
        // cout << xo;
        while (xo) {
            if (xo&1)
                break;
            ++c;
            xo = xo >> 1;
        }
        // cout<<c;
        int a = 0, b = 0;
        for (const auto& i : nums) {
            if (i & (1 << c))
                a ^= i;
            else
                b ^= i;
        }

        return {a, b};
    }
};