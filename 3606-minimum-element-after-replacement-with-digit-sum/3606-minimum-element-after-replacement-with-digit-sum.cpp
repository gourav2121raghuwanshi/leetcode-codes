class Solution {
public:
    int minElement(vector<int>& nums) {
        int t = 1e9;
        for (auto& i : nums) {
            int s = i;
            int ans = 0;
            while (s) {
                ans += s % 10;
                s /= 10;
            }
            t = min(ans, t);
        }
        return t;
    }
};