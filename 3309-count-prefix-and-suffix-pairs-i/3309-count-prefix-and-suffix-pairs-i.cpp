class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // Check if words[j] is a prefix of words[i]
                if (words[i].substr(0, words[j].size()) == words[j] &&
                    words[i].substr(words[i].size() - words[j].size()) == words[j]) {
                    ++ans;
                }
            }
        }
        
        return ans;
    }
};
