class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < s.size(); ++i) {
            mp[s[i]].push_back(i);
        }
        int ans = 0;
        for (auto& i : words) {
            if (mp[i[0]].empty())
                continue;
            string curr = i;
            int idx = mp[curr[0]][0];
            if (curr.size() == 1) {
                ++ans;
                continue;
            }
            for (int j = 1; j < curr.size(); ++j) {

                if (mp[curr[j]].empty())
                    break;
                auto next =
                    upper_bound(mp[curr[j]].begin(), mp[curr[j]].end(), idx);
                if (next == mp[curr[j]].end())
                    break;
                idx = *next;
                if (j == curr.size() - 1)
                    ++ans;
            }
        }
        return ans;
    }
};