class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> maxReq(26, 0);
        for (auto& i : words2) {
            vector<int> v(26, 0);
            for (auto& j : i) {
                ++v[j - 'a'];
            }
            for (int j = 0; j < 26; ++j) {
                maxReq[j] = max(maxReq[j], v[j]);
            }
        }
        int n = words1.size();
        for (int kk = 0; kk < n; ++kk) {
            string i = words1[kk];
            bool f = true;
            vector<int> v(26, 0);
            for (auto& j : i) {
                ++v[j - 'a'];
            }

            for (int j = 0; j < 26; ++j) {
                if (maxReq[j] > v[j]) {
                    f = false;
                    break;
                }
            }

            if (f)
                ans.push_back(i);
        }
        return ans;
    }
};