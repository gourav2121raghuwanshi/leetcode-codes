class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int s = 0;
        int e = n - 1;
        while (s < e) {
            if (height[s] <= height[e]) {
                ans = max(ans, (e - s) * height[s]);
                ++s;
            } else {
                ans = max(ans, (e - s) * height[e]);
                --e;
            }
        }

        return ans;
    }
};