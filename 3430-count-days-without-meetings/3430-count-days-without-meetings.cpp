class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans = 0;
        vector<pair<int, int>> v;
        for (auto& i : meetings) {
            v.push_back({i[0], 1});
            v.push_back({i[1], -1});
        }
        sort(v.begin(), v.end());
        long long csum = 0;
        int prev = 0;
        csum = 0;
        for (auto& it : v) {
            if (csum == 0) {
                if (it.first != prev)
                    ans += (it.first - prev - 1);
            }
            csum += it.second;
            prev = it.first;
        }
        if (days != prev)
            ans += days - prev;
        return ans;
    }
};