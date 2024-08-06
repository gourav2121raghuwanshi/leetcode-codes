class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (auto& i : word) {
            ++freq[i - 'a'];
        }
        sort(freq.rbegin(), freq.rend());
        int c = 1;
        int j = 0;
        int ans = 0;
        int time = 4;
        while (time--) {
            for (int i = 0; i < 8 && i + j < 26; ++i) {
                if (freq[j + i] == 0)
                    break;
                ans += c * freq[j + i];
            }
            ++c;
            j += 8;
        }
        return ans;
    }
};