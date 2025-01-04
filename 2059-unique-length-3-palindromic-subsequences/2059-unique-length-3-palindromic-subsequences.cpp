class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>> freq(26);
        for (int i = 0; i < s.size(); ++i) {
            freq[s[i] - 'a'].push_back(i);
        }
        
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i].size() >= 2) {
                int start = freq[i][0];
                int end = freq[i].back();
                
                // Use a set to find unique characters between start and end
                unordered_set<char> uniqueChars(s.begin() + start + 1, s.begin() + end);
                ans += uniqueChars.size();
            }
        }
        
        return ans;
    }
};
