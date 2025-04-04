class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int l = 0;
        char ch;
        int maxi = 0;
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++freq[s[i] - 'A'];
            if (freq[s[i] - 'A'] > maxi) {
                maxi = freq[s[i] - 'A'];
                ch = s[i];
            }
            int len = i - l + 1;
            while (len - maxi > k) {
                --freq[s[l] - 'A'];
                ++l;
                len = i - l + 1;
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};