class Solution {
    // video : https://www.youtube.com/watch?v=45TkgKy0GS0
public:
    int minimumDifference(vector<int>& nums) {
        long long ts = accumulate(nums.begin(), nums.end(), 0LL);

        int N = nums.size();

        int n = N / 2;
        vector<vector<long long>> left(n + 1);
        vector<vector<long long>> right(n + 1);

        for (int i = 0; i < (1 << n); ++i) { // i => mask
            long long sleft = 0;
            long long sright = 0;
            int size = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    sleft += nums[j];
                    sright += nums[j + n];
                    ++size;
                }
            }
            left[size].push_back(sleft);
            right[size].push_back(sright);
        }

        for (auto& i : right)
            sort(i.begin(), i.end());

        long long ans = LLONG_MAX;

        ans = min(ans, abs(ts - 2 * left[n][0]));  // all n ele from left
        ans = min(ans, abs(ts - 2 * right[n][0])); // all n ele from right

        // left right (taking elements)
        // 1     n-1
        // 2     n-2
        // .       .
        // n-1    1
        for (int size = 1; size <= n - 1; ++size) {
            for (auto& a : left[size]) {
                int b = (ts - 2 * a) / 2;  // target we are looking for so to get as close to ts/2 as possible
                auto& v = right[n - size];   // take n-size elements from right
                auto itr = lower_bound(v.begin(), v.end(), b);

                // *itr => value at that index
                if (itr != v.end()) {
                    ans = min(ans, abs(ts - 2 * (a + *itr)));
                }                                   
                if (itr != v.begin()) {
                    --itr;
                    ans = min(ans, abs(ts - 2 * (a + *itr)));
                }
            }
        }
        return ans;
    }
};