class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int even_sum_c = 1;
        int odd_sum_c = 0;
        const int mod = 1e9 + 7;
        int ans = 0;
        int s = 0;
        for (auto& i : arr) {
            s += i;
            if (s & 1) {
                ans = (ans + even_sum_c) % mod;
                ++odd_sum_c;
            } else {
                ans = (ans + odd_sum_c) % mod;
                ++even_sum_c;
            }
        }

        return ans;
    }
};