class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = words.size();
        
        // Precompute cumulative counts in a vector
        vector<int> valid(n + 1, 0); // Cumulative count array with an extra 0 at the start
        for (int i = 0; i < n; ++i) {
            valid[i + 1] = valid[i] + (vowels.count(words[i][0]) && vowels.count(words[i].back()));
        }
        
        // Process queries
        vector<int> ans;
        for (auto& query : queries) {
            int start = query[0];
            int end = query[1];
            ans.push_back(valid[end + 1] - valid[start]);
        }
        return ans;
    }
};
