class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0;
        int ans = 0;
        int cost = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            cost +=  abs(s[i] - t[i]);
            while (maxCost< cost) {
                   cost -= abs(s[l] - t[l]);
                    ++l;
            }
              ans = max(ans, i - l + 1);
            
        }
        return ans;
    }
};