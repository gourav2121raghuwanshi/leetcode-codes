class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans = 0;
        map<int, int> mp;
        for (auto& i : meetings) {
            mp[i[0]] += 1;
            mp[i[1]] -= 1;
        }
        long long csum = 0;
        auto it = mp.begin();
        int prev = 0;
        csum = 0;
        while (it != mp.end()) {
            if (csum == 0) {
                if (it->first != prev)
                    ans += (it->first - prev - 1);
            }
            csum += it->second;
            prev = it->first;
            ++it;
        }
        
        if (days != prev)
            ans += days - prev;
        return ans;
    }
};