class Solution {
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;  // Divide before multiplication to avoid overflow.
    }
public:
    int maxLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            long long gc = 0;
            long long prod = 1;
            long long lc = nums[i];
            for (int j = i; j < n; ++j) {
                gc = gcd(nums[j], gc);
                lc = lcm(lc, nums[j]);
                
                // Check for overflow in prod before multiplying.
                if (prod > LLONG_MAX / nums[j]) break;
                prod *= nums[j];
                
                if (prod == gc * lc) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
