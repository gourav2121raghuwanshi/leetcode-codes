class Solution {
public:
    int beautySum(std::string s) {
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            std::vector<int> freq(26, 0);
            for (int j = i; j < n; ++j) {
                int maxi = 0;
                int mini = INT_MAX;
                ++freq[s[j] - 'a'];
                for (int i = 0; i < 26; ++i) {
                    if(freq[i]==0) continue;
                    maxi = std::max(maxi, freq[i]);
                    mini = std::min(mini, freq[i]);
                }
                // cout << maxi << " " << mini << endl;
                if (mini != INT_MAX && maxi != 0) {
                    ans += maxi - mini;
                }
            }
        }

        return ans;
    }
};
